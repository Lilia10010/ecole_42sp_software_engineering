/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:25 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/01/14 20:32:09 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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
        envp++;
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

void error_exit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
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

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    pid_t pid1, pid2;
    int infile, outfile;

    if (argc < 5)
        error_exit("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile");

    infile = open(argv[1], O_RDONLY);
    if (infile < 0)
        error_exit("Error opening infile");

    outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (outfile < 0)
        error_exit("Error opening outfile");

    if (pipe(fd) < 0)
        error_exit("Error creating pipe");

    pid1 = fork();
    if (pid1 < 0)
        error_exit("Error forking process 1");
    if (pid1 == 0)
    {
        dup2(infile, STDIN_FILENO);  // Redirect infile to stdin
        dup2(fd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
        close(fd[0]);
        close(fd[1]);
        execute_command(argv[2], envp);
    }

    pid2 = fork();
    if (pid2 < 0)
        error_exit("Error forking process 2");
    if (pid2 == 0)
    {
        dup2(fd[0], STDIN_FILENO);  // Redirect pipe read end to stdin
        dup2(outfile, STDOUT_FILENO); // Redirect stdout to outfile
        close(fd[0]);
        close(fd[1]);
        execute_command(argv[3], envp);
    }

    close(fd[0]);
    close(fd[1]);
    close(infile);
    close(outfile);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return (0);
}
