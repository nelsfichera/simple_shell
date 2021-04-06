#include "holberton.h"

/**
 * main - where everything begins. It's better to have many small files dedicated to for each function than a few large files.
 * Return: 0
 */

int main(void)
{ 
 	size_t bufsize = BUFFER_SIZE;
    char *buffer;
    char *sep;
    int success = 1;

    do
    {

	    /* read */
	    buffer = malloc(BUFFER_SIZE * sizeof(char));
	    if (buffer == NULL)
	    {
		    return (-1);
	    }
	    printf("SimpleShell$ ");
	    getline(&buffer, &bufsize, stdin);
	    if (getline == "exit")
	    {
		   exitshell();
	    }
	    sep = " ";
	    /* the parent process should return 1, which is True for the while loop */
	    success = execute(parse(buffer, sep));
    } while (success);

    return (0);
}
