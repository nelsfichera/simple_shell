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
	int bytes_read;

	printf("made it to shell main.c\n");
    do
    {

	    /* read */
	    buffer = malloc(BUFFER_SIZE * sizeof(char));
	    if (buffer == NULL)
	    {
			perror("buffer cannot be stored");
		    return (-1);
	    }
	    printf("SimpleShell$ ");
	    bytes_read = getline(&buffer, &bufsize, stdin);
		printf("the bytes_read is %d\n", bytes_read);
		printf("made it through getline\n");
		printf("buffer is %s\n", buffer);
		printf("buffer can be printed twice, %s\n", buffer);
	    /* the parent process should return 1, which is True for the while loop */
	    success = parse(buffer);
    } while (success);

    return (0);
}
