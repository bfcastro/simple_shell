#include "main.h"

/**
 * add_rvar_node - __inserts a __var at the end
 * of a r_var list.
 * @head: __head of the __linked list.
 * @lvar: __length of the var.
 * @val: __value of the var.
 * @lval: __length of the __value.
 * Return: a__ddress of the h__ead.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new, *_temp;

	new = malloc(sizeof(r_var));
	if (new == NULL)
		return (NULL);

	new->len_var = lvar;
	new->val = val;
	new->len_val = lval;

	new->next = NULL;
	_temp = *head;

	if (_temp == NULL)
	{
		*head = new;
	}
	else
	{
		while (_temp->next != NULL)
			_temp = _temp->next;
		_temp->next = new;
	}

	return (*head);
}

/**
 * free_rvar_list - f__rees r_var
 * @head: linked __list __head.
 * Return: __void.
 */
void free_rvar_list(r_var **head)
{
	r_var *temp;
	r_var *current;

	if (head != NULL)
	{
		current = *head;
		while ((temp = current) != NULL)
		{
			current = current->next;
			free(temp);
		}
		*head = NULL;
	}
}
