#include "holberton.h"

/*initial attempt at parsing using standard strtok*/
/*obviously not the only way to do it or even the best way*/ 

char **parse(char *input, char *separator)
{
	char *parsed_line;
	int index = 0; 
	char **commands; 

	if (input == NULL)
		return (NULL);
	
	commands = malloc (buffer * sizeof(char*)); 
	/*buffer size  should probably be defined in a macro?*/ 
	
	if (commands == NULL)
	{
		perror("malloc failed");
		exit(1);
	}
	parsed_line = strtok(input, separator);

	while (parsed_line != NULL)
	{
		commands[index] = parsed_line;
		index++;
		parsed_line(strtok(NULL, separator);
	}
	commands[index] = NULL;
	return(commands);
	free(commands);
}
