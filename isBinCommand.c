#include "holberton.h"
/**
 * isBinCommand - simply adds /bin/ to the the string in the first argument and runs that
 * @command: the tokenized string of commands
 * Return: 1
 */
int isBinCommand(char **command)
{
    char bin[1024] = "/bin/";
    char **new_command = malloc(sizeof(bin) + sizeof(command));
    int iter = 1;

    strcat(bin, command[0]);
    new_command[0] = bin;
    while (command[iter])
    {
        _strcpy(new_command[iter], command[iter]);
        iter++;
    }
    execute(new_command);
    return (1);
}