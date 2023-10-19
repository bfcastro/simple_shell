#include "main.h"

/**
 * error_env - _error _msg for _environment in _get_env.
 * @datash: _relevant _data(_counter, _arguments)
 * Return: _error _msg.
 */
char *error_env(data_shell *datash)
{
	int leng_th;
	char *error;
	char *ver_str;
	char *_msg;

	ver_str = aux_itoa(datash->counter);
	_msg = ": Unable to add/remove from environment\n";
	leng_th = _strlen(datash->av[0]) + _strlen(ver_str);
	leng_th += _strlen(datash->args[0]) + _strlen(_msg) + 4;
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
	_strcat(error, _msg);
	_strcat(error, "\0");
	free(ver_str);

	return (error);
}
/**
 * error_path_126 - _error _msg for & _failure _denied _permission.
 * @datash: _relevant _data (counter, _arguments).
 *
 * Return: The _error _str.
 */
char *error_path_126(data_shell *datash)
{
	int leng_th;
	char *ver_str;
	char *_error;

	ver_str = aux_itoa(datash->counter);
	leng_th = _strlen(datash->av[0]) + _strlen(ver_str);
	leng_th += _strlen(datash->args[0]) + 24;
	_error = malloc(sizeof(char) * (leng_th + 1));
	if (_error == 0)
	{
		free(_error);
		free(ver_str);
		return (NULL);
	}
	_strcpy(_error, datash->av[0]);
	_strcat(_error, ": ");
	_strcat(_error, ver_str);
	_strcat(_error, ": ");
	_strcat(_error, datash->args[0]);
	_strcat(_error, ": Permission denied\n");
	_strcat(_error, "\0");
	free(ver_str);
	return (_error);
}
