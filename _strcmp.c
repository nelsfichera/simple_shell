#include "holberton.h"
/**
* _strcmp - compares two strings
* @s1: the first string
* @s2: the second string
* Return: comparison of the strings on success, 0 on failure
*/
int _strcmp(char *s1, char *s2)
{
	int x;

	for (x = 0; *(s1 + x) != '\0'; x++)
	{
		if (*(s1 + x) != *(s2 + x))
			return (*(s1 + x) - *(s2 + x));
	}
	if (*(s2 + x) != '\0')
		return (*(s2 + x) * -1);
	return (0);
}

