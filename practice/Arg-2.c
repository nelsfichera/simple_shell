#include "holberton.h"
int main(int ac, char **av)
{
    char *buffer = strtok(*(av + 1), "-");

    if (ac != 2)
    {
        printf("only need one input string");
        return (0);
    }
    while (buffer != NULL)
    {
        printf("%s\n", buffer);
        buffer = strtok(NULL, "-");

    }


    return (0);
}