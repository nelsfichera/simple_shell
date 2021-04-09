#include "holberton.h"

char *_strcat(char *str1, char *str2)
{
	int x, n;
	char *str3;

	str3 = malloc(sizeof(char) * (_strlen(str1) + _strlen(str2) + 1));

	if (str3 == NULL)
		return (NULL);

	for(x = 0; str1[x] != '\0'; x++)
		str3[x] = str1[x];
	for(n = 0; str2[n] != '\0'; n++, x++)
		str3[x] = str2[n];
	str3 = '\0';

	return(str3);

}
int main(void)
{
	strcpy(str1, "This is a string");
	strcpy(str2, "This is another string");

	_strcat(str1,str2);
	return(0);
}

