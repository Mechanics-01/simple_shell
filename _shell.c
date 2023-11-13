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

	while (true)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("%s", prompt);
			fflush(stdout);
		}
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
		if (strcmp(line_buff, "exit") == 0)
			break;
		else if (strcmp(line_buff, "env") == 0)
			env(envp);
		else
			exe_comd(line_buff, av);
		free(line_buff);

	}
	return (0);
}
