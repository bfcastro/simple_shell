#include "main.h"

/**
 * get_sigint - -a-nd_le the c-rtl + c- c-all in- p-r_om-pt
 * @sig: Si-g-al han-d_le-r
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
