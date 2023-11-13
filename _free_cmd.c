#include "shell.h"

/**
 * free_commands - Memories are freely allocated for an array of strings
 * @commands: It commands the  array of strings to be freed
 */

void free_commands(char **commands)
{
	int i = 0;

	while (commands[i] != NULL)
	{
		free(commands[i]);
		i++;
	}
	free(commands);
}
