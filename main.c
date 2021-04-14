#include "holberton.h"
/**
* main - main dowhile loop to get functions
* @argc: arg count 
* @argv: arg val
* @envp: env var
* Return: 0
*/
int main (int argc, char *argv[], char *envp[])
{
	char *input, **args;
	int status = 1;

	(void) argc;
	(void) argv;

	do {
		if (isatty(STD_FILENO))
			write(1, "($) ", 4);

		input = getline();
		args = line_split(input);
		status = execute_builtin(args, envp);
		free(input);
		free(args);
	}while (status);

	return (0);
}
/**
* execute_builtin - gets the builtins and executes them
* @args: args 
* @env: env var
* Return: what the function returns
*/
int execute_builtin(char **args, char **env)
{
	static char *builtin[] = {"cd", "env", "exit"};
	static int built_num = 3;

	int (*builtin_function) (char **) = { &_cd, &_env, &_exit};

	int index, exit_ret, exit_args = 0;

	if (*args == NULL)
		return (1);
	for (index = 0; index < built_num; index++)
	{
		if (_strcmp(args[0], "env") == 0)
			return(_env(env));
		if (_strcmp(args[0], "exit") == 0)
		{
			exit_ret = _exit(args);
			exit_args = _atoi(args[1]);
			if (exit_args < 0)
			{
				write (1, "Illegal exit code", 23);
				free(args);
				exit(EXIT_FAILURE);
			}
			if (exit_ret == -1)
				perror("Error on exit");
			else
			{
				free(args[0]);
				free(args);
				exit(exit_ret);
			}
		}
			if (_strcmp(args[0], builtin[index] == 0)
					return((*builtin[index])(args));
	}
	return (_execute(args));
}

/**
* _execute - handles executing the files
* @args: args
* Return: 1 on success, 0 on failure
*/
int _execute(char **args)
{
	int status, execute_status;
	pid_t process_id;

	if (*args == NULL)
		return (1);
	
	process_id = fork();

	if (process_id == 0)
	{
		if (_strchr(args[0], '/') != NULL)
		{
			execute_status = execve(args[0], args, environ);
			if (execute_status == -1)
			{
				perror("Execution error");
				return (0);
			}
		}
		else 
			return(carvePath(args));
	}
	else if (process_id < 0)
		perror("Failure to fork");
	else
		wait(&status);
	return (1);
}
