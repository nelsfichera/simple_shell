#include "holberton.h"
/*initial attempt at an execute function, to be coordinated with main*/

int execute(char **commands)
{
	pid_t parent_pid;
    pid_t child_pid;
	char *pathstat;

    /* Evaluate */
    parent_pid = getpid();
    child_pid = fork();

	if (commands == NULL || commands[0] == NULL)
		perror("Error: could not execute");
	/* path module determines if the file exists in the given path */
	/* path */
	if (child_pid == 0)
	{
		pathstat = pathmod(commands[0]);
		if (pathstat == "bad")
			exit(2);
		if (execve(pathstat, commands, NULL) == -1)
		{
			perror("Error");
			exit(2);
		}
	}
	else if (child_pid < 0)
		perror("Error");
	else
		wait(NULL);
	return (1);
}
