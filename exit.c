#include "main.h"

/**
 * exit_shell - _exits t_he s_hell cmd
 *
 * @datash: r_elevant da_ta (sta_tus and ar_gs)
 * Return: 0 on success.
 */
int exit_shell(data_shell *datash)
{
	unsigned int u_status;
	int is_digit;
	int str_len;
	int big_number;

	if (datash->args[1] != NULL)
	{
		u_status = _atoi(datash->args[1]);
		is_digit = _isdigit(datash->args[1]);
		str_len = _strlen(datash->args[1]);
		big_number = u_status > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_error(datash, 2);
			datash->status = 2;
			return (1);
		}
		datash->status = (u_status % 256);
	}
	return (0);
}
