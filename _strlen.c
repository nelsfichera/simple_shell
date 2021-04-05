#include "holberton.h"

int _strlen(char *s)
{
	int x = 0;

	if (*s != '\0')
	{
		x = _strlen(s + 1);
		x = x + 1;
	}
	return (x);
}
