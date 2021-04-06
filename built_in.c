#include "holberton.h"
/*initial attempt at exit, needs to be added to as we have a better understanding of scope*/
int exitshell(char **command)
{
	if(command)
	exit(1);
	return (EXIT_SUCCESS);
}
/*int printenv(char **command)
{
	int x;
	if (*command)
	{
		x = 0;
		while(environ[x])
		{
			write(1, environ[x], _strlen(environ[x]));
			write(1, "\n", 1);
			x++;
		}
	}
	return(0);
}
commented out for testing*/

int checkbuiltin(char **command)
{
	int x; 
	char *array[] = {"exit", "cd", "env", NULL}; 

	typedef int(*builtin)(char **);
	builtin functions [] = {&exitshell, &cd, &printenv};

	x = 0;

	while (array[x])
	{
		if (_strcmp(array[x], command[0]) == 0)
				return (functions[x](command));
		x++;
	}
	return (execute(command));
}
