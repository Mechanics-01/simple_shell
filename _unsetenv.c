#include "shell.h"

/**
 * _unsetenv - Unsets or removes an environment variable
 * @name: The name of the environment variable to unset
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	int env_index;
	size_t name_len;
	int i;

	if (name == NULL || name[0] == '\0')
		return (-1);

	env_index = 0;
	name_len = strlen(name);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0)
		{
			env_index = i;
			break;
		}
	}

	if (env_index != 0)
	{
		for (i = env_index; environ[i] != NULL; i++)
			environ[i] = environ[i + 1];

		return (0);
	}
	return (-1);
}
