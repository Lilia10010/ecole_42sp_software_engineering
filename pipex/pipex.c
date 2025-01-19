/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:25 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/01/19 17:14:51 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

void process_child(int *pipes, int prev_pipe, int file_in, int file_out, int is_last_command)
{
	dup2(prev_pipe, STDIN_FILENO);
	if (is_last_command)
		dup2(file_out, STDOUT_FILENO);
	else
		dup2(pipes[1], STDOUT_FILENO);
	close(pipes[0]);
	close(pipes[1]);
	if (prev_pipe != file_in)
		close(prev_pipe);
}

void process_commands(int argc, char **argv, char **envp, int file_in, int file_out)
{
	int i;
	int pipes[2];
	pid_t pid;
	int prev_pipe;
	int is_last_command;
		
	prev_pipe = file_in;
	i = 0;
	while (i < argc - 3)
	{	
		is_last_command = i == argc - 4;
		if(pipe(pipes) < 0)
			error_exit("Error: pipe");
		pid = fork();
		if (pid < 0)
			error_exit("Error: fork");
		if (pid == 0)
		{
			process_child(pipes, prev_pipe, file_in, file_out, is_last_command);
			execute_command(argv[i + 2], envp);
		}
		close(prev_pipe);
		close(pipes[1]);
		prev_pipe = pipes[0]; // resetar p/ leitura
		++i;
	}
}

void pipex(int argc, char **argv, char **envp)
{
    int file_in;
	int file_out;

    file_in = open(argv[1], O_RDONLY);
    if (file_in < 0)
        error_exit("Error: open input file");
    file_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (file_out < 0)
		error_exit("Error: open output file");
	
	process_commands(argc, argv, envp, file_in, file_out);
    
    while (wait(NULL) > 0); //espera todos os processos
}

int main(int argc, char **argv, char **envp)
{
    if (argc < 5)
    {
        write(2, "Usage: ./pipex infile cmd1 cmd2 ... cmdN outfile\n", 49);
        return (1);
    }
    pipex(argc, argv, envp);
    return (0);
}
