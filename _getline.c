#include "shell.h"

/**
 * _getline - Custom getline function.
 * @line_buff: Pointer to the buffer where the line will be stored.
 * Return: The number of bytes read (including newline), or EOF if there's
 * an error or end of file is reached.
 */
ssize_t _getline(char **line_buff)
{
	static ssize_t buff_size = -1;
	static char buff[BUFFER];
	ssize_t line_len = 0;
	ssize_t i;

	if (buff_size <= 0 || buff[buff_size - 1] == '\0')
	{
		buff_size = read(STDIN_FILENO, buff, BUFFER);
		if (buff_size < 0)
			return (buff_size);
		else if (buff_size == 0)
			return (EOF);
	}
	while (buff_size > 0 && buff[line_len] != '\n')
		line_len++;

	*line_buff = malloc(line_len + 1);
	if (*line_buff == NULL)
	{
		perror("malloc");
		exit(1);
	}
	for (i = 0; i < line_len; i++)
		(*line_buff)[i] = buff[i];
	(*line_buff)[line_len] = '\0';

	buff_size -= (line_len + 1);
	for (i = 0; i < buff_size; i++)
	{
		buff[i] = buff[line_len + i];
	}
	return (line_len);
}
