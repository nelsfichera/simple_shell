#include "holberton.h"

char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; *(src + x) != '\0'; x++)
		*(dest + x) = *(src + x);
	*(dest + x) = '\0';
	return (dest);
}
