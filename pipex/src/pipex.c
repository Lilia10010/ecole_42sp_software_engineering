/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:25 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/01/17 18:12:16 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/pipex.h"

void error_exit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

char *get_command_path(char *command, char **envp)
{
    char *path_env;
    char **paths;
    char *full_path;
    size_t i;

    while (*envp)
    {
        if (ft_strncmp(*envp, "PATH=", 5) == 0)
        {
            path_env = *envp + 5;
            break;
        }
        ++envp;
    }
    if (!path_env)
        return (NULL);

    paths = ft_split(path_env, ':');
    i = 0;
    while (paths[i])
    {
        full_path = malloc(strlen(paths[i]) + strlen(command) + 2);
        if (!full_path)
            return (NULL);
        sprintf(full_path, "%s/%s", paths[i], command);
        if (access(full_path, X_OK) == 0)
        {
            while (paths[i])
                free(paths[i++]);
            free(paths);
            return (full_path);
        }
        free(full_path);
        i++;
    }
    i = 0;
    while (paths[i])
        free(paths[i++]);
    free(paths);
    return (NULL);
}

void execute_command(char *cmd, char **envp)
{
    char **args = ft_split(cmd, ' ');
    char *path = get_command_path(args[0], envp);
    if (!path)
        error_exit("Command not found");
    execve(path, args, envp);
    perror("execve");
    exit(EXIT_FAILURE);
}

void process_commands(int argc, char **argv, char **envp, int file_in, int file_out)
{
	int i;
	int pipes[2];
	pid_t pid;
	int prev_pipe;
	
	prev_pipe = file_in;
	i = 0;
	while (i < argc - 3)
	{
		if(pipe(pipes) < 0)
			error_exit("Error: pipe");
		pid = fork();
		if (pid < 0)
			error_exit("Error: fork");
		if (pid == 0)
		{
			dup2(prev_pipe, STDIN_FILENO);
			if (i < argc - 4)
				dup2(pipes[1], STDOUT_FILENO);
			else
				dup2(file_out, STDOUT_FILENO);

			close(pipes[0]);
			close(pipes[1]);
			if (prev_pipe != file_in)
				close(prev_pipe);
			execute_command(argv[i + 2], envp);
		}
		close(prev_pipe);
		close(pipes[1]);
		prev_pipe = pipes[0]; // resetar p/ leitura
		++i;
	}
}

void setup_pipex(int argc, char **argv, char **envp)
{
    int file_in, file_out;

    file_in = open(argv[1], O_RDONLY);
    if (file_in < 0)
        error_exit("Error: open input file");
    file_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (file_out < 0)
        error_exit("Error: open output file");

    //para cada comando intermediário


	process_commands(argc, argv, envp, file_in, file_out);
    /* while(i < argc - 3)
    {
        if (pipe(pipes) < 0)
            error_exit("Error: pipe");
        pid = fork();
        if (pid < 0)
            error_exit("Error: fork");
        if (pid == 0) // Child process
        {
            dup2(prev_pipe, STDIN_FILENO);
            if (i < argc - 4)
                dup2(pipes[1], STDOUT_FILENO); // se não for o último comando, redireciona a saída para o pipe
            else
                dup2(file_out, STDOUT_FILENO); //se for o ultimo comando, redireciona a saída para o arquivo

            close(pipes[0]);
            close(pipes[1]);
            if (prev_pipe != file_in)
                close(prev_pipe);

            execute_command(argv[i + 2], envp);
        }

        close(prev_pipe);
        close(pipes[1]);
        prev_pipe = pipes[0]; // resetar p/ (leitura)
		++i;
    } */

    // Wait for all child processes
    while (wait(NULL) > 0);
}

int main(int argc, char **argv, char **envp)
{
    if (argc < 5)
    {
        write(2, "Usage: ./pipex infile cmd1 cmd2 ... cmdN outfile\n", 49);
        return (1);
    }
    setup_pipex(argc, argv, envp);
    return (0);
}
