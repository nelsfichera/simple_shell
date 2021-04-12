#ifndef HOLBERTON_H
#define HOLBERTON_H
/*standard lib headers*/
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stddef.h>
/*macros and extern*/
#define BUFFER_SIZE 128
#define DELIM " \n\a\t"
extern char **environ;
/*function pointers*/ 
typedef struct builtin
{
	char **command; 
	void (*function)(char *);
} built_in; 
/*str handlers*/
int _putchar(char c);
int _strlen(char *s);
char *_strcat(char *str1, char *str2);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strtok(char *str, char *separator, int flag);
/*main functions*/
int execute(char **commands);
int parse(char *inputstring);
int checkbuiltin(char **command);
int isPath(char *path);
int isBinCommand(char **command);
/*builtins*/
int pathmod(char *compath);
int _printenv(char **env);
int _atoi(char *str);
int _builtinexit(char **arguments);
char *_getenv(char *name, char **env);
int _cd(char **commands);
int binExecute(char **commands);
int _env(char **env);
#endif
