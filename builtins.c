#include "main.h"

/**
 * exec_line - _finds _builtins and _commands
 *
 * @datash: _relevant _data (args)
 * Return: 1 on _success.
 */
int exec_line(data_shell *datash)
{
	int (*builtin)(data_shell *datash);

	if (datash->args[0] == NULL)
		return (1);

	builtin = get_builtin(datash->args[0]);

	if (builtin != NULL)
		return (builtin(datash));

	return (cmd_exec(datash));
}
