This repository contains all of the files necessary to compile the hsh, a limited capability command line interpreter program. This hsh is able to get commands typed into standard input,r ead and execute limited commands. 

To install this shell, clone the repository and compile its content with the following command:
gcc -Wall -Werror -Wextra -pedantic \*.c -o hsh.

When the files have been compiled, run the command ./hsh on the command line. After this, the shell should work as expected, executing any supported command. 

Features: 

Builtin:
This shell receives the env command and prints a list of the environment variables.
This shell receives the exit command and exits. 

[help, cd,  control c, control d]

A breakdown of each file and its functions: 

\_atoi.c: changes string to integer.
\_cd.c: changes directory
\_env.c: contains functions to get, set, and unset the environmental variables. 
\_exit.c: contains the exit function. 
\_strcat.c: concatentates two strings 
\_strcmp.c: compares to strings
\_strcpy.c: copies a string
\_strlen.c: gets the length of a string 
\_strtok.c: tokenizes a string
built\_in.c: gets built-in functions. 
execute.c: executes the given command 
holberton.h: our header file
isBinCommand: checks to see if the entered command is found in the /bin/
man\_1\_simple\_shell: the man page of our function
parse.c: parses the given command and calls the right process. 
shell\_main.c: the main file, which directs input.

Authors: 
Nels Fichera 
Thomas Francis
