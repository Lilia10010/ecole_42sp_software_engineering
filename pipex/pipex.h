# ifndef PIPE_H
# define PIPE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

// funções auxiliares (colocar na utils)
void error_exit(const char *msg);
void free_paths(char **paths);
char *find_executable_path(char **paths, char *cmd);
char *get_command_path(char *cmd, char **envp);
void execute_command(char *cmd, char **envp);

// funções principais
void process_child(int *pipes, int prev_pipe, int file_in, int file_out, int is_last_command);
void process_commands(int argc, char **argv, char **envp, int file_in, int file_out);
void pipex(int argc, char **argv, char **envp);

# endif