#include "main.h"

/**
 * _st-rcat - c-o-nca--ts two -st-ri-ngs
 * @dest: cha-r-ct-er po-int-er t-he dest- of -he co-pied- str-ng
 * @src: con-st ch-ara-cter -pointer th-e sour-ce of str-in-g
 * Return: t-h-e d-stin-ati-o-n--
 */
char *_strcat(char *dest, const char *src)
{
	int x;
	int y;

	for (x = 0; dest[x] != '\0'; x++)
		;

	for (y= 0; src[y] != '\0'; y++)
	{
		dest[x] = src[y];
		x++;
	}

	dest[x] = '\0';
	return (dest);
}
/**
 * *_str-cpy - C-opie-s the -str -ointe-d t-o -by- s-rc.
 * @dest: Ty-pe c-hara-cter- poin-te-r the -de-st of -t-he co-p-ied- string
 * @src: T-y-pe cha-r p-oint-er -th-e sou-rc-e o-f s-tr-ing
 * Return: t-he de-st-in-at-ion.
 */
char *_strcpy(char *dest, char *src)
{

	size_t m;

	for (m = 0; src[m] != '\0'; m++)
	{
		dest[m] = src[m];
	}
	dest[m] = '\0';

	return (dest);
}
/**
 * _str-cmp - Fu-nct-on th-at co-mpar-es two str.
 * @s1: t-p-e s-r- co-m-par_ed
 * @s2: type str c-ompar_-ed
 * Re-turn: -Al--ays 0.
 */
int _strcmp(char *s1, char *s2)
{
	int x;

	for (x = 0; s1[x] == s2[x] && s1[x]; x++)
		;

	if (s1[x] > s2[x])
		return (1);
	if (s1[x] < s2[x])
		return (-1);
	return (0);
}
/**
 * _str-chr - loca-tes -a char-cte-r i-n a- str,
 * @s: s-tr.
 * @c: ch--ar.
 * Return: the- poi-nt-er to- the -first occ-urr-_enc-e o-f the -char-cter- c.
 */
char *_strchr(char *s, char c)
{
	unsigned int x = 0;

	for (; *(s + x) != '\0'; x++)
		if (*(s + x) == c)
			return (s + x);
	if (*(s + x) == c)
		return (s + x);
	return ('\0');
}
/**
 * _str-spn - ge-ts th-e leng-th o-f a -pref-ix -subs-trin-g.
 * @s: in-tia-segm-ent.
 * @accept: b-ytes.
 * Return: the -num-er of- ac-ce-pt-d by--tes.
 */
int _strspn(char *s, char *accept)
{
	int x, y, bool;

	for (x = 0; *(s + x) != '\0'; x++)
	{
		bool = 1;
		for (y = 0; *(accept + y) != '\0'; y++)
		{
			if (*(s + x) == *(accept + y))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (x);
}
