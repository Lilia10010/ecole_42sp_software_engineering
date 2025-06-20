/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:25 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/01/24 22:20:23 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_child(int *pipes, int prev_pipe, t_pipex *pipe, int index)
{
	int is_last_command;

	is_last_command = pipe->argc - 4 == index;
	dup2(prev_pipe, STDIN_FILENO);
	if (is_last_command)
		dup2(pipe->file_out, STDOUT_FILENO);
	else
		dup2(pipes[1], STDOUT_FILENO);
	close(pipes[0]);
	close(pipes[1]);
	if (prev_pipe != pipe->file_in)
		close(prev_pipe);
	execute_command(pipe->argv[index + 2], pipe->envp);
}

void	process_commands(t_pipex *pipex)
{
	int		i;
	int		pipes[2];
	pid_t	pid;
	int		prev_pipe;

	prev_pipe = pipex->file_in;
	i = 0;
	while (i < pipex->argc - 3)
	{
		if (pipe(pipes) < 0)
			error_exit("Error: pipe");
		pid = fork();
		if (pid < 0)
			error_exit("Error: fork");
		if (pid == 0)
			process_child(pipes, prev_pipe, pipex, i);
		close(prev_pipe);
		close(pipes[1]);
		prev_pipe = pipes[0];
		++i;
	}
	if (i == pipex->argc - 3)
		pipex->last_pid = pid;
}

void	pipex(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	pipex.argc = argc;
	pipex.argv = argv;
	pipex.envp = envp;
	pipex.file_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex.file_out < 0)
		error_exit("Error open output file");
	pipex.file_in = open(argv[1], O_RDONLY);
	if (pipex.file_in < 0)
	{
		error_exit("Error open infile");
	}
	process_commands(&pipex);
	if (waitpid(pipex.last_pid, &status, 0) == -1)
		error_exit("Error waitpid");
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
}

int	main(int argc, char **argv, char **envp)
{	
	if (argc < 5)
	{
		ft_putstr_fd("\033[31mError: Invalid arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex infile \"cat\" \"grep test\" outfile\n", 1);
		return (1);
	}
	pipex(argc, argv, envp);
	return (0);
}
