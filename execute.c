#include "holberton.h"
/**
* execute - executes a command as a child process
* @commands: the command being passed to the shell
* Return: 0 on failure, 1 on success
*/
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
			perror(commands[0]);
			return (1);
		}
	}
	if (child_pid < 0)
	{
		return (1);
	}

	wait(NULL);
	return (1);
}
