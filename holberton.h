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
/*printf */
/**
* struct functions - struct for calling functions
* @type: identifies which function to use
* @function: pointer to the function called by type
*/
typedef struct functions
{
	 char type;
	 char *(*function)(va_list);

} func_t;
/*function pointers*/
/**
* struct builtin - structure for pointers to built in functions
* @command: commands
* @function: function
*/
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


/*main printing functions*/
char *(*getfunction(char n))(va_list);
int output(char *buffer, int buffer_size, int start, int mode, ...);
int _printf(const char *format, ...);

/*functions being called by type*/
char *format_binary(va_list);
char *format_char(va_list);
char *format_decimal(va_list);
char *format_hex(va_list);
char *format_octal(va_list);
char *format_percent();
char *format_reverse(va_list);
char *format_rot13(va_list);
char *format_string(va_list);
char *format_unsigned(va_list);
#endif
