/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:25 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/01/24 19:23:13 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	process_child(int *pipes, int prev_pipe, t_pipex *pipex, int is_last)
{
	if (!is_last)
		dup2(pipes[1], STDOUT_FILENO);
	else 
		dup2(pipex->file_out, STDOUT_FILENO);

	dup2(prev_pipe, STDIN_FILENO);

	close(pipes[0]);
	close(pipes[1]);
	if (prev_pipe != pipex->file_in)
		close(prev_pipe);

}

void	process_commands(t_pipex *pipex)
{
	int	i;
	int	pipes[2];
	int	prev_pipe;
	pid_t pid;

	prev_pipe = pipex->file_in;
	i = 0;
	while (i < pipex->argc - 3)
	{
		if (pipe(pipes) < 0)
			error_exit("Error pipe creation failed");
		pid = fork();
		if (pid < 0)
			error_exit("Error fork failed");
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
	pipex->last_pid = pid;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex;

	if (argc == 5)
	{
		pipex.argc = argc;
		pipex.argv = argv;
		pipex.envp = envp;

		pipex.file_out = open(argv[argc -1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (pipex.file_out < 0)
			error_exit("Error failed to open output file");
		pipex.file_in = open(argv[1], O_RDONLY);
		if (pipex.file_in < 0)
			error_exit("Error failed to open input file");

		process_commands(&pipex);

		if (waitpid(pipex.last_pid, NULL, 0) == -1)
			error_exit("Error waitpid failed");

		close(pipex.file_out);
		close(pipex.file_in);
	}
	else
	{
		ft_putstr_fd("\033[31mError: Invalid arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex infile \"cat\" \"grep test\" outfile\n", 1);
	}


	return (0);
}


