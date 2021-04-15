#include "holberton.h"
/**
* _getchar - gets a char
* Return: void
*/

int _getchar(void)
{
	char *character, buffer[1];
	int descript = 0;

	descript = read(STDIN_FILENO, buffer, 1);

	if (descript > 0)
	{
		character = buffer;
		return (*character);
	}
	else if (descript == -1)
	{
		perror("Error");
		return (0);
	}
	return (EOF);
}
/**
* _getline - get a line
* Return: void
*/
char *_getline(void)
{
	char *input = NULL;
	int ascii, index = 0, buffer_size = BUFFER_SIZE;

	input = _calloc(buffer_size, sizeof(char));

	if (!input)
	{
		perror("Error");
		return (NULL);
	}
	while (1)
	{
		ascii = _getchar();
		if (ascii == EOF)
		{
			free(input);
			exit(EXIT_SUCCESS);
		}
		else if (ascii == '\n')
		{
			input[index] = '\0';
			return (input);
		}
		input[index] = ascii;
		index++;
	}
	return (input);
}
