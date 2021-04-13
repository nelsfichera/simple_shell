#include "holberton.h"

/**
* format_rot13 - encodes a string in ROT13
* @argument: target string
* Return: Encoded string
*/
char *format_rot13(va_list argument)
{
	char *rot = va_arg(argument, char *);
	int x = 0, y = 0;
	char *rotated;
	char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rotabc[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	rotated = malloc(sizeof(_strlen(rot) + 1));
	for (x = 0; rot[x] != '\0'; x++)
	{
		for (y = 0; abc[y] != '\0'; y++)
		{
			if (rot[x] == abc[y])
			{
				rot[x] = rotabc[y];
				break;
			}
		}
	}
	rotated[_strlen(rot)] = '\0';
	for (x = 0; rotated[x]; x++)
		rotated[x] = rot[x];
	return (rotated);
}
/**
* format_char - prints a char arg
* @argument: the arg being passed
* Return: pointer to char
*/
char *format_char(va_list argument)
{
	char *c = malloc(sizeof(char) * 2);

	if (c == NULL)
		return (NULL);
	c[0] = va_arg(argument, int);
	c[1] = '\0';
	return (c);
}
/**
 * format_string - Prints an argument as a string
 * @argument: String argument
 * Return: Pointer to string
 */
char *format_string(va_list argument)
{
	int i;
	char *string = va_arg(argument, char *);
	char *new_string;

	if (string == NULL)
		return (NULL);
	new_string = malloc(_strlen(string) + 1);
	if (new_string == NULL)
		return (NULL);
	for (i = 0; string[i]; i++)
		new_string[i] = string[i];
	return (new_string);
}

/**
* format_reverse - Prints an argument string in reverse
* @argument: the argument
* Return: pointer to string
*/
char *format_reverse(va_list argument)
{
	char *reverse;
	char *string;
	int x, n, length = 0;

	string = va_arg(argument, char *);
	if (string == NULL)
		return (NULL);
	length = _strlen(string);

	reverse = malloc(sizeof(char) * (length + 1));
	if (reverse == NULL)
		return (NULL);

	for (n = (length - 1); n >= 0; n--)
		reverse[x++] = string[n];
	reverse[x] = '\0';
	return (reverse);
}
