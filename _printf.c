#include "holberton.h"

#include <stdio.h>

/**
* get_function - get the appropriate function
* @n: identifier for function
* Return: Pointer to a string formatting function
*/
char *(*get_function(char n))(va_list)
{
	int x  = 0;
	func_t func_table[] = {
		{'c', format_char},
		{'s', format_string},
		{'%', format_percent},
		{'d', format_decimal},
		{'i', format_decimal},
		{'b', format_binary},
		{'R', format_rot13},
		{'r', format_reverse},
		{'o', format_octal},
		{'u', format_unsigned},
		{'\0', NULL}
	};
	while (func_table[x].type != '\0')
	{
		if (func_table[x].type == n)
			return (func_table[x].function);
		x++;
	}
	return (NULL);
}
/**
 * output - a temporary function in place of buffer functions to test _printf
 * @buffer: buffer destination
 * @buffer_size: size of the buffer
 * @start: where to start writing to the buffer
 * @char_mode: for copying single chars (used to force copy a null byte)
 * Return: Number of bytes copied to the buffer
 */
int output(char *buffer, int buffer_size, int start, int char_mode, ...)
{
	int bi = start;
	int si = 0;
	va_list arguments;
	char *string;

	va_start(arguments, char_mode);
	if (char_mode < 0)
	{
		buffer[bi % buffer_size] = *va_arg(arguments, char *);
		if (++bi % buffer_size == 0)
			write(1, buffer, buffer_size);
	}
	else if (char_mode)
	{
		for (; si < char_mode; si++)
		{
			buffer[bi % buffer_size] = va_arg(arguments, int);
			if (++bi % buffer_size == 0)
				write(1, buffer, buffer_size);
		}
	}
	else
	{
		string = va_arg(arguments, char *);
		for (; string[si]; si++)
		{
			buffer[bi % buffer_size] = string[si];
			if (++bi % buffer_size == 0)
				write(1, buffer, buffer_size);
		}
	}
	va_end(arguments);
	return (bi - start);
}

/**
* _printf - manages sub-functions, returns number of bytes
* @format: the format to be executed on a string
* Return: number of bytes, output printed string
*/
int _printf(const char *format, ...)
{
	char *string, buffer[1024], parse_format_mode = 0;
	int x, byte_count = 0;
	va_list arguments;
	char *(*format_function)(va_list) = NULL;

	if (!format)
		return (-1);
	va_start(arguments, format);
	for (x = 0; format[x]; x++)
	{
		if (!parse_format_mode)
		{
			if (format[x] == '%')
				parse_format_mode = 1;
			else
				byte_count += output(buffer, 1024, byte_count, 1, format[x]);
			continue;
		}
		format_function = get_function(format[x]);
		if (!format_function)
			byte_count += output(buffer, 1024, byte_count, 2, '%', format[x]);
		else
		{
			string = format_function(arguments);
			if (!string)
				byte_count += output(buffer, 1024, byte_count, 0, "(null)");
			else
			{
				byte_count += output(buffer, 1024, byte_count, -(format[x] == 99), string);
				free(string);
			}
		}
		parse_format_mode = 0;
	}
	if (byte_count % 1024 != 0)
		write(1, buffer, byte_count % 1024);
	va_end(arguments);
	return (parse_format_mode ? -1 : byte_count);
}
