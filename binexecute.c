#include "holberton.h"
/*initial attempt at an execute function, to be coordinated with main*/

int binExecute(char **commands)
{
	pid_t child_pid;
    char bin[100] = "/bin/";

	/* Evaluate */
	child_pid = fork();

	if (commands == NULL || commands[0] == NULL)
	{
		return (0);
	}
	if (child_pid == 0)
	{ /* if child was successfully created */
    _strcat(bin, commands[0]);
		if (execve(bin, commands, NULL) == -1)
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
