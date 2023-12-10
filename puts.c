#include "shell.h"

/**
  * _puts - prints a string
  * @s: the string
  *
  * Return: void
  */
void _puts(char *s)
{
	int k = 0;

	while (*(s + k) != 0)
	{
		_putchar(*(s + k));
		k++;
	}
}
