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
	/*char *path_cmd, *ext = "exit";*/
	int status = 0;
	pid_t id = fork();

	if (id == -1)
		return (id);

	if (id == 0)
	{
		/*if (strcmp(argv[0], ext) == 0)
			shell_exit(id, argv);*/
		/*else*/
		/*{*/
			/*th_cmd = search_path(argv[0]);
			if (path_cmd == NULL)
			{
				perror(av[0]);
				exit(1);
			}*/
			if (execve(argv[0],/*path_cmd*/argv, NULL) == -1)
			{
				perror(av[0]);
				exit(1);
			}
		/*}*/
		/*free(path_cmd);*/
		/*path_cmd = NULL;*/
	}
	else
	{
		wait(&status);
	}
	 return (id);
}
