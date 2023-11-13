#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#define BUFFER 1050
#define COMMAND_SIZE 100
extern char **environ;

int exe_comd(char *input, char *av[]);
char *location(char *path, char *arg);
char *get_loc(char *arg);
int env(char *envp[]);
ssize_t _getline(char **line_buff);
char *my_strtoken(char *string, const char *target);
void exec_env(char *argv[]);
void change_d(char *d);
char *_getenv(const char *name);
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
void free_commands(char **commands);
char **parse_commands(char *input);
void check_env(int env_index, int overwrite, char *new_env);
void path_exec(char *argv[], char *av[], char *input);

#endif/*SHELL_H*/
