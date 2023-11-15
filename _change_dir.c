#include "shell.h"

/**
 * change_d - Change the currents working directories
 * @d: The target directory
 */
void change_d(char *d)
{
	char *directory;
	char cdd[BUFFER];

	if (d == NULL)
	{
		directory = _getenv("HOME");
	}
	else if (_strcmp(d, "-") == 0)
	{
		directory = _getenv("OLDPWD");
	}
	else
	{
		directory = d;
	}

	if (chdir(directory) != 0)
	{
		perror("chdir");
		exit(1);
	}
	else
	{
		if (getcwd(cdd, sizeof(cdd)) == NULL)
		{
			perror("getcwd");
			exit(1);
		}
		_setenv("PWD", cdd, 1);
		_setenv("OLDPWD", _getenv("OLDPWD"), 1);
	}
}
