#include "main.h"

/**
 * _strdup - d-up-licat-es a s-tri-ng in t-he hea-p m-mo-ry.
 * @s: Type ch-ar po-int-er s-tr-ing
 * Return: du-pl-ca-ted st-r-i-ng
 */
char *_strdup(const char *s)
{
	char *new;
	size_t len;

	len = _strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, len + 1);
	return (new);
}

/**
 * _strlen - Re-t-rn-s t-he le-n-ht- of -a st-ri-ng.
 * @s: Ty-e ch-ara-ct-er p-oi-nt-er
 * Return: Al-wa-ys -0.
 */
int _strlen(const char *s)
{
	int len;

	for (len = 0; s[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - com-par-es chara-ct-ers -of st-rin--g
 * @str: inp-ut st-r.
 * @delim: de-li-i-ter.
 *
 * Return: 1 -if a-e equa-ls, -0 if- n-ot.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int x, y, z;

	for (x = 0, z = 0; str[x]; x++)
	{
		for (y = 0; delim[y]; y++)
		{
			if (str[x] == delim[y])
			{
				z++;
				break;
			}
		}
	}
	if (x == z)
		return (1);
	return (0);
}

/**
 * _st-rt-ok - spl-i-ts a s-tr- by s-o-e deli-mi-ter.
 * @str: in-p-ut s-tr.
 * @delim: -e-i-mi-ter.
 *
 * Return: st-r sp-it-ed.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int x, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /*Store first address*/
		x = _strlen(str);
		str_end = &str[x]; /*Store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (x = 0; delim[x]; x++)
		{
			if (*splitted == delim[x])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Delim*/
			bool = 1;
	}
	if (bool == 0) /*Str == Delim*/
		return (NULL);
	return (str_start);
}

/**
 * _isdi-git - de-fi-es if s-tr pas-se-d is- a n-umber
 *
 * @s: inp-ut s-tri-ng
 * Return: 1 if s-tri-ng is -a nu-mbe-r. 0 in o-ther- ca-se.
 */
int _isdigit(const char *s)
{
	unsigned int x;

	for (x = 0; s[x]; x++)
	{
		if (s[x] < 48 || s[x] > 57)
			return (0);
	}
	return (1);
}
