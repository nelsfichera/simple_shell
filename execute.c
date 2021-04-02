#include "holberton.h"
/*initial attempt at an execute function, to be coordinated with main*/

int execute(char **commands)
{
	pid_t parent_pid;
    pid_t child_pid;
	int status; 

    /* Evaluate */
    parent_pid = getpid();
    child_pid = fork();

	if (commands == NULL || commands[0] == NULL)
		perror("Error: could not execute");

	if (child_pid == 0)
	{
		if (execve(commands[0], commands, NULL) == -1)
		{
			perror("Error");
			exit(2);
		}
	}
	else if (child_pid < 0)
		perror("Error");
	else
		wait(&status); /* status is NULL by default */
	return (1);
}
