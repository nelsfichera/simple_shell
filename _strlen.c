#include "holberton.h"
/**
* _strlen - mimics standard strlen function and gets the length of a string
* @s: the chars to be counted
* Return: the number of chars in a str
*/
int _strlen(const char *s)
{
	int x = 0;

	while (s[x] != '\0')
	{
		x++;
	}
	return (x);
}
