#include "shell.h"

/**
 * location - Locate the executable file in the given path.
 * @path: The PATH environment variable.
 * @arg: The command to search for in the path.
 * Return: The full path to the executable if found, otherwise NULL.
 */
char *location(char *path, char *arg)
{
	char *path_cpy;
	char *path_token;
	char *filepath;
	char *delim = ":";

	path_cpy = _strdup(path);

	path_token = strtok(path_cpy, delim);

	filepath = malloc(_strlen(arg) + _strlen(path_token) + 2);

	while (path_token != NULL)
	{
		_strcpy(filepath, path_token);
		_strcat(filepath, "/");
		_strcat(filepath, arg);
		_strcat(filepath, "\0");

		if (access(filepath, X_OK) == 0)
		{
			free(path_cpy);
			return (filepath);
		}
		path_token = strtok(NULL, delim);
	}
	free(filepath);
	free(path_cpy);
	return (NULL);
}
