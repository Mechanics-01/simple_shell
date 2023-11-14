#include "shell.h"

/**
 * parse_commands - Parse input string into an array of commands
 * @input: The input strings contains multiple commands
 * Return: An array of strings representing commands
 */
char **parse_commands(char *input)
{
	int i = 0;
	char *tok_str;
	char **commands = malloc(sizeof(char *) * 100);

	if (commands == NULL)
	{
		perror("malloc");
		exit(1);
	}

	tok_str = strtok(input, ";");
	while (tok_str != NULL)
	{
		commands[i++] = strdup(tok_str);
		tok_str = strtok(NULL, ";");
	}

	commands[i] = NULL;

	return (commands);
}
