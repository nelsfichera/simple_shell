#include "holberton.h"
/*
 * https://c-for-dummies.com/blog/?p=1112
 */
int main(void)
{
    size_t bufsize = 100;
    char *buffer = malloc(bufsize * sizeof(char));

    printf("$ ");
    getline(&buffer, &bufsize, stdin);
    printf("%s\n", buffer);
}