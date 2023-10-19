#include "main.h"

/**
 * check_env - _checks if i_nput var is _environment var
 *
 * @h: _head of _linked list
 * @in: _string _input
 * @data: _data structure
 * Return: _void
 */
void check_env(r_var **h, char *in, data_shell *data)
{
	int row, ch_r, y, l_val;
	char **_envr;

	_envr = data->_environ;
	for (row = 0; _envr[row]; row++)
	{
		for (y = 1, ch_r = 0; _envr[row][ch_r]; ch_r++)
		{
			if (_envr[row][ch_r] == '=')
			{
				l_val = _strlen(_envr[row] + ch_r + 1);
				add_rvar_node(h, y, _envr[row] + ch_r + 1, l_val);
				return;
			}

			if (in[y] == _envr[row][ch_r])
				y++;
			else
				break;
		}
	}

	for (y = 0; in[y]; y++)
	{
		if (in[y] == ' ' || in[y] == '\t' || in[y] == ';' || in[y] == '\n')
			break;
	}

	add_rvar_node(h, y, NULL, 0);
}

/**
 * check_vars - check for variables is $$ or $?
 *
 * @h: _head of _the _linked list
 * @in: in_put str__ing
 * @st: __last __status Shell
 * @data: d_ata __structure
 * Return: __void
 */
int check_vars(r_var **h, char *in, char *st, data_shell *data)
{
	int x, l_st, l_pd;

	l_st = _strlen(st);
	l_pd = _strlen(data->pid);

	for (x = 0; in[x]; x++)
	{
		if (in[x] == '$')
		{
			if (in[x + 1] == '?')
				add_rvar_node(h, 2, st, l_st), x++;
			else if (in[x + 1] == '$')
				add_rvar_node(h, 2, data->pid, l_pd), x++;
			else if (in[x + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[x + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[x + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[x + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[x + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + x, data);
		}
	}

	return (x);
}

/**
 * replaced_input - __replaces __str into vars
 *
 * @head: __head of the __linked list
 * @input: in_put str
 * @new_input: _new in_put str (replaced)
 * @nlen: __new leng_th
 * Return: __replaced str
 */
char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *indx;
	int x, y, z;

	indx = *head;
	for (y = x = 0; x < nlen; x++)
	{
		if (input[y] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[x] = input[y];
				y++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (z = 0; z < indx->len_var; z++)
					y++;
				x--;
			}
			else
			{
				for (z = 0; z < indx->len_val; z++)
				{
					new_input[x] = indx->val[z];
					x++;
				}
				y += (indx->len_var);
				x--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[x] = input[y];
			y++;
		}
	}

	return (new_input);
}

/**
 * rep_var - __calls _functions to repla_ce st_r in_to var_-iables
 *
 * @input: in___put s_tr
 * @datash: da_-ta stru__cture
 * Return: repl___aced s__tr
 */
char *rep_var(char *input, data_shell *datash)
{
	r_var *head, *indx;
	char *status, *new_input;
	int o_len, n_len;

	status = aux_itoa(datash->status);
	head = NULL;

	o_len = check_vars(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	n_len = 0;

	while (indx != NULL)
	{
		n_len += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	n_len += o_len;

	new_input = malloc(sizeof(char) * (n_len + 1));
	new_input[n_len] = '\0';

	new_input = replaced_input(&head, input, new_input, n_len);

	free(input);
	free(status);
	free_rvar_list(&head);

	return (new_input);
}
