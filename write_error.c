#include "holberton.h"

void error(char *program, char *command)
{

	write(2, name, _strlen(name));
	write(2, ": ", 2);
	write(2, command, _strlen(command));
	write(2, ": not found\n", 12);
}
