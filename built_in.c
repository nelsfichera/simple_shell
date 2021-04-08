#include "holberton.h"
/*initial attempt at exit, needs to be added to as we have a better understanding of scope*/

int checkbuiltin(char **command)
{
	int x; 
	char *array[] = {"exit", "cd", "env", NULL}; 

	typedef int(*builtin)(char **);
	builtin functions [] = {&_builtinexit, &_cd, &_printenv};

	x = 0;

	while (array[x])
	{
		if (_strcmp(array[x], *command) == 0)
			return (functions[x](command));
		x++;
	}
	return (0);
}
