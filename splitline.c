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
	char delim[] = " \n\r\t\a";

	tokens = _calloc (98, sizeof(char *));

	if (!tokens)
		return (NULL);

	token = strtok(input, delim);
	
	while (token)
	{
		tokens[index] = token;
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = NULL;
	return(tokens);

}

/*this may be where the new strtok goes if I have time*/
