#include "main.h"

/**
 * shell_exit - Wait for a child process to terminate and handle exit status.
 * @pid: The process ID of the child process.
 * @av: The argument vector containing the program name and its arguments.
 *
 * Description: Waits for the child process with the given PID to terminate
 *              and retrieves its exit status. If the child process has exited
 *              successfully (with exit code 0) and the program name in the
 *              argument vector is NULL, it will also call exit(0) to terminate
 *              the parent process.
 */

void shell_exit(pid_t pid, char **av)
{
	int state, exit_state;

	waitpid(pid, &state, 0);
	if (WIFEXITED(state))
	{
		exit_state = WEXITSTATUS(state);
		if (exit_state == 0 && av[0] == NULL)
		{
			exit(0);
		}
	}
}
