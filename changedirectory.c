#include "shell.h"
/**
 * cmd_if - Changes the current directory and updates environment variables
 * @argv: Array of arguments, where args[1] represents the directory path
 * Return: Void
 */
void cmd_if(char **argv)
{
	if (chdir(argv[1]) == -1)
		perror("cd");
	else
	{
		char chwd[PATH_MAX];

		if (getcwd(chwd, sizeof(chwd)) != NULL)
		{
			if (setenv("PWD", chwd, 1) == -1)
				perror("setenv");
			if (setenv("OLDPWD", argv[1], 1) == -1)
				perror("setenv");
		}
		else
		{
			perror("getcwd");
		}
	}
}

/**
 * cmd_cd - changes the current directory of the process
 * @argms: Array of arguments
 * Return: Void
 */
void cmd_cd(char **argms)
{
	char *path;

	if (argms[1] == NULL || (_strcmp(argms[1], "~") == 0))
	{
		path = _getenv("HOME");
		if (path == NULL)
		{
			perror("cd");
			return;
		}
	}
	else if (_strcmp(argms[1], "-") == 0)
	{
		path = _getenv("OLDPWD");
		if (path == NULL)
		{
			perror("cd");
			return;
		}
		printf("%s\n", path);
	}
	else
	{
		path = argms[1];
	}

	 cmd_if(argms);

}

