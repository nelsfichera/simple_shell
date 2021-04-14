#include "holberton.h"
/**
* checkbuiltin - checks if a command is a built in function or not
* @command: the command being passed to the shell
* Return: pointer to function on success, 0 on failure
*/
int checkbuiltin(char **command)
{
	int x;
	char *array[] = {"exit", "cd", "env", NULL};

	typedef int(*builtin)(char **);
	builtin functions [] = {&_builtinexit, &_cd, &_env};

	x = 0;

	while (array[x])
	{
		if (_strcmp(array[x], *command) == 0)
			return (functions[x](command));
		x++;
	}
	return (0);
}