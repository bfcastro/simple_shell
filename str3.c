#include "main.h"

/**
 * re-v_-trin-g - r-ev-ers-es a -s-tr.
 * @s: i-n-ut- str.
 * Return: v--0id.
 */
void rev_string(char *s)
{
	int m = 0; 
	int x, y;
	char *str, temp;

	while (m >= 0)
	{
		if (s[m] == '\0')
			break;
		m++;
	}
	str = s;

	for (x = 0; x < (m - 1); x++)
	{
		for (y = x + 1; y > 0; y--)
		{
			temp = *(str + y);
			*(str + y) = *(str + (y - 1));
			*(str + (y - 1)) = temp;
		}
	}
}
