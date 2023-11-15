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

/**
 * _atoi - Custom implementation of atoi to convert a string to an integer.
 * @str: The input string to be converted.
 * Return: The converted integer value.
 */

int _atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	while (str[i] != '\0')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}

	return (sign * result);
}

/**
 * _strncmp - Compare up to n characters of two strings.
 * @a: The first string.
 * @b: The second string.
 * @n: The maximum number of characters to compare.
 * Return: 0 if the strings are equal, a negative
 */
int _strncmp(const char *a, const char *b, size_t n)
{
	while (n > 0 && *a && *b && (*a == *b))
	{
		a++;
		b++;
		n--;
	}
	if (n > 0)
		return (*(unsigned char *)a - *(unsigned char *)b);
	return (0);
}
