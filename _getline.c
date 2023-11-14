#include "shell.h"

/**
 * _getline - Custom getline function.
 * @line_buff: Pointer to the buffer where the line will be stored.
 * Return: The number of bytes read (including newline), or End-of-file (EOF) if there's
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
	while (buff_size > 0)
	{
		if (buff[line_len] == '\n')
			break;
		line_len++;
	}
	*line_buff = malloc(line_len + 1);
	if (*line_buff == NULL)
	{
		perror("malloc");
		exit(1);
	}
	if (line_len > 0)
	{
		for (i = 0; i < line_len; i++)
			(*line_buff)[i] = buff[i];
		(*line_buff)[line_len] = '\0';
	}
	if (buff_size - line_len - 1 > 0)
	{
		buff_size -= (line_len + 1);
		memmove(buff, buff + line_len + 1, buff_size);
	}
	else
		buff_size = 0;
	return (line_len);
}
