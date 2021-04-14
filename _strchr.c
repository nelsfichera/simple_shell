#include "holberton.h"
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
