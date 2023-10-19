#include "shell.h"

/**
 * _erratoi - converts a strg to an integer
 * @s: the strg to be converted
 * Return: 0 if no numbs in strg, converted numb otherwise
 * -1 on error
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++; /*TODO: why does this make main returns 255? */
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (reult > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - print an error message
 * info: the parammeter and return info struct
 * @estr: strg contains specific error type
 * Return: 0 if no numbers in string, converted numn otherwise
 *   -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fnsme);
	_eputs(":");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(":");
	_eputs(info->argv[0]);
	_eputs(":");
	_eputs(estr);

