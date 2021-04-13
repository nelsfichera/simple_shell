#include "holberton.h"

/**
 * isPath - determines if the command is a path
 * @path: input string
 * Return: 2 for folder, 1 for file, 0 for error
 */
int isPath(char *path)
{
	struct stat stats;

	/* checks if path is a file that exists */
	if (stat(path, &stats) == 0)
	{
		return (1);
	}
	return (0);
}
