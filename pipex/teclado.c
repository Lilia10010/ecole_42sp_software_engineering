#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    printf("Digite algo (será redirecionado para o arquivo):\n");

    // Abre um arquivo para redirecionar a entrada padrão
    int input_fd = open("entrada_teclado.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (input_fd == -1) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    // Salva o descritor original da entrada padrão
    int stdin_backup = dup(STDIN_FILENO);

    // Redireciona a entrada padrão para o arquivo
    dup2(input_fd, STDOUT_FILENO);
    close(input_fd);

    // Escreve no arquivo diretamente
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);

    // Restaura a entrada padrão original
    dup2(stdin_backup, STDIN_FILENO);
    close(stdin_backup);

    printf("Conteúdo redirecionado e gravado no arquivo.\n");
    return 0;
}
