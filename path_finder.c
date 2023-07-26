#include "main.h"

/**
 * path_finder - Function allocates path to the input.
 * @str: The user inpute.
 * Return: The actual path of the inpute
 */

char *search_path(const char *str)
{
	char *path, *tok_path = NULL, *exact_path = NULL;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		tok_path = strtok(path, ":");
		while (tok_path != NULL)
		{
			exact_path = malloc(/*BUFFER*/strlen(tok_path) + strlen(str) + 2);
			if (exact_path == NULL)
			{
				/*perror("Memory alloc error");*/
				exit(1);
			}
			strcpy(exact_path, tok_path);
			strcat(exact_path, "/");
			strcat(exact_path, str);
			if (stat(exact_path, &buffer) == 0)
			{
				/*free(tok_path);
				tok_path = NULL;*/
				return (exact_path);
			}
			free(exact_path);
			exact_path = NULL;
			tok_path = strtok(NULL, ":");
		}
		if (stat(str, &buffer) == 0)
			return (strdup(str));
		return (NULL);
	}
	return (NULL);
}
