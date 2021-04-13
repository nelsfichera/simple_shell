#include "holberton.h"
/**
* _strlen - mimics standard strlen function and gets the length of a string
* @s: the chars to be counted
* Return: the number of chars in a str
*/
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
