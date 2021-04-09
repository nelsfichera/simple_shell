#include "holberton.h"
/**
 * _strcat - concatenate two strings
 * @dest: final
 * @src: src
 * Return: char
 */

char *_strcat(char *dest, char *src)
{
	int destlen;
	int x;

	for (destlen = 0; dest[destlen] != 0; destlen++)
	{
		continue;
	}

	for (x = 0; src[x] != 0; x++)
	{
		dest[destlen] = src[x];
		destlen++;
	}
	dest[destlen] = '\0';
	return (dest);
}
/*
int main(void)
{
	char str1[100] = "This is a string";
	char str2[100] = "This is another string";
	char *str3 = malloc(strlen(str1) + strlen(str2) + 1);

	str3 = _strcat(str1, str2);
	printf("%s\n", str3);
	return(0);
}
*/