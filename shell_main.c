#include "holberton.h"

/**
 * main - where everything begins. It's better to have many small files dedicated to for each function than a few large files.
 * Return: 0
 */

int main(void)
{ 
 	size_t bufsize = BUFFER_SIZE;
    char *buffer;
    int success = 1;

    do
    {
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
    } while (success);

    return (0);
}
