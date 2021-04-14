#include "holberton.h"
/**
* carvePath - runs commands found in the path
* @args: arguments
* Return: execute status for main loop
*/
int carvePath(char **args)
{
	char *the_path;
	int execute_status;

	the_path = find_path(args[0]);

	if (the_path == NULL)
	{
		perror("Command not found");
		return (0);
	}
	else 
	{
		args[0] = the_path;
		execute_status = execve(args[0], args, environ);
		if (execute_status == -1)
		{
			free(the_path);
			perror("Error on execution");
			return (0);
		}
		free(the_path);
		return (0);
	}
}

/**
* findPath - finds a command in the path
* @command: the command to find
* Return: path of executable on success, null on failure
*/
char *findPath(char *command)
{
	char **env_path = getPath();
	char *output;

	output = commandPath(command, env_path);

	free(env_path);
	return (output);
}
/**
* commandPath - gets the command in a tokenized path
* @command: the command to find
* @path: tokenized path variable
* Return: path of executable on success, null on failure
*/
char *commandPath(char *command, char **path)
{
	int found_file;
	char *full_path;

	if (command == NULL || path == NULL)
		return (NULL);

	while (*path)
	{
		full_path = _calloc(_strlen(command) + _strlen(*path) + 2, sizeof(char));
		if (full_path == NULL)
		{
			perror("Error");
			return (NULL);
		}
		setFullPath(full_path, *path, command);
		found_file = access(full_path, F_OK);
		if (found_file != -1)
			return(full_path);
		free(full_path);
		path++;
	}
	return (NULL);
}
void setFullPath(char *destination, char *path, char *command)
{
	_strcat(destination, path);
	_strcat(destination, "/");
	_strcat(destination, command);
}
