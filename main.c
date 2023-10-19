#include "main.h"

/**
 * free_data - frees __data structure
 *
 * @datash: data __structure
 * Return: +void
 */
void free_data(data_shell *datash)
{
	unsigned int x;

	for (x = 0; datash->_environ[x]; x++)
	{
		free(datash->_environ[x]);
	}

	free(datash->_environ);
	free(datash->pid);
}

/**
 * set_data - __data __structure __initialization
 *
 * @datash: __data __structure
 * @av: __argument __array
 * Return: __void
 */
void set_data(data_shell *datash, char **av)
{
	unsigned int x;

	datash->av = av;
	datash->input = NULL;
	datash->args = NULL;
	datash->status = 0;
	datash->counter = 1;

	for (x = 0; environ[x]; x++)
		;

	datash->_environ = malloc(sizeof(char *) * (x + 1));

	for (x = 0; environ[x]; x++)
	{
		datash->_environ[x] = _strdup(environ[x]);
	}

	datash->_environ[x] = NULL;
	datash->pid = aux_itoa(getpid());
}

/**
 * main - __Entry point
 *
 * @ac: a__rgument __counter
 * @av: __argument __array
 *
 * Return: 0 on __success.
 */
int main(int ac, char **av)
{
	data_shell datash;
	(void) ac;

	signal(SIGINT, get_sigint);
	set_data(&datash, av);
	shell_loop(&datash);
	free_data(&datash);
	if (datash.status < 0)
		return (255);
	return (datash.status);
}
