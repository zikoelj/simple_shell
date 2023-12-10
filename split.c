#include "shell.h"

/**
 * split - Function that splits a string into tokens
 * @line: Pointer to the string
 * Return: Array of tokens
 */
char **split(char *line)
{
	char *tok;
	char **toks = malloc(100 * sizeof(char *));
	int i = 0;
	int is_tok = 0;

	if (!toks)
	{
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	tok = strtok(line, " \t\n");
	if (tok == NULL)
	{
		free(toks);
		return (NULL);
	}

	while (tok != NULL && i < 99)
	{
		if (is_tok == 0 && tok[0] == ' ')
		{
			tok = strtok(NULL, " \t\n");
			continue;
		}
		toks[i] = tok;
		tok = strtok(NULL, " \t\n");
		i++;
		is_tok = 1;
	}
	toks[i] = NULL;

	if (i >= 99)
	{
		free(toks);
		return (NULL);
	}

	return (toks);
}
