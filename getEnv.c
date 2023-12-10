#include "shell.h"

/**
 * _getenv - Function that retrieves an environment variable
 * @nm: Name of the environment variable to retrieve
 * Return: Pointer to the value of the environment variable,
 *         or NULL if not found
 */
char *_getenv(const char *nm)
{

	size_t nm_len = _strlen1(nm);
	char **env;

	if (nm == NULL || environ == NULL)
		return (NULL);

	for (env = environ; *env != NULL; env++)
{
		if (_strncmp(nm, *env, nm_len) == 0 && (*env)[nm_len] == '=')
			return (&(*env)[nm_len + 1]);
	}

	return (NULL);
}
