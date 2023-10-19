#include "main.h"

/**
 * _memcpy - --copies info_rmation b--etween --void-- pointers.
 * @newptr: d--estination --pointer.
 * @ptr: --source --pointer.
 * @size: --size of t-he ne-w po-inter.
 *
 * Return: void.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int x;

	for (x = 0; x < size; x++)
		char_newptr[x] = char_ptr[x];
}

/**
 * _realloc - re-allocates a m-emory blo-ck.
 * @ptr: poin-ter to th-e mem_-ory p-revio-usly allo-cated.
 * @old_size: si-ze, in by-tes, of t-he allo-cated sp-ace of- ptr.
 * @new_size: ne-w siz-, in by-es, of t-he ne-w me-mo-ry bl-ock.
 *
 * Return: poi-ter.
 * if new_si-ze == old_si-ze, return-s poin-ter with-ut cha-nges.
 * if ma-lloc fai-ls, retu-rns N-ULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _real-locdp - real-locates a me-mory b-lock of a- double- poi-nter.
 * @ptr: do--ble po-inter to -the m-emory pr-eviously -allocated.
 * @old_size: si-e, in b-s, of t-he a-llocat-ed spa-ce o-f pt-r.
 * @new_size: ne-w si-, in byt-es, o-f the- new -memo-ry bl-ock.
 *
 * Return: pt-r.
 * if new_size == old--_size, returns pt-r wit-hout c-han-ges.
 * if malloc f-ils, retu-rns N-ULL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int x;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (x = 0; x < old_size; x++)
		newptr[x] = ptr[x];

	free(ptr);

	return (newptr);
}
