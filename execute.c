#include "holberton.h"
/*initial attempt at an execute function, to be coordinated with main*/

int execute(char **commands)
{
	struct stat stats;
	/*pid_t parent_pid;*/
	pid_t child_pid;
	int pathorcom;

	/* Evaluate */
	/*parent_pid = getpid();*/
	child_pid = fork();

	if (commands == NULL || commands[0] == NULL)
		perror("Error: could not execute");
	/* path module determines if the file exists in the given path */
	/* path */
	if (child_pid == 0)
	{ /* if child was successfully created */
		pathorcom = isPath(commands[0]);
		if (pathorcom == 1) /* if it is a normal path*/
		{					/* check if the path exists*/
			if (stat(commands[0], &stats) == 0)
			{ /* if the path exists then run execve normally*/
				if (execve(commands[0], commands, NULL) == -1)
				{ /* if execve fails */
					perror("Error, execve path failed for some reason");
					return (1);
				}
			}
			perror("Path does not exist");
			return (1);
		}
		/* if pathorcom is not a normal path, then it must be a command */
		if (execve(checkbuiltin(commands), commands, NULL) == -1)
		{ /* if execve fails */
			perror("Error, command failed for some reason");
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
