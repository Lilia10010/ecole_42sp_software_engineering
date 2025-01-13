#ifndef PIPE_H
#define PIPE_H

#include <stdio.h>
#include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../libft/libft.h"

void	print_hello(void);
void	print_error(const char *msg);

char    *get_command_path(char *command, char **envp);

#endif