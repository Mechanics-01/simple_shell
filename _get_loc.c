#include "shell.h"

/**
 * get_loc - Get the location of a command in the PATH.
 * @arg: The command to locate.
 * Return: The full path of the command, or NULL if not found.
 */
char *get_loc(char *arg)
{
	char *path;

	if (arg[0] == '/')
	{
		path = _strdup(arg);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		return (NULL);
	}
	path = _getenv("PATH");

	if (path)
	{
		path = location(path, arg);
		return (path);
	}
	return (NULL);
}
