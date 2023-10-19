#include "main.h"

/**
 * read_line - r-eads t-he inp-ut s-tr.
 *
 * @i_eof: re-turn val-e of- get-_li-ne f-un-ct-ion
 * Return: inp-ut st-r
 */
char *read_line(int *i_eof)
{
	char *in_put = NULL;
	size_t buffsize = 0;

	*i_eof = getline(&in_put, &buffsize, stdin);

	return (in_put);
}
