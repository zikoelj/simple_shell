#include "shell.h"

/**
 * path_tok - Function that tokenizes the path
 * @command: command
 * @full_path: The path
 * @path_copy: copy of the path
 * Return: always 0
*/
int path_tok(char *command, char **full_path, char *path_copy)
{
	size_t command_len = _strlen(command);
	size_t full_path_len;
	size_t token_len;
	char *token;

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		token_len = _strlen(token);
		full_path_len = token_len + command_len + 2;

		*full_path = malloc(full_path_len * sizeof(char));
		if (*full_path == NULL)
		{
			perror("Failed to allocate memory");
			free(path_copy);
			return (0);
		}

		_strcpy(*full_path, token);
		(*full_path)[token_len] = '/';
		_strcpy(*full_path + token_len + 1, command);

		if (access(*full_path, X_OK) == 0)
			break;

		free(*full_path);
		*full_path = NULL;
		token = strtok(NULL, ":");
	}
	return (0);
}

/**
 * path - Function that finds the full path of a command
 * @command: Pointer to the command
 * @full_path: Pointer to store the full path of the command
 * Return: 1 on success, 0 if command not found
 */
int path(char *command, char **full_path)
{
	char *path = _getenv("PATH");
	size_t path_len = _strlen(path);

	char *path_copy = malloc((path_len + 1) * sizeof(char));

	if (path_copy == NULL)
	{
		perror("Failed to allocate memory");
		return (0);
	}

	_strcpy(path_copy, path);
	path_tok(command, full_path, path_copy);

	free(path_copy);

	if (*full_path == NULL)
		return (0);

	return (1);
}
