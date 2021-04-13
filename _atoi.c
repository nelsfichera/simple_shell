#include "holberton.h"
/**
* _atoi - mimics standard atoi, creates an int from a char
* @str: the string to convert
* Return: integer
*/
int _atoi(char *str)
{
	int x = 0, negative = -1, integer = 0, flag = 0;

	while(str[x] != '\0')
	{
		if(str[x] == '-')
			negative = negative * -1;
		if (str[x] >= '0' && str[x] <= '9')
		{
			integer = integer * 10;
			integer = integer - (str[x] - '0');
			flag = 1;
		}
		else if (flag == 1)
			break;
		x++;
	}
	integer = integer * negative;
	return (integer);
}
