#include "holberton.h"

/**
* memset - mem set w constant bite
* @addy: address to fill 
* @value: value to fill
* @size: number of bytes
* Return: char
*/

char *_memset(char *addy, char value, unsigned int size)
{
	unsigned int count = 0;

	while (count < size)
	{
		*(addy + count) = value;
		count++;
	}
	return(addy);
}

/**
* _callos - allocates and initializes memory for an array
* @members: values to store
* @size: number of bytes
* Return: void pointer
*/
void *_calloc(unsigned int members, int size)
{
	void *pointer = NULL;

	if (members == 0 || size == 0)
		return (NULL);
	pointer = malloc(members *size);
	if (pointer == NULL)
		return (NULL);
	_memset(pointer, 0, size * members);
	return (pointer);
}
