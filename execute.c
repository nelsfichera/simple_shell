#include "holberton.h"
/*initial attempt at an execute function, to be coordinated with main*/

int execute(char **commands)
{
	pid_t child_pid;

	/* Evaluate */
	child_pid = fork();

	if (commands == NULL || commands[0] == NULL)
	{
		return (0);
	}
	if (child_pid == 0)
	{ /* if child was successfully created */
		if (execve(commands[0], commands, NULL) == -1)
		{ /* if execve fails */
			return (0);
		}
	}
	if (child_pid < 0)
	{
		return (0);
	}

	wait(NULL);
	return (1);
}
