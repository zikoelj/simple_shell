#include "shell.h"

/**
 * hundle_ctrl - Function that hundles Ctrl-C signal
 * @sgnl: Argument to the singal function
 * Return : Void
*/

void hundle_ctrl(int sgnl)
{
	(void)sgnl;
	write(1, "\n$ ", 4);
}
