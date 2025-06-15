#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void redirect_stdout_to_file(const char *filename) {
    // Abre o arquivo para escrita (cria se não existir, trunca se já existir)
    int file_fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (file_fd == -1) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    // Redireciona o stdout para o arquivo
    if (dup2(file_fd, STDOUT_FILENO) == -1) {
        perror("Erro no dup2");
        close(file_fd);
        return;
    }

    // Agora qualquer printf vai para o arquivo
	printf("Bane no sistema alguém me desconfigurou")
	write(1, "ui\n", 3);

    // Fecha o descritor do arquivo (não precisamos dele após redirecionar)
    close(file_fd);

    // Verifica se stdout está funcionando corretamente
    printf("Esta mensagem também está no arquivo!\n");
}

int main(void) {

    const char *filename = "saida.txt";

    // Redireciona stdout para o arquivo
    redirect_stdout_to_file(filename);

    printf("fimm.\n");

    return (0);
}
