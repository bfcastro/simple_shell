#include "main.h"

/**
 * is_cdir - checks ":" _wether is _current d_irectory.
 * @path: t_ype ch_ar _ptr _char.
 * @i: _type i_nt _ptr _of _index.
 * _Return: 1 if the _path is _searchabl_in the _cd, else 0.
 */
int is_cdir(char *path, int *i)
{
	if (path[*i] == ':')
		return (1);

	while (path[*i] != ':' && path[*i])
	{
		*i += 1;
	}

	if (path[*i])
		*i += 1;

	return (0);
}

/**
 * _which - _finds _a _cmd
 *
 * @cmd: _name _of the _command
 * @_environ: _environment _variable
 * Return:  _command _location.
 */
char *_which(char *cmd, char **_environ)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cmd, x;
	struct stat st;

	path = _getenv("PATH", _environ);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cmd = _strlen(cmd);
		token_path = _strtok(ptr_path, ":");
		x = 0;
		while (token_path != NULL)
		{
			if (is_cdir(path, &x))
				if (stat(cmd, &st) == 0)
					return (cmd);
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + len_cmd + 2);
			_strcpy(dir, token_path);
			_strcat(dir, "/");
			_strcat(dir, cmd);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cmd, &st) == 0)
			return (cmd);
		return (NULL);
	}
	if (cmd[0] == '/')
		if (stat(cmd, &st) == 0)
			return (cmd);
	return (NULL);
}

/**
 * is_executable - _checks if _file is _executable
 *
 * @datash: _data _structure
 * Return: 0 if _executable, _else _other if _executable
 */
int is_executable(data_shell *datash)
{
	struct stat st;
	int x;
	char *in_put;

	in_put = datash->args[0];
	for (x = 0; in_put[x]; x++)
	{
		if (in_put[x] == '.')
		{
			if (in_put[x + 1] == '.')
				return (0);
			if (in_put[x + 1] == '/')
				continue;
			else
				break;
		}
		else if (in_put[x] == '/' && x != 0)
		{
			if (in_put[x + 1] == '.')
				continue;
			x++;
			break;
		}
		else
			break;
	}
	if (x == 0)
		return (0);

	if (stat(in_put + x, &st) == 0)
	{
		return (x);
	}
	get_error(datash, 127);
	return (-1);
}

/**
 * check_error_cmd - _checks for _user _access _permissions
 *
 * @dir: _dest_ination _direc_tory
 * @datash: _data _structure
 * Return: 1 _if there i_s an _error, 0 if__ not
 */
int check_error_cmd(char *dir, data_shell *datash)
{
	if (dir == NULL)
	{
		get_error(datash, 127);
		return (1);
	}

	if (_strcmp(datash->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(datash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			get_error(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cmd_exec - __command l_ines _-execution
 *
 * @datash: __relevant data (args and input)
 * Return: 1 on s__uccess.
 */
int cmd_exec(data_shell *datash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_executable(datash);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(datash->args[0], datash->_environ);
		if (check_error_cmd(dir, datash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(datash->args[0], datash->_environ);
		else
			dir = datash->args[0];
		execve(dir + exec, datash->args, datash->_environ);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	datash->status = state / 256;
	return (1);
}
