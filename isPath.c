#include "holberton.h"

/**
 * isPath - determines if the command is a path https://codeforwin.org/2018/03/c-program-check-file-or-directory-exists-not.html
 * @path: input string
 * Return: 2 for folder, 1 for file, 0 for error
 */
int isPath(char *path)
{
    struct stat stats;

    printf("made it to path with path, %s\n", path);
    /* checks if path is a file that exists */
    if (stat(path, &stats) == 0)
    {
        printf("found file for path %s\n", path);
        return (1);
    }
    perror("isPath.c, file not found");
    /* checks if a path is a folder that exists */
    /* we don't really need this right now so I'll comment it out
    if (S_ISDIR(stats.st_mode))
    {
        printf("found folder for path %s", path);
        return (2);
    }
    */
    return (0);
}