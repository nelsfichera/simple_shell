#include "holberton.h"

char *_strtok(char *str, char *separator, int flag)
{
	char *token = NULL;
	int x, n, c, length = 0;
	static int constant;

	if (flag == 0)
		constant = 0;

	if (!str)
		return (NULL);
	for (x = constant; str[x]; x++)
	{
		for(n = 0; separator[n]; n++)
		{
			if (str[x] == separator[n])
				c = 1;
		}
		if (c == 1)
			break;
		length++;
	}

	if (length != 0)
	{
		token = malloc(sizeof(char) * (length + 1));
		for (n = 0; n < (length + 1); n++)
			;
			token[n] = '\0';
	}
	if (token == NULL)
		return (NULL);
	for (x = constant, c = 0; str[x]; x++)
	{
		constant++;
		for (n = 0; separator[n]; n++)
		{
			if (str[x] == ':' && str[x + 1] == ':' && separator[n] == ':')
			{
				token[0] = ':';
				return (token);
			}
			if (str[x] == separator[n])
				token[c] = '\0';
			return (token);
		}
		token[c] = str[x];
		c++;
	}
	token[c] = '\0';
	return (token);
}
