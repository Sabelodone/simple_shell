#ifndef MAIN_H
#define MAIN_H

/*Libraries*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

/*Global variable decleration and MICROS*/
extern char **environ;
#define DELIM " \t\r\a\n"
#define RECIEVEDSIG 0
#define MAX_STR_IN 20
#define BUFFER 1024
#define PROMPT "cisfun$ "

/*Functions prototypes*/
void non_interactive(void);
void interactive(char **av);
pid_t exe(char **argv, char **av);
char *search_path(const char *input);
void shell_exit(char **av);
void display_env(char *av[]);
ssize_t _getline(char *str, size_t index, int stream);
char *_memcpy(char *dest, char *src, unsigned int n);
int _strlen(const char *s);

#endif
