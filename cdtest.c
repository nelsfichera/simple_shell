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
    char s[100];
    char *argv[] = {". ./chdir.sh", "whatever"};

    do
    {
        printf("cwd is now %s\n", getcwd(s,100));
	    /* read */
	    buffer = malloc(BUFFER_SIZE * sizeof(char));
	    if (buffer == NULL)
	    {
			perror("buffer cannot be stored");
		    return (-1);
	    }
	    printf("SimpleShell$ ");
	    getline(&buffer, &bufsize, stdin);
	    /* the parent process should return 1, which is True for the while loop */
        printf("current working directory is %s\n", getcwd(s, 100));
        printf("buffer is %s\n", buffer);
        /* execve(argv[0], argv, NULL); */
        chdir("testfolder"); /* I can't believe this works as is */
        printf("this cwd is now %s\n", getcwd(s,100));
    } while (success);

    return (0);
}
/*
gcc thomasCD.c cdtest.c isPath.c _strlen.c -o cdtest
*/
