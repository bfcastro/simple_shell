#include "main.h"

/**
 * get_builtin - _pair the_ b_uiltin to _args
 * @cmd: _comma_nd _argument
 * Return: _function _ptr _of the _builtin _cmd
 */
int (*get_builtin(char *cmd))(data_shell *)
{
	builtin_t builtin[] = {
		{ "env", _env },
		{ "exit", exit_shell },
		{ "setenv", _setenv },
		{ "unsetenv", _unsetenv },
		{ "cd", cd_shell },
		{ "help", get_help },
		{ NULL, NULL }
	};
	int x;

	for (x = 0; builtin[x].name; x++)
	{
		if (_strcmp(builtin[x].name, cmd) == 0)
			break;
	}

	return (builtin[x].f);
}
