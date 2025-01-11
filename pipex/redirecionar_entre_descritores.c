/* #include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int src_fd = open("origem.txt", O_RDONLY);
	int dest_fd = open("dest.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

	if (src_fd < 0 || dest_fd < 0)
	{
		perror("erro ao abrir file");
		return (1);
	}

	dup2(src_fd, dest_fd);

	close(src_fd);
	close(dest_fd);

	return (0);
} */


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUF_SIZE 1024

int main() {
    // Abre o arquivo de origem em modo de leitura
    int src_fd = open("origem.txt", O_RDONLY);
    // Abre o arquivo de destino em modo de escrita
    int dest_fd = open("destino.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (src_fd == -1 || dest_fd == -1) {
        perror("Erro ao abrir arquivos");
        return 1;
    }

    char buffer[BUF_SIZE];
    ssize_t bytes_read, bytes_written;

    // Lê o conteúdo do arquivo origem e escreve no destino
    while ((bytes_read = read(src_fd, buffer, BUF_SIZE)) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Erro ao escrever no arquivo de destino");
            close(src_fd);
            close(dest_fd);
            return 1;
        }
    }

    if (bytes_read == -1) {
        perror("Erro ao ler o arquivo de origem");
    }

    // Fecha os arquivos
    close(src_fd);
    close(dest_fd);

    return 0;
}
