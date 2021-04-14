#include "holberton.h"
/**
* _getenv - gets the environment variables from path
* @var: the name of the variable
* Return: variable on success, null on failure
*/
char *_getenv(const char *var)
{
	int var_len = _strlen(var);

	char **ptr;
	char *output;

	ptr = environ;

	while (*ptr)
	{
		if (strncmp(*ptr, var, var_len) == 0)
		{
			output = *ptr + var_len + 1;
			return (output);
		}
		ptr++;
	}
	return (NULL);
}
/**
* _env - prints all the env variables
* @env_var: environment variables
* Return: 1
*/

int _env(char **env_var)
{
	unsigned int index;
	int env_var_len = 0;

	for (index = 0; env_var[index] != NULL; index++)
	{
		env_var_len = _strlen(env_var[index]);
		write(1, env_var[index], env_var_len);
		write(1, "\n", 1);
	}
	return (1);
}
/*a set env will go here if we need to*/

