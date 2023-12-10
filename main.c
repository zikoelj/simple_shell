#include "shell.h"
/**
 * main - main function of the program
 * @argc: the number of arguments
 * @argv: the arguments
 * @envrp: the environment
 * Return: Integer type
 */
int main(int argc, char **argv, char **envrp)
{
	int fd = STDIN_FILENO;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
				exit(127);
			return (EXIT_FAILURE);
		}
	}
	signal(SIGINT, hundle_ctrl);

	prompt(argv, envrp);

	if (fd != STDIN_FILENO)
		close(fd);

	return (0);
}
