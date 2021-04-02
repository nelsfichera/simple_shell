#include "holberton.h"

/**
 * main - where everything begins. It's better to have many small files dedicated to for each function than a few large files.
 * Return: 0
 */

int main(void)
{
    pid_t parent_pid;
    pid_t child_pid;
    int status;
    size_t bufsize = 1024; /* for now. Should increase or workaround later. The workaround is going to be a macros */
    char *buffer;
    char *sep;
    char bufferarray[16][64];
    
    do
    {
        /* read */
        buffer = malloc(bufsize * sizeof(char));
        if (buffer == NULL)
        {
            return (-1);
        }
        printf("SimpleShell$ ");
        getline(&buffer, &bufsize, stdin);
        /* Evaluate */
        sep = " ";
        /* would be helpful to return the size of the largest string to malloc() the bufferarray correctly */
        bufferarray = parse(buffer, sep);
        /* getpid() info */
        /* fork() */
        parent_pid = getpid();
        child_pid = fork();
        if (child_pid == -1)
        {
            perror("Error:");
            return (1);
        }
        /* if a process is a child, run execute() */
        if (child_pid == 0)
        {
            /* we're not allowed to use printf technically, but we'll probably replace with _printf from the printf project anyways. Worst case, use _putchar() I guess. */
            printf("Testing: child made it to execute.");
        /* execute() */
            execute();
            exit(1);
        }
        /* wait is supposed to NULL. This works because status is NULL by default*/
        wait(&status);
        /* else (if) a process is a parent */

        /* run execve(./shell) to restart the shell */
        /* if restarting the shell fails, print error and return (0); */
    } while (status);

    return (0);
}
