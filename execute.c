#include "holberton.h"
/*initial attempt at an execute function, to be coordinated with main*/

int execute(char **commands)
{
	pid_t child;
	int status; 

	if (commands == NULL || commands[0] == NULL)
		perror("Error: could not execute");

	child = fork();

	if (child == 0)
	{
		if (execve(commands[0], commands, NULL) == -1)
		{
			perror("Error");
			exit(2);
		}
	}
	else if (child < 0)
		perror("Error");
	else
		wait(NULL);
	return (EXIT_SUCCESS);
}
