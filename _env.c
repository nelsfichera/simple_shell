#include "holberton.h"

char *_env(const char *name, char **env)
{
	int x = 0;
	int n = 0;

	if (name == NULL || env == NULL || *env == NULL)
		return (NULL);
	while(env[x])
	{
		while(env[x][n] == name[n])
				n++;
		/* without  curly braces, n just goes to the end rather than iterating over the environment list*/
		if (env[x][n] == '=')
		{
			n++;
			return (&(env[x][n]));
		}
		x++;
		n = 0;
	}
	write(STDOUT_FILENO, "ERROR", 5);
	return(NULL);
}
