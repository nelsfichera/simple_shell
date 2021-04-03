#include "holberton.h"
/** pathmod - path module that checks where the command comes from
 * @compath: command path. All commands are a path until proven guilty.
 * Return: string that will eventually be passed into execve
 */
char *pathmod(char *compath)
{
    struct stat stats;
    char *bin = "/bin/";
    int comIsPath;
    /* building an error string */
    char *environment = "bash: ";
    char *path_not_exists = ": No such file or directory";

    if (compath == "cd")
    {
        return (compath);
    }
    /* it would be best to determine if compath is a path or a command */
    /* ispath() function needs to be built */
    comIsPath = ispath(compath); /* returns either 1 or 0. 1 is true. 0 is false */

    /* stat() dumps info to struct stat stats*/
    /* if the executable file exists in compath */
    if (comIsPath == 1)
    {
        if (stat(compath, &stats) == 0) /* incorrect figure out a function that looks for the command */
        {                               /* do nothing, this path exists */
            return (compath);
        }
        strcat(environment, compath);
        strcat(environment, path_not_exists);
        perror(environment);
        return ("bad");
    }
    /* below only accounts /bin/. Needs to account for other universally exposed folders like cd/ for cd command */
    strcat(bin, compath);
    if (stat(bin, &stats) == 0)
    {
        return (bin);
    }
    /* there can be a lot of similar checks for other universally exposed folders */
    /* build error for when path does not exist. Environment should be defined. Defined as "bash" for now*/
    strcat(compath, ": command not found");
    perror(compath);
    return ("bad");
}