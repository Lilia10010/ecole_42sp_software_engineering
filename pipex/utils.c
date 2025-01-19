/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:19:25 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/01/19 17:13:35 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex.h"

//mover p utils
void error_exit(const char *msg)
{
	printf("Error: %s\n", msg);
    perror(msg);
    exit(EXIT_FAILURE);
}

void free_paths(char **paths)
{
	int i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char *find_executable_path(char **paths, char *cmd)
{
    char *part_path;
    char *full_path;
    int i;

	i = 0;
    while (paths[i])
    {
        part_path = ft_strjoin(paths[i], "/");
        if (!part_path)
            return (NULL);

        full_path = ft_strjoin(part_path, cmd);
        free(part_path);

        if (!full_path)
            return (NULL);

        if (access(full_path, F_OK) == 0) //x verifica se é executável f verifica a existência
            return (full_path);

        free(full_path);
		++i;
    }

    return (NULL);
}


char *get_command_path(char *cmd, char **envp)
{
    char **paths;
    char *path;
    int i;

    i = 0;
    while (ft_strnstr(envp[i], "PATH", 4) == 0)
        i++;

    paths = ft_split(envp[i] + 5, ':');
    if (!paths)
        return (NULL);

    path = find_executable_path(paths, cmd);
    free_paths(paths);
    return (path);
}



void execute_command(char *cmd, char **envp)
{
    char **args = ft_split(cmd, ' ');
    char *path = get_command_path(args[0], envp);
    if (!path)
	{
        error_exit("Command not found =>");

	}
    execve(path, args, envp);
    perror("execve");
    exit(EXIT_FAILURE);
}