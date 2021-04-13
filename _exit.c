#include "holberton.h"
/**
* _builtinexit - mimics the standard exit command and exits the shell
* @arguments: any flags or arguments passed to exit
* Return: -1 on success.
*/
int _builtinexit(char **arguments)
{
	int flag, x, integer = 0;

	if (arguments[1] == NULL)
	{
		free(arguments[0]);
		free(arguments);
		exit(EXIT_SUCCESS);
	}
	for (x = 0; arguments[1][x]; x++)
	{
		if ((arguments[1][x] >= '0' && arguments[1][x] <= '9')
		|| arguments[1][0] == '+')
		{
			flag = 1;
			if (arguments[1][x + 1] < '0' || arguments[1][x + 1] > '9')
				break;
		}
		else
			break;
		flag = 0;
	}

	if (flag == 1)
	{
		integer = _atoi(arguments[1]);
		return (integer);
	}
	return (-1);
}

