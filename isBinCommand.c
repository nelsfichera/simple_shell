#include "holberton.h"
/**
 * isBinCommand - simply adds /bin/ to the the string in the first argument and runs that
 * @command: the tokenized string of commands
 * Return: 1
 */
int isBinCommand(char **command)
{
    char *bin = "/bin/";

    printf("made it to isBinCommand");
    _strcat(bin, command[0]);
    execve(bin, command, NULL);
    return (1);
}