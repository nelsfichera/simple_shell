#include "holberton.h"
/*initial attempt at exit, needs to be added to as we have a better understanding of scope*/
int exitshell(char **command)
{
	if (*command)
	exit(1);
	return (EXIT_SUCCESS);
}
int printenv(char **command)
{
	int x;
	if (*command)
	{
		x = 0;
		while(environ[x])/*defined in extern char*/
		{
			write(1, environ[x], _strlen(environ[x]));
			write(1, "\n", 1);
			x++;
		}
	}
	return(0);
}
int cd (char **command)
{
	chdir(command[1]);
	return (0);
}

