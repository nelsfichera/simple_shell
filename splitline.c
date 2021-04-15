#include "holberton.h"
/**
* splitline - splits a line into tokens
* @input: the input line
* Return: address of substrings
*/
char **splitline(char *input)
{
	char *token, **tokens;
	int index = 0;
	const char delimtoken[] = {" \n\r\t\a"};

	tokens = _calloc(98, sizeof(char *));

	if (!tokens)
		return (NULL);

	token = _strtok(input, delimtoken);

	while (token)
	{
		tokens[index] = token;
		token = _strtok(NULL, delimtoken);
		index++;
	}
	tokens[index] = NULL;
	return (tokens);

}
/**
* _modstrtok - strtok but return pointer!
* @str: the string
* @delim: delimiters
* @save: pointer
* Return: tokenized string
*/
char *_modstrtok(char *str, const char *delim, char **save)
{
	char *end;

	if (str == NULL)
		str = *save;
	if (*str == '\0')
	{
		*save = str;
		return (NULL);
	}

	str += _strspn(str, delim);

	if (*str == '\0')
	{
		*save = str;
		return (NULL);
	}

	end = str + _strcspn(str, delim);

	if (*end == '\0')
	{
		*save = end;
		return (str);
	}

	*end = '\0';
	*save = end + 1;
	return (str);
}
/**
* _strtok - calls the other strtok
* @str: the string
* @delimeters: delimiters
* Return: result of other function
*/
char *_strtok(char *str, const char *delimeters)
{
	static char *originalstr;

	return (_modstrtok(str, delimeters, &originalstr));
}
