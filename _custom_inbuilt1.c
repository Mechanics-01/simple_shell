#include "shell.h"

/**
 * *_strcat - concatenates two strings
 * @dest: target string
 * @loc: target string to be added
 * Return: void
 */

char *_strcat(char *dest, char *loc)
{
	int i;
	int k = 0;

	for (i = 0; dest[i] != '\0'; i++)
	{
		;
	}
	while (loc[k] != '\0')
	{
		dest[i] = loc[k];
		i++;
		k++;
	}
	dest[i] = '\0';
	return (dest);
}
