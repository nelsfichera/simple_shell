#include "holberton.h"
/**
 * _cd - a builtin function for changing directory. This function needs to be in the parent process, not a child process
 * @path: path to change to
 * Return: 1
 */
int _cd(void)
{
    char *argv[] = {". ./chdir.sh", "whatever"};
    execve(argv[0], argv, NULL);
    return (1);
}