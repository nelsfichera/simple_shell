#include "holberton.h"

char *_strcat(char *dest, char *src)
{
	int x, n;
	int boolean = 1;

	for (x = 0; boolean == 1; x++)
	{
		if (*(dest + x) == '\0')
		{
			for (n = 0; *(src + n) != '\0'; x++, n++)
				*(dest + x) = '\0';
			boolean = 0;
		}
	}
	return (dest);
}
