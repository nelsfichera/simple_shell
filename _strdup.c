#include "holberton.h"
/**
* _strdup - returns pointer to duplicated string
* @str: the string to be copied
* Return: v0id
*/
char *_strdup(char *str)
{
	int x, n;
	char *dupe;

	if (!str)
		return (NULL);

	n = _strlen(str) + 1;

	dupe = _calloc(n, sizeof(char));
	if (!dupe)
		return (NULL);
	for (x = 0; x < n; x++)
		dupe[x] = str[x];
	return (dupe);
}

