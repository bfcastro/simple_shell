#include "main.h"

/**
 * cmp_env_name - _compares _environment variables _names
 * when the _name are input.
 * @nenv:  _environment name _variable
 * @name: _name input
 *
 * Return: 0 for _equal. none 0 if _different.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int x;

	for (x = 0; nenv[x] != '='; x++)
	{
		if (nenv[x] != name[x])
		{
			return (0);
		}
	}

	return (x + 1);
}

/**
 * _getenv - _acquire e_nvironment v_ariable
 * @name: _environment _variable name
 * @_environ: _environment v_ariable
 *
 * Return: e_nvironment _variable _value if found.
 * else _returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int x, moving;

	/* Initialize ptr_env value */
	ptr_env = NULL;
	moving = 0;
	/* Compares environment variables */
	/* environment is declared in the header file */
	for (x = 0; _environ[x]; x++)
	{
		/* when environments are equal */
		moving = cmp_env_name(_environ[x], name);
		if (moving)
		{
			ptr_env = _environ[x];
			break;
		}
	}

	return (ptr_env + moving);
}

/**
 * _env - _output _evironment _variables
 *
 * @datash: _relevant _data.
 * Return: 1 on _success.
 */
int _env(data_shell *datash)
{
	int x, y;

	for (x = 0; datash->_environ[x]; x++)
	{

		for (y = 0; datash->_environ[x][y]; y++)
			;

		write(STDOUT_FILENO, datash->_environ[x], y);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
