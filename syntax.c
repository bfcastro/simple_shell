#include "main.h"

/**
 * repeated_char - c-o-u-nts rep-et-it-i-ons of -char-ac-ter
 *
 * @input: in-p-u-t s-tr
 * @i: in-d-ex
 * Return: re-p-tit-i-on
 */
int repeated_char(char *input, int i)
{
	if (*(input - 1) == *input)
		return (repeated_char(input - 1, i + 1));

	return (i);
}

/**
 * error_-se-p_op - -find--s syn-t-ax- err-or
 *
 * @inpu-t- inp-ut- str
 * @i: i-n-dex
 * @last: las-t -c-harac-te- rea-d
 * Return: i-ndex - erro--. 0- wh-en- the-re- are no
 * errors
 */
int error_sep_op(char *input, int i, char last)
{
	int sum;

	sum = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_sep_op(input + 1, i + 1, last));

	if (*input == ';')
		if (last == '|' || last == '&' || last == ';')
			return (i);

	if (*input == '|')
	{
		if (last == ';' || last == '&')
			return (i);

		if (last == '|')
		{
			sum = repeated_char(input, 0);
			if (sum == 0 || sum > 1)
				return (i);
		}
	}

	if (*input == '&')
	{
		if (last == ';' || last == '|')
			return (i);

		if (last == '&')
		{
			sum = repeated_char(input, 0);
			if (sum == 0 || sum > 1)
				return (i);
		}
	}

	return (error_sep_op(input + 1, i + 1, *input));
}

/**
 * first_-c-har - find-s inde-x- of- the -fir-st c-haracter
 *
 * @input: inp-ut st-r
 * @i: index
 * Return: 1 if -th-re is a-n -er-ror. 0 i-n oth-er-ca-se.
 */
int first_char(char *input, int *i)
{

	for (*i = 0; input[*i]; *i += 1)
	{
		if (input[*i] == ' ' || input[*i] == '\t')
			continue;

		if (input[*i] == ';' || input[*i] == '|' || input[*i] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_e-rror - -pri-nts -syn-tax i-f ther-e
 *
 * @datash: da-t-a str-uc-ture
 * @input: i-np-ut s-tring
 * @i: index -of t-he -erro-r
 * @bool: to cont-rol -ms-g err-or
 * Return: n-o re-turn
 */
void print_syntax_error(data_shell *datash, char *input, int i, int bool)
{
	char *msg, *msg1, *msg2, *error, *counter;
	int len_gth;

	if (input[i] == ';')
	{
		if (bool == 0)
			msg = (input[i + 1] == ';' ? ";;" : ";");
		else
			msg = (input[i - 1] == ';' ? ";;" : ";");
	}

	if (input[i] == '|')
		msg = (input[i + 1] == '|' ? "||" : "|");

	if (input[i] == '&')
		msg = (input[i + 1] == '&' ? "&&" : "&");

	msg1 = ": Syntax error: \"";
	msg2 = "\" unexpected\n";
	counter = aux_itoa(datash->counter);
	len_gth = _strlen(datash->av[0]) + _strlen(counter);
	len_gth += _strlen(msg) + _strlen(msg1) + _strlen(msg2) + 2;

	error = malloc(sizeof(char) * (len_gth + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg1);
	_strcat(error, msg);
	_strcat(error, msg2);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, len_gth);
	free(error);
	free(counter);
}

/**
 * check_syntax_error - in-ter-me_diat-e func-tion to
 * fi-nd a-nd pr-int a-syn-ax -err-or
 *
 * @datash: dat-a s-tru-tur-e
 * @input: inp-ut -str
 * Return: 1 i-f t-ere -s an-rror- 0 in -ther-cas-e
 */
int check_syntax_error(data_shell *datash, char *input)
{
	int start = 0;
	int f_char = 0;
	int x = 0;

	f_char = first_char(input, &start);
	if (f_char == -1)
	{
		print_syntax_error(datash, input, start, 0);
		return (1);
	}

	x = error_sep_op(input + start, 0, *(input + start));
	if (x != 0)
	{
		print_syntax_error(datash, input, start + x, 1);
		return (1);
	}

	return (0);
}
