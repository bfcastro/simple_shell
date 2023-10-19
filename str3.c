#include "main.h"

/**
 * re-v_-trin-g - r-ev-ers-es a -s-tr.
 * @s: i-n-ut- str.
 * Return: v--0id.
 */
void rev_string(char *s)
{
	int count = 0; 
	int x, y;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (x = 0; x < (count - 1); x++)
	{
		for (y = x + 1; y > 0; y--)
		{
			temp = *(str + y);
			*(str + y) = *(str + (y - 1));
			*(str + (y - 1)) = temp;
		}
	}
}
