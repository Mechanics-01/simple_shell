#include "shell.h"

/**
 * env - Print environment variables
 * @envp: The array of environment variables
 * Return: Always 0
 */
int env(char *envp[])
{
	unsigned int i = 0;

	while (envp[i] != NULL)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}
