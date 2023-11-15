#include "shell.h"

/**
 * exe_comd - It Execute a command
 * @input: The command input
 * @av: The array of arguments
 * Return: 0 on success, -1 on failure
 */
int exe_comd(char *input, char *av[])
{
	int i = 0;
	char **commands = parse_commands(input);

	while (commands[i] != NULL)
	{
		char *command = commands[i];
		char *argv[100];
		int j = 0, exit_s = 0;
		char *tok_str = strtok(command, " ");

		if (tok_str == NULL)
		{
			i++;
			continue;
		}

		break_exec(argv, tok_str, j, exit_s);

		if ((_strcmp(argv[0], "setenv") == 0) ||
		(_strcmp(argv[0], "unsetenv") == 0))
		{
			exec_env(argv);
			i++;
			continue;
		}
		else if (_strcmp(argv[0], "cd") == 0)
		{
			change_d(argv[1]);
			i++;
			continue;
		}
		path_exec(argv, av, input);
		i++;
	}
	free(commands);
	return (0);
}

/**
 * break_exec - Breaks down the command string
 * into arguments and handles exit
 * @argv: The array to store command arguments
 * @tok_str: The command string to break down
 * @j: Index to keep track of arguments
 * @exit_s: Exit status variable
 */
void break_exec(char *argv[], char *tok_str, int j, int exit_s)
{
	while (tok_str != NULL)
	{
		argv[j++] = tok_str;
		tok_str = strtok(NULL, " ");
	}
	argv[j] = NULL;

	if (_strcmp(argv[0], "exit") == 0 && argv[1] != NULL)
	{
		exit_s = _atoi(argv[1]);
		exit(exit_s);
	}
}


/**
 * path_exec - Execute a command with the provided path
 * @argv: The array of command arguments
 * @av: The array of program arguments
 * @input: The input command string
 */
void path_exec(char *argv[], char *av[], char *input)
{
	pid_t c_pid;
	int status;
	char *path = get_loc(argv[0]);

	if (path != NULL)
	{
		c_pid = fork();
		if (c_pid == -1)
		{
			perror("fork");
			free(input);
			exit(1);
		}

		if (c_pid == 0)
		{
			if (execve(path, argv, NULL) == -1)
			{
				perror(av[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			waitpid(c_pid, &status, 0);
			free(path);
		}
	}
	else
	{
		if (isatty(STDIN_FILENO) == 0)
		{
			fprintf(stderr, "%s: %d: %s: %s\n", av[0], 1, argv[0], "not found");
			_exit(127);
		}
		perror(av[0]);
	}
}
