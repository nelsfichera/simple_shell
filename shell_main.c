#include "holberton.h"
/**
 * main - where everything begins.
 * @argc: number of arguments
 * @argv: arguments in string
 * Return: 0
 */
int main(int argc, char **argv)
{
	size_t bufsize = BUFFER_SIZE;
	char *buffer;
	char *NonActiveArray = malloc(argc * 100);
	int success = 1;
	int iter = 1;

	if (argc > 1)
	{
		while (argv[iter])
		{
			_strcat(NonActiveArray, argv[iter]);
			_strcat(NonActiveArray, " ");
			iter++;
		}
		parse(NonActiveArray);
	}
	else
	{
		do {
			_printf("($) ");
			/* read */
			buffer = malloc(BUFFER_SIZE * sizeof(char));
			if (buffer == NULL)
			{
				perror("buffer cannot be stored");
				return (-1);
			}
			getline(&buffer, &bufsize, stdin);
			/* the parent process should return 1, which is True for the while loop */
			success = parse(buffer);
			_putchar('\n');
		} while (success);
	}
	return (0);
}
