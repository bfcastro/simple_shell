#include "main.h"

/**
 * copy_info - _copies _infomation to _create
 * a new _environment or _alias
 * @name: _name (environment or alias)
 * @value: _value (environment or _alias)
 *
 * Return: _new environment or _alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 *
 * @name: _environment _variable name
 * @value: _environment _variable _value
 * @datash: _data _structure (environment)
 * Return: _void
 */
void set_env(char *name, char *value, data_shell *datash)
{
	int x;
	char *var_env, *name_env;

	for (x = 0; datash->_environ[x]; x++)
	{
		var_env = _strdup(datash->_environ[x]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(datash->_environ[x]);
			datash->_environ[x] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	datash->_environ = _reallocdp(datash->_environ, x, sizeof(char *) * (x + 2));
	datash->_environ[x] = copy_info(name, value);
	datash->_environ[x + 1] = NULL;
}

/**
 * _setenv - _compares _env var names
 * with the _name passed.
 * @datash: _relevant _data (environment name and environment value)
 *
 * Return: 1 on _success.
 */
int _setenv(data_shell *datash)
{

	if (datash->args[1] == NULL || datash->args[2] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}

	set_env(datash->args[1], datash->args[2], datash);

	return (1);
}

/**
 * _unsetenv -  _environment _variable _delete
 *
 * @datash: _relevant _data (environment name)
 *
 * Return: 1 on _success.
 */
int _unsetenv(data_shell *datash)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int x, y, z;

	if (datash->args[1] == NULL)
	{
		get_error(datash, -1);
		return (1);
	}
	z = -1;
	for (x = 0; datash->_environ[x]; x++)
	{
		var_env = _strdup(datash->_environ[x]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, datash->args[1]) == 0)
		{
			z = x;
		}
		free(var_env);
	}
	if (z == -1)
	{
		get_error(datash, -1);
		return (1);
	}
	realloc_environ = malloc(sizeof(char *) * (x));
	for (x = y = 0; datash->_environ[x]; x++)
	{
		if (x != z)
		{
			realloc_environ[y] = datash->_environ[x];
			y++;
		}
	}
	realloc_environ[y] = NULL;
	free(datash->_environ[z]);
	free(datash->_environ);
	datash->_environ = realloc_environ;
	return (1);
}
