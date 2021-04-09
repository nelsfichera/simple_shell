#include "holberton.h"
/*initial attempt at an execute function, to be coordinated with main*/

int execute(char **commands)
{
	pid_t child_pid;

	/* Evaluate */
	child_pid = fork();

	if (commands == NULL || commands[0] == NULL)
		perror("Error: could not execute");
	if (child_pid == 0)
	{ /* if child was successfully created */
		if (execve(commands[0], commands, NULL) == -1)
		{ /* if execve fails */
			perror("Error, execve path failed for some reason");
			return (1);
		}
	}
	if (child_pid < 0)
	{
		perror("Error: child was not created correctly");
		return (1);
	}

	wait(NULL);
	return (1);
}
