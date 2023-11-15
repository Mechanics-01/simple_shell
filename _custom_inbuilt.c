#include "shell.h"

/**
 * _strdup - Duplicates a string.
 * @source: The string to duplicate.
 * Return: A pointer to the duplicated string
 */
char *_strdup(const char *source)
{
	size_t len;
	char *dup;

	if (source == NULL)
		return (NULL);
	len = _strlen(source) + 1;

	dup = (char *)malloc(len);

	if (dup == NULL)
		return (NULL);

	_strcpy(dup, source);

		return (dup);
}


/**
 * _strcmp - Compare two strings.
 * @a: First string to compare
 * @b: Second string to compare
 * Return: 0 if strings are equal, positive else negative
 */
int _strcmp(char *a, char *b)
{
	while (*a == *b && *a != '\0')
	{
		a++;
		b++;
	}

	return (*a - *b);
}


/**
 * _strcpy - Copies the string from src to dest.
 * @dest: Pointer to the destination buffer.
 * @loc: Pointer to the source string.
 * Return: A pointer to the destination string (dest).
 */
char *_strcpy(char *dest, const char *loc)
{
	int i;

	for (i = 0; loc[i] != '\0'; i++)
	{
		dest[i] = loc[i];
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * _strlen - Returns the length of a string.
 * @str: Pointer to the target string.
 * Return: Length of the string.
 */
int _strlen(const char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
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
