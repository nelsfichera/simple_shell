#include "holberton.h"

/**
 * isPath - determines if the command is a path
 * @isthispath: input string
 * Return: either 0 or 1. 1 for true. 0 for false.
 */
int isPath(char *isthispath)
{
    int iter = 0;
    int str_len = _strlen(isthispath);

    if (str_len == 1 && isthispath[0] == '/')
    {
        return (1);
    }
    while (isthispath[iter])
    {
        if (isthispath[iter] != '/')
        {
            if (iter + 1 < str_len)
            {
                if (isthispath[iter + 1] == '/')
                {
                    return (1);
                }
            }
        }
    }
    return (0);
}