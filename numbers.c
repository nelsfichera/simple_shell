#include "holberton.h"
/**
* format_binary - changes an int to binary
* @argument: the integer to change
* Return: binaried string
*/
char *format_binary(va_list argument)
{
	int x = 0, i = 0, n = 0;
	int split = 1;
	char *binary;

	n = va_arg(argument, int);
	i = n;
	/*malloc up to max binary int*/
	binary = malloc(sizeof(char) * 33);
	if (binary == NULL)
		return (NULL);
	if (n == 0)
	{
		binary[0] = '0';
		binary[1] = '\0';
	}
	/*negative numbers*/
	if (n < 0)
	{
		binary[0] = 1 + '0';
		x++;
		n *= -1;
		i *= -1;
	}
	/*split and convert*/
	while (n > 0)
	{
		n /= 2;
		split *= 2;
	}
	split /= 2;
	while (split > 0)
	{
		binary[x++] = (i / split + '0');
		i %= split;
		split /= 2;
	}
	binary[x] = '\0';
	return (binary);
}
/**
* format_octal - formats into octal notation
* @argument: the integer to convert
* Return: octaled string
*/
char *format_octal(va_list argument)
{
	unsigned int x = 0;
	unsigned int i, n;
	int split = 1;
	char *octal;

	n = va_arg(argument, unsigned int);
	i = n;
	/*malloc up to max octal int*/
	octal = malloc(sizeof(char) * 12);
	if (octal == NULL)
		return (NULL);
	if (n == 0)
	{
		octal[0] = '0';
		octal[1] = '\0';
		return (octal);
	}
	/*split and convert*/
	while (n > 0)
	{
		n /= 8;
		split *= 8;
	}

	split /= 8;

	while (split > 0)
	{
		octal[x++] = (i / split + '0');
		i %= split;
		split /= 8;
	}
	octal[x] = '\0';
	return (octal);
}
/**
 * format_decimal - converts an int to a string
 * @argument: int to convert
 * Return: string format integer
 */
char *format_decimal(va_list argument)
{
	int integer = va_arg(argument, int);
	int digits, temp = integer;
	int limit = 0;
	char *formatted;

	for (digits = 0; temp != 0; digits++)
		temp /= 10;

	if (integer <= 0)
		digits++;	/* Negative sign or count zero as one digit */

	formatted = malloc(digits + 1); /* +1 for Null byte */
	if (!formatted)
		return (NULL);

	formatted[digits--] = '\0'; /* Set null byte at the end of the string */
	if (integer < 0)
	{
		formatted[0] = '-'; /* Negative sign at the beginning */
		limit = 1;
	}
	for (; digits >= limit; digits--)
	{
		temp = integer % 10;
		formatted[digits] = temp < 0 ? -temp + '0' : temp + '0';
		integer /= 10;
	}
	return (formatted);
}

/**
 * format_unsigned - converts an unsigned int to a string
 * @argument: unsigned int to convert
 * Return: string format unsigned int
 */
char *format_unsigned(va_list argument)
{
	unsigned int number = va_arg(argument, int);
	int digits, temp = number;
	char *formatted;

	for (digits = 0; temp != 0; digits++)
		temp /= 10;
	formatted = malloc(digits + 1);
	if (!formatted)
		return (NULL);
	formatted[digits--] = '\0';

	for (; digits >= 0; digits--)
	{
		temp = number % 10;
		formatted[digits] = temp < 0 ? -temp + '0' : temp + '0';
		number /= 10;
	}
	return (formatted);
}

/**
 * format_percent - returns "%"
 * Return: % in string format
 */
char *format_percent()
{
	char *c = malloc(sizeof(char) * 2);

	if (c == NULL)
		return (NULL);
	c[0] = '%';
	c[1] = '\0';
	return (c);
}
