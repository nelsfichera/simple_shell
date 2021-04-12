#include "holberton.h"

int _env(char **env)
{
	if (env)
		_printenv(environ);
	return (1);
}
int _printenv(char **env)
{
	unsigned int index = 0;
	int env_var_len = 0; 

	for (index = 0; env[index] != NULL; index++)
	{
		env_var_len = _strlen(env[index]);
		write(1, env[index], env_var_len);
		write(1, "\n", 1);
	}
	return (EXIT_SUCCESS);
}

char *_getenv(char *name, char **env)
{
	char *token1 = NULL, *token2 = NULL;
	char *env_name = NULL, *current_env = NULL;
	int x = 0; 

	env_name = strdup(name);

	while (env[x] && env)
	{
		current_env = NULL;
		token2 = NULL;
		current_env = strdup(env[x]);
		token1 = strtok(current_env, "=");
		token2 = strdup(strtok(NULL, "="));
		if (_strcmp(env_name, token1) == 0)
			break;
		free(current_env);
		free(token2);
		x++;
	}
	free(current_env);
	free(env_name);
	return(token2);
}

void _setenv(char *arg1, char *arg2, char *newenv[])
{
	char *new_var, set_var[BUFFER_SIZE];
	short x = 0, n = 0;

	if(!arg1 || !arg2)
	{
		write(STDERR_FILENO, "Parameters not found\n", 29);
		return;
	}
	_strcpy(set_var, arg1);
	_strcat(set_var, "=");

	while (environ[x] && _strcmp(environ[x], set_var))
		x++;
	_strcat(set_var, arg2);
	if(environ[x])
		_strcpy(environ[x], set_var);
	else
	{
		new_var = calloc(150, sizeof(char));
		_strcpy(new_var, set_var);
		while(newenv[n])
			n++;
		newenv[n] = new_var;
		newenv[n + 1] = NULL;
		environ[x++] = new_var;
		environ[x] = NULL;
	}
}
