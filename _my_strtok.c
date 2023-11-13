#include "shell.h"

/**
 * my_strtoken - Extract tokens from a string based on a set of delimiters.
 * @string: The string to tokenize.
 * @target: The set of delimiter characters.
 *
 * Return: The extracted token, or NULL if no more tokens are available.
 */
char *my_strtoken(char *string, const char *target)
{
	static char *n_token;
	size_t i;
	size_t target_len;
	char *token;
	char *targ_pos;

	if (string != NULL)
		n_token = string;

	if (n_token == NULL || *n_token == '\0')
		return (NULL);

	target_len = strlen(target);
	token = n_token;
	targ_pos = NULL;

	while (*n_token != '\0')
	{
		for (i = 0; i < target_len; i++)
		{
			if (*n_token == target[i])
			{
				targ_pos = n_token;
				break;
			}
		}
		if (targ_pos != NULL)
		{
			*targ_pos = '\0';
			n_token = targ_pos + 1;
			return (token);
		}
		n_token++;
	}
	n_token = NULL;
	return (token);
}
