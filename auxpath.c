#include "holberton.h"

/**
* getPath - return the env path var
* Return: tokenized path
*/
char **getPath(void)
{
	char **output;
	char *token;
	char *envstr;
	unsigned int x, pathlen;

	envstr = _getenv("PATH");

	if (envstr == NULL)
		return (NULL);

	pathlen = countDelims(envstr);
	output = _calloc(pathlen + 1, sizeof(char*));

	if (output == NULL)
	{
		perror("Error");
		return (NULL);
	}

	token = strtok(envstr, ":");
	*output = token; 

	for (x = 1; x < pathlen; x++)
	{
		token = strtok(NULL, ":");
		*(output + x) = token;
	}
	*(output + x) = NULL;
	return (output);
}

/**
* countDelims - counts delimiters in the path for dir count
* @str: the full path str
* Return: num of delims (and therefore, num of dirs)
*/
unsigned int countDelims(char *str)
{
	int x = 0;
	char *iter = str;

	while (*iter != '\0')
	{
		if (*iter == ':')
			x++;
		iter++;
	}
	return (x + 1);
}
