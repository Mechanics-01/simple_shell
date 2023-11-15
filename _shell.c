#include "shell.h"
/**
 * main - Entry point for the shell program
 * @ac: The number of arguments
 * @av: The array of arguments
 * @envp: The environment variables
 * Return: 0 on success, -1 on failure
 */
int main(int ac, char *av[], char *envp[])
{
	ssize_t buff_out_len;
	char *prompt = "Shell$ ";
	char *line_buff = NULL;
	(void)ac;

	if (isatty(STDIN_FILENO))
	{
		while (true)
		{
			printf("%s", prompt);
			fflush(stdout);
			line_buff = malloc(BUFFER);
			if (line_buff == NULL)
			{
				perror("malloc");
				exit(1);
			}
			buff_out_len = _getline(&line_buff);
			if (buff_out_len == EOF)
			{
				free(line_buff);
				break;
			}
			if (buff_out_len == -1)
			{
				perror("getline");
				free(line_buff);
				exit(1);
			}
			check_buff(line_buff, av, envp);
			free(line_buff);
		}
	}
	else
		check_non_interactive(line_buff, ac, av, envp);
	return (0);
}

/**
 * check_non_interactive - Check and execute commands in non-interactive mode
 * @line_buff: Buffer containing the command line
 * @ac: Number of command line arguments
 * @av: The array of arguments
 * @envp: The environment variables
 */
void check_non_interactive(char *line_buff, int ac, char *av[], char *envp[])
{
	int fd;
	ssize_t line_len;

	line_buff = malloc(BUFFER);
	if (line_buff == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			perror("open");
			exit(EXIT_FAILURE);
		}
		dup2(fd, STDIN_FILENO);
		close(fd);
	}

	while ((_getline(&line_buff)) != -1)
	{
		line_len = _strlen(line_buff);
		if (line_len > 0 && line_buff[line_len - 1] == '\n')
		{
			line_buff[line_len - 1] = '\0';
		}
		check_buff(line_buff, av, envp);
	}

	free(line_buff);
}

/**
 * check_buff - Check and execute commands from buffer
 * @line_buff: Buffer containing the command line
 * @av: The array of arguments
 * @envp: The environment variables
 */
void check_buff(char *line_buff, char *av[], char *envp[])
{
	if (_strcmp(line_buff, "exit") == 0)
		exit(EXIT_SUCCESS);
	else if (_strcmp(line_buff, "env") == 0)
		env(envp);
	else
		exe_comd(line_buff, av);
}


