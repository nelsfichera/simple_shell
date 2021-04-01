#include "holberton.h"

int main(int ac, char **av)
{
    int iter;

    for (iter = 0; *(av + iter); iter++)
    {
        printf("%s\n", *(av + iter));
    }
    return (0);
}