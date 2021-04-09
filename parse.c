#include "holberton.h"

/*initial attempt at parsing using standard strtok*/
/*obviously not the only way to do it or even the best way*/ 

int parse(char *input)
{
	int bufsize = BUFFER_SIZE;
	int iter = 0;
	int isItPath;
	char **tokens = malloc(bufsize * sizeof(char));
	char *token;

	printf("made it to parse.c");
	if (tokens == NULL)
	{
		perror("malloc failed for tokens");
		free(tokens);
		return (1);
	}
	if (input == NULL)
	{
		perror("parse error, input is null");
		return (1);
	}
	/* replace with _strtok later when code start working */
	token = strtok(input, DELIM);
	while (token != NULL)
	{
		tokens[iter] = token;
		iter++;
		token = strtok(NULL, DELIM);
	}
	tokens[iter] = NULL;
	printf("made it to checkbuiltin");
	if (checkbuiltin(tokens) == 1)
		return (1);
	printf("made it to isbincommand in parse.c");
	if (isBinCommand(tokens) == 1)
		return (1);
	isItPath = isPath(tokens[0]);
	if (isItPath == 1) /* path is a valid file. May not be executable though */
		execute(tokens);
	
	return(1);
	free(tokens);
}
