/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:25 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/01/20 23:58:53 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_child(int *pipes, int prev_pipe, t_pipex *pipex, int is_last)
{
	dup2(prev_pipe, STDIN_FILENO);
	if (is_last)
		dup2(pipex->file_out, STDOUT_FILENO);
	else
		dup2(pipes[1], STDOUT_FILENO);
	close(pipes[0]);
	close(pipes[1]);
	if (prev_pipe != pipex->file_in)
		close(prev_pipe);
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
		{
			process_child(pipes, prev_pipe, pipex, i == pipex->argc - 4);
			execute_command(pipex->argv[i + 2], pipex->envp);
		}
		close(prev_pipe);
		close(pipes[1]);
		prev_pipe = pipes[0];
		++i;
	}
}

void	pipex(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	pipex.argc = argc;
	pipex.argv = argv;
	pipex.envp = envp;
	pipex.file_in = open(argv[1], O_RDONLY);
	if (pipex.file_in < 0)
	{
		error_exit("Error: open output file");
	}
	pipex.file_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (pipex.file_out < 0)
		error_exit("Error: open output file");
	process_commands(&pipex);
	while (wait(NULL) > 0)
		;
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 ... cmdN outfile\n", 49);
		return (1);
	}
	pipex(argc, argv, envp);
	return (0);
}
