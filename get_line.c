#include "main.h"

/**
 * bring_line - __assigns the __line variable 4 __get_line
 * @lineptr: __Buf that st__ore the in_put __string
 * @buffer: __string which __has been ca_lled to line
 * @n: s_ize of l_ine
 * @j: s_ize of _buf
 */
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{

	if (*lineptr == NULL)
	{
		if  (j > BUFSIZE)
			*n = j;

		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else if (*n < j)
	{
		if (j > BUFSIZE)
			*n = j;
		else
			*n = BUFSIZE;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}
/**
 * get_line - _read _string in_put
 * @lineptr: buf t_hat stores t_he in_put
 * @n: size _of line _pointer
 * @stream: s_tring to _read from
 * Return: _size of bytes
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int x;
	static ssize_t in_put;
	ssize_t retreaval;
	char *_buffer;
	char t = 'z';

	if (in_put == 0)
		fflush(stream);
	else
		return (-1);
	in_put = 0;

	_buffer = malloc(sizeof(char) * BUFSIZE);
	if (_buffer == 0)
		return (-1);
	while (t != '\n')
	{
		x = read(STDIN_FILENO, &t, 1);
		if (x == -1 || (x == 0 && in_put == 0))
		{
			free(_buffer);
			return (-1);
		}
		if (x == 0 && in_put != 0)
		{
			in_put++;
			break;
		}
		if (in_put >= BUFSIZE)
			_buffer = _realloc(_buffer, in_put, in_put + 1);
		_buffer[in_put] = t;
		in_put++;
	}
	_buffer[in_put] = '\0';
	bring_line(lineptr, n, _buffer, in_put);
	retreaval = in_put;
	if (x != 0)
		in_put = 0;
	return (retreaval);
}
