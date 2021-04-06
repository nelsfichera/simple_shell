#ifndef HOLBERTON_H
#define HOLBERTON_H
/*standard lib headers*/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <stddef.h>
/*macros and extern*/
#define BUFFER_SIZE 1024
#define DELIM "\n\a\t"
extern char **environ;
/*function pointers*/ 
typedef struct builtin
{
	char *command; 
	void (*function)(char *);
} built_in; 
/*str handlers*/
int _putchar(char c);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strtok(char *str, char *separator, int flag);
/*main functions*/
int execute(char **commands);
char **parse(char *input, char *separator);
/*builtins*/
int pathmod(char *compath);
int isPath(char *isthispath);
char *_env(const char *name, char **env);
int exitshell(char **command);
int checkbuiltin(char *command);


#endif
