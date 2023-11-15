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

/**
 * reportError - Report an error to stderr and exit with failure status.
 * @programName: The name of the program.
 * @fileName: The name of the file associated with the error.
 */
void reportError(const char *programName, const char *fileName)
{
	const char *msg = programName;
	int len = 0;

	const char err[] = ": 1: ";
	const char notFound[] = ": not found\n";
	const char term = '\0';

	while (msg[len] != '\0')
		len++;

	write(STDERR_FILENO, msg, len);
	write(STDERR_FILENO, err, sizeof(err) - 1);
	write(STDERR_FILENO, fileName, strlen(fileName));
	write(STDERR_FILENO, notFound, sizeof(notFound) - 1);
	write(STDERR_FILENO, &term, 1);

	_exit(EXIT_FAILURE);
}
