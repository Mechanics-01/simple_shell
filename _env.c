#include "shell.h"

/**
 * env - It Print environment variables
 * @envp: The array of environment variables
 * Return: Always 0
 */
int env(char *envp[])
{
	unsigned int i = 0;

	while (envp[i] != NULL)
	{
		write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
