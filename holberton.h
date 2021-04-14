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
#include <errno.h>
/*macros and extern*/
#define BUFFER_SIZE 1024
extern char **environ;
/*str handlers*/
int _putchar(char c);
int _strlen(const char *s);
char *_strcat(char *str1, char *str2);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
char *_strtok(char *str, const char *delimiters);
char *_modstrtok(char *str, const char *delim, char **save);
char **splitline(char *input);
char *_strchr(const char *s, int x);
unsigned int _strspn(char *s, const char *find);
size_t _strcspn(const char *s, const char *reject);
/*memory*/
char *_memset(char *addy, char value, unsigned int size);
void *_calloc(unsigned int members, int size);
/*main functions*/
int main (int argc, char *argv[], char *envp[]);
int execute_builtin(char **args, char **env);
int _execute(char **args);
int carvePath(char **args);
char *findPath(char *command);
char *commandPath(char *command, char **path);
void setFullPath(char *destination, char *path, char *command);
char **getPath(void);
unsigned int countDelims(char *str);
/*builtins*/

int _printenv(char **env);
int _atoi(char *str);
int _builtinexit(char **arguments);
char *_getenv(const char *var);
int _cd(char **commands);
int binExecute(char **commands);
int _env(char **env_var);
char *_getline(void);
int _getchar(void);

/*main printing functions*/
char *(*getfunction(char n))(va_list);
int output(char *buffer, int buffer_size, int start, int mode, ...);
#endif
