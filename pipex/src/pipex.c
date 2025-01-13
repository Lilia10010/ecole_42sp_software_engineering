#include "../include/pipex.h"
char    *get_command_path(char *command, char **envp)
{
    char    *path_env;
    char    **paths;
    char    *full_path;
    size_t  i;

    // Procurar a variável PATH nas variáveis de ambiente
    while (*envp)
    {
        if (strncmp(*envp, "PATH=", 5) == 0)
        {
            path_env = *envp + 5; // Ignorar o prefixo "PATH="
            break;
        }
        envp++;
    }

    if (!path_env)
        return (NULL); // Retorna NULL se PATH não for encontrado

    // Dividir a variável PATH em um array de strings (usando ':')
    paths = ft_split(path_env, ':'); // Use sua implementação de ft_split

    i = 0;
    while (paths[i])
    {
        // Construir o caminho completo do comando
        full_path = malloc(strlen(paths[i]) + strlen(command) + 2); // 1 para '/' e 1 para '\0'
        if (!full_path)
            return (NULL); // Retorna NULL se malloc falhar
        sprintf(full_path, "%s/%s", paths[i], command);

        // Verificar se o comando é executável
        if (access(full_path, X_OK) == 0)
        {
            // Libera os caminhos restantes e retorna o caminho encontrado
            while (paths[i])
                free(paths[i++]);
            free(paths);
            return (full_path);
        }
        free(full_path);
        i++;
    }

    // Libera os caminhos e retorna NULL se o comando não for encontrado
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

void    execute_command(char *cmd, char **envp)
{
    char    **args = ft_split(cmd, ' '); // Assuming you have ft_split implemented
    char    *path = get_command_path(args[0], envp); // Function to find the full path of the command

    if (!path)
        error_exit("Command not found");
    execve(path, args, envp);
    perror("execve");
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv, char **envp)
{
    int     infile, outfile, pipefd[2];
    pid_t   pid1, pid2;

    if (argc != 5)
        error_exit("Usage: ./pipex file1 cmd1 cmd2 file2");

    infile = open(argv[1], O_RDONLY);
    if (infile < 0)
        error_exit("Error opening file1");

    outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile < 0)
        error_exit("Error opening file2");

    if (pipe(pipefd) < 0)
        error_exit("Pipe failed");

    pid1 = fork();
    if (pid1 < 0)
        error_exit("Fork failed");

    if (pid1 == 0)
    {
        // Child process 1: Handle cmd1
        dup2(infile, STDIN_FILENO);  // Redirect input to file1
        dup2(pipefd[1], STDOUT_FILENO); // Redirect output to pipe
        close(pipefd[0]); // Close unused read end of pipe
        execute_command(argv[2], envp); // Execute cmd1
    }

    pid2 = fork();
    if (pid2 < 0)
        error_exit("Fork failed");

    if (pid2 == 0)
    {
        // Child process 2: Handle cmd2
        dup2(pipefd[0], STDIN_FILENO); // Redirect input from pipe
        dup2(outfile, STDOUT_FILENO); // Redirect output to file2
        close(pipefd[1]); // Close unused write end of pipe
        execute_command(argv[3], envp); // Execute cmd2
    }

    // Parent process: Close file descriptors and wait for children
    close(pipefd[0]);
    close(pipefd[1]);
    close(infile);
    close(outfile);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return (0);
}
