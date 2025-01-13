#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
    paths = split(path_env, ':'); // Use sua implementação de split

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

int main(int argc, char **argv, char **envp)
{
    if (argc < 2)
    {
        printf("Usage: %s <command>\n", argv[0]);
        return (1);
    }

    char *path = get_command_path(argv[1], envp);
    if (path)
    {
        printf("Command path: %s\n", path);
        free(path); // Liberar a memória alocada para o caminho
    }
    else
    {
        printf("Command not found!\n");
    }
    return (0);
}
