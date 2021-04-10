#include "holberton.h"
/**
 * isBinCommand - simply adds /bin/ to the the string in the first argument and runs that
 * @command: the tokenized string of commands
 * Return: 1
 */
int isBinCommand(char **command)
{
    if (binExecute(command) == 0)
    {
        perror("isBinCommand, execution error");
        return (0);
    }
    return (1);
}