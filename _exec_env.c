#include "shell.h"

/**
 * exec_env - It Execute environment-related commands
 * @argv: The array of command-line arguments
 * Return: Always 0
 */
void exec_env(char *argv[])
{
	char *b_msg;

	if (_strcmp(argv[0], "setenv") == 0)
	{
		if (argv[1] != NULL && argv[2] != NULL)
		{
			if (_setenv(argv[1], argv[2], 1) == -1)
			{
				b_msg = "setenv: Error establishing environment variable\n";
				write(2, b_msg, _strlen(b_msg));
			}
		}
		else
		{
			b_msg = "Usage: setenv VARIABLE VALUE\n";
			write(2, b_msg, _strlen(b_msg));
		}
	}
	else if (_strcmp(argv[0], "unsetenv") == 0)
	{
		if (argv[1] != NULL)
		{
			if (_unsetenv(argv[1]) == -1)
			{
				b_msg = "unsetenv: Error establishing environment variable\n";
				write(2, b_msg, _strlen(b_msg));
			}

		}
		else
		{
			b_msg = "unsetenv: Usage: unsetenv VARIABLE\n";
			write(2, b_msg, _strlen(b_msg));
		}
	}
}
