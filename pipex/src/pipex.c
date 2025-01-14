/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:25 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/01/13 23:33:39 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char    *get_command_path(char *command, char **envp)
{
    char    *path_env;
    char    **paths;
    char    *full_path;
    size_t  i;

    while (*envp)
    {
        if (strncmp(*envp, "PATH=", 5) == 0)
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
void    error_exit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

/* void    execute_command(char *cmd, char **envp)
{
    char    **args = ft_split(cmd, ' ');
    char    *path = get_command_path(args[0], envp); 
    if (!path)
        error_exit("Command not found");
    execve(path, args, envp);
    perror("execve");
    exit(EXIT_FAILURE);
} */

void    execute_process(char **argv, char **envp, int *fd)
{
	int     file;
	char    **args;
	char    *path;

	file = open(argv[1], O_RDONLY, 0777);
	if (file < 0)
		error_exit("error: open fd");
	dup2(fd[1], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close(fd[0]);
	args = ft_split(argv[2], ' ');
	path = get_command_path(args[0], envp);
	if (!path)
		error_exit("Command not found");
	execve(path, args, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv, char **envp)
{
	int fd[2];
	pid_t pid1;

	if (argc == 5)
	{
		if (pipe(fd) < 0)
			error_exit("error: pipe");
		pid1 = fork();
		if (pid1 < 0)
			error_exit("error: forking");
		if (pid1 == 0)
			execute_process(argv, envp, fd)
		waitpid(pid1, NULL, 0);
		execute_process(argv, envp, fd);	
	}
	
	return (0);
}
