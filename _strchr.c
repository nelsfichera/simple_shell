#include "holberton.h"
/**
* _strchr - strchr but not
* @s: string
* @x: where the char
* Return: pointer on success, null on failure
*/

char *_strchr(const char *s, int x)
{
	const char *ptr;

	if (s == NULL)
		return (NULL);
	ptr = s;
	while (*ptr != '\0')
	{
		if (*ptr == x)
			return ((char *)ptr);
		ptr++;
	}
	return (NULL);
}
