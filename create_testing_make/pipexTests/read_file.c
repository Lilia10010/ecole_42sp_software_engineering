#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

    int input_fd = open("entrada.txt", O_RDONLY);
    if (input_fd < -1) {
        perror("Erro ao abrir arquivo");
        return 1;
    }


    dup2(input_fd, STDIN_FILENO);
    close(input_fd); 

	
    // Lê da entrada padrão (agora redirecionada para o arquivo)
    char buffer[100];
    fgets(buffer, sizeof(buffer), stdin);

    // Mostra o conteúdo lido
    printf("Conteúdo lido: %s", buffer);

    return 0;
}
