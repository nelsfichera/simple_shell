#include "holberton.h"
/**
* NonActiveParse - parses the gotten line for commands
* @array: array of strings from nonactive mode
* Return: 1 on success
*/
int NonActiveParse(char **array)
{
	if (checkbuiltin(array) == 1)
		return (1);
	if (isBinCommand(array) == 1)
		return (1);
	if (isPath(array[0]) == 1)
		execute(array);
	return (1);
}
/**
* parse - parses the gotten line for commands
* @inputstring: the string from stdin
* Return: 1 on success
*/
int parse(char *inputstring)
{
	int bufsize;
	int iter = 0;
	char **tokens;
	char *token;

	bufsize = BUFFER_SIZE;
	tokens = malloc(bufsize * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		return (1);
	}
	if (inputstring == NULL)
	{
		return (1);
	}
	token = strtok(inputstring, DELIM);
	while (token != NULL)
	{
		tokens[iter] = token;
		iter++;
		token = strtok(NULL, DELIM);
	}
	tokens[iter] = NULL;
	if (checkbuiltin(tokens) == 1)
		return (1);
	if (isBinCommand(tokens) == 1)
		return (1);
	if (isPath(tokens[0]) == 1)
		execute(tokens);
	return (1);
	free(tokens);
}
