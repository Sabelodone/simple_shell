#include "main.h"

/**
 * interactive - Run the shell in interactive mode.
 * @av: The argument vector containing the program name and its arguments.
 *
 * Description: This function runs the shell in interactive mode,
 */

void interactive(char **av)
{
	char *input = NULL, *argv[MAX_STR_IN] = {NULL, NULL};
	int i;
	size_t buffer = 0;
	ssize_t _chars;
	(void)av;

	while(1)
	{
		printf("%s", PROMPT);
		_chars = getline(&input, &buffer, stdin);
		if (_chars < 0 || input == NULL)
			break;

		input[strcspn(input, "\n")] = '\0';

		argv[0] = strtok(input, " ");
		
		for(i = 0; argv[i] != NULL; i++)
		{
			argv[++i] = strtok(NULL, " ");
		}

		/*display_env(argv);*/

		if (exe(argv, av) == -1)
		{
			free(input);
			exit(1);
		}
		/*free(input);
		input = NULL;*/
	}
	free(input);
	input = NULL;
}
