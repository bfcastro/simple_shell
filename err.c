#include "main.h"

/**
 * strcat_cd - _concatenates msg for c_hangedirectory e_rror _msg
 *
 * @datash:  _relevant _data (directory)
 * @msg: _output _msg _error
 * @error: _output msg
 * @ver_str: _counter _lines
 * Return: _error _msg
 */
char *strcat_cd(data_shell *datash, char *msg, char *error, char *ver_str)
{
	char *illegal_flag;

	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, msg);
	if (datash->args[1][0] == '-')
	{
		illegal_flag = malloc(3);
		illegal_flag[0] = '-';
		illegal_flag[1] = datash->args[1][1];
		illegal_flag[2] = '\0';
		_strcat(error, illegal_flag);
		free(illegal_flag);
	}
	else
	{
		_strcat(error, datash->args[1]);
	}

	_strcat(error, "\n");
	_strcat(error, "\0");
	return (error);
}

/**
 * error_get_cd - _error msg for cd _command in get_cd
 * @datash: _relevant d_ata (di_rectory)
 * Return: _Error _message
 */
char *error_get_cd(data_shell *datash)
{
	int leng_th, len_id;
	char *error, *ver_str, *msg;

	ver_str = aux_itoa(datash->counter);
	if (datash->args[1][0] == '-')
	{
		msg = ": Illegal option ";
		len_id = 2;
	}
	else
	{
		msg = ": can't cd to ";
		len_id = _strlen(datash->args[1]);
	}

	leng_th = _strlen(datash->av[0]) + _strlen(datash->args[0]);
	leng_th += _strlen(ver_str) + _strlen(msg) + len_id + 5;
	error = malloc(sizeof(char) * (leng_th + 1));

	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}

	error = strcat_cd(datash, msg, error, ver_str);

	free(ver_str);

	return (error);
}

/**
 * error_not_found - g_eneric _error msg for c_ommand not _found
 * @datash: _relevant _data (_counter, _arguments)
 * Return: _Error_msg
 */
char *error_not_found(data_shell *datash)
{
	int leng_th;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	leng_th = _strlen(datash->av[0]) + _strlen(ver_str);
	leng_th += _strlen(datash->args[0]) + 16;
	error = malloc(sizeof(char) * (leng_th + 1));
	if (error == 0)
	{
		free(error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": not found\n");
	_strcat(error, "\0");
	free(ver_str);
	return (error);
}

/**
 * error_exit_shell - _generic _error _msg for _exit in _get_exit
 * @datash: _relevant data (counter, arguments)
 *
 * Return: _Error msg
 */
char *error_exit_shell(data_shell *datash)
{
	int leng_th;
	char *error;
	char *ver_str;

	ver_str = aux_itoa(datash->counter);
	leng_th = _strlen(datash->av[0]) + _strlen(ver_str);
	leng_th += _strlen(datash->args[0]) + _strlen(datash->args[1]) + 23;
	error = malloc(sizeof(char) * (leng_th + 1));
	if (error == 0)
	{
		free(ver_str);
		return (NULL);
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, ver_str);
	_strcat(error, ": ");
	_strcat(error, datash->args[0]);
	_strcat(error, ": Illegal number: ");
	_strcat(error, datash->args[1]);
	_strcat(error, "\n\0");
	free(ver_str);

	return (error);
}
