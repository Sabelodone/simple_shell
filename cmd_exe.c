#include "main.h"

/**
 * exe - Execute a command with arguments.
 * @argv: The argument vector containing the command and its arguments.
 * @av: The argument vector containing the program name and its arguments.
 *
 * Return: The process ID of the child created to execute the command.
 */

pid_t exe(char **argv, char **av)
{
	char *path_cmd;
	int state;
	pid_t id = fork();

	if (!argv)
		return (id);
	if (id == -1)
		return (id);
	else if (id == 0)
	{
		path_cmd = search_path(argv[0]);
		if (path_cmd == NULL)
		{
			perror(av[0]);
			exit(1);
		}
		if (execve(path_cmd, argv, NULL) == -1)
		{
			perror(av[0]);
			exit(1);
		}
		free(path_cmd);
		path_cmd = NULL;
	} else
	{
		wait(&state);
	}
	return (id);
}
