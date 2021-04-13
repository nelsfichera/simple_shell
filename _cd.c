#include "holberton.h"
/**
* _cd - changes the directory
* @commands: the directory to be changed to
* Return: 1 on success
*/
int _cd(char **commands)
{
	char cwd[BUFFER_SIZE];
	int index;
	int cwd_size = 0;

	if (!commands[1] || (commands[1][0] == '~' && !commands[1][1]))
		chdir(_getenv("HOME", NULL));
	else if (commands[1][0] == '-' && !commands[1][1])
	{
		chdir(_getenv("PREVPWD", NULL));
		getcwd(cwd, sizeof(cwd));
		for (index = 0; cwd[index] != '\0'; index++)
			cwd_size++;
		cwd[index] = '\n';
		write(1, cwd, cwd_size + 1);
	}
	else if (access(commands[1], F_OK) == 0)
	{
		if (access(commands[1], R_OK) != 0)
			write(1, "Permission denied\n", 32);
		else
			chdir(commands[1]);
	}
	else
		write(1, "Directory not found\n", 30);

	return (1);
}
