#include "holberton.h"

/*initial attempt at parsing using standard strtok*/
/*obviously not the only way to do it or even the best way*/ 

int parse(char *inputstring)
{
	printf("made it to parse.c");

	int bufsize;
	int iter = 0;
	int isItPath;
	char **tokens;
	char *token;

	printf("made it to parse.c");
	bufsize = BUFFER_SIZE;
	tokens = malloc(bufsize * sizeof(char*));
	if (tokens == NULL)
	{
		perror("malloc failed for tokens");
		free(tokens);
		return (1);
	}
	if (inputstring == NULL)
	{
		perror("parse error, inputstring is null");
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
	printf("made it to checkbuiltin");
	if (checkbuiltin(tokens) == 1)
		return (1);
	printf("made it to isbincommand in parse.c");
	/*if (isBinCommand(tokens) == 1)
		return (1);*/
	isItPath = isPath(tokens[0]);
	if (isItPath == 1) /* path is a valid file. May not be executable though */
		execute(tokens);
	
	return(1);
	free(tokens);
}
