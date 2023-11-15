#include "shell.h"

/**
 * _setenv - Set or update an environment variable
 * @name: The name of the environment variable
 * @value: The value to set for the environment variable
 * @overwrite: Flag to indicate whether to overwrite an existing variable
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	size_t name_len, value_len, env_len, i;
	char *new_env;
	int env_index;

	if (name == NULL || name[0] == '\0')
		return (-1);
	name_len = _strlen(name);
	value_len = (value != NULL) ? _strlen(value) : 0;
	env_len = name_len + value_len + 2;
	new_env = malloc(env_len);
	if (new_env == NULL)
		return (-1);
	for (i = 0; i < name_len; i++)
		new_env[i] = name[i];
	new_env[name_len] = '=';
	for (i = 0; i < value_len; i++)
		new_env[name_len + 1 + i] = value[i];
	new_env[env_len - 1] = '\0';
	env_index = 0;
	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0)
		{
			env_index = i;
			break;
		}
	}
	check_env(env_index, overwrite, new_env);
	return (0);
}

/**
 * check_env - Updates the environment variable based on the given index
 * @env_index: Index in the environment variable array
 * @overwrite: Flag indicating whether to overwrite an existing variable
 * @new_env: The new environment variable to set
 */
void check_env(int env_index, int overwrite, char *new_env)
{
	size_t i;

	if (env_index != 0)
	{
		if (overwrite)
		{
			environ[env_index] = new_env;
		}
		else
		{
			free(new_env);
		}
	}
	else
	{
		for (i = 0;; i++)
		{
			if (environ[i] == NULL)
			{
				environ[i] = new_env;
				environ[i + 1] = NULL;
				break;
			}
		}
	}
}
