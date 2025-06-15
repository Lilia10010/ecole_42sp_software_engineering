/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 23:35:19 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/01/25 15:31:12 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include "../libft/libft.h"

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
	int		file_in;
	int		file_out;
	pid_t	last_pid;
}	t_pipex;

void	error_exit(const char *msg);
void	free_paths(char **paths);
char	*find_executable_path(char **paths, char *cmd);
char	*get_command_path(char *cmd, char **envp);
void	execute_command(char *cmd, char **envp);
void	process_child(int *pipes, int prev_pipe, t_pipex *pipe, int index);
void	process_commands(t_pipex *pipex);
void	pipex(int argc, char **argv, char **envp);

#endif