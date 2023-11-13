#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable.
 * Return: The value of the environment variable, or NULL if not found.
 */
char *_getenv(const char *name)
{
	int i;
	char *env;

	if (name == NULL || environ == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		env = environ[i];
		if (strncmp(env, name, strlen(name)) == 0 && env[strlen(name)] == '=')
			return (env + strlen(name) + 1);
	}
	return (NULL);
}
