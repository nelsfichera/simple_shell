#include "holberton.h"

/*initial attempt at parsing using standard strtok*/
/*obviously not the only way to do it or even the best way*/ 

int parse(char *inputstring)
{
	int bufsize;
	int iter = 0;
	char **tokens;
	char *token;

	bufsize = BUFFER_SIZE;
	tokens = malloc(bufsize * sizeof(char*));
	if (tokens == NULL)
	{
		free(tokens);
		return (1);
	}
	if (inputstring == NULL)
	{
		return (1);
	}
	/* replace with _strtok later when code start working */
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
	if (isPath(tokens[0]) == 1) /* path is a valid file. May not be executable though */
		execute(tokens);
	return(1);
	free(tokens);
}
