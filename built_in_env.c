#include "main.h"

/**
 * display_env - Output the shell local environment details
 * @av: Array of arguments values
 */

void display_env(char *av[])
{
	char **env = environ;

	if (strcmp(av[0], "env") == 0)
	{
		while (*env)
		{
			if (*env)
				puts(*env);
			env++;
		}

	} else if (strcmp(av[0], "exit") == 0)
	{
		/*free()*/
		exit(0);
	}
	else
	{
		/*performs other instructions*/
	}
}
