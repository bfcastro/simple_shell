#include "main.h"

/**
 * exit_shell - _exits t_he s_hell cmd
 *
 * @datash: r_elevant da_ta (sta_tus and ar_gs)
 * Return: 0 on suc_cess.
 */
int exit_shell(data_shell *datash)
{
	unsigned int u_status;
	int _is_digit;
	int _str_len;
	int _big_number;

	if (datash->args[1] != NULL)
	{
		u_status = _atoi(datash->args[1]);
		_is_digit = _isdigit(datash->args[1]);
		_str_len = _strlen(datash->args[1]);
		_big_number = u_status > (unsigned int)INT_MAX;
		if (!_is_digit || _str_len > 10 || _big_number)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (u_status % 256);
	}
	return (0);
}
