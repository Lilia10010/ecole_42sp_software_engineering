#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int error_fd = open("erros.log", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (error_fd < 0)
	{
		perror("error ao abrir arquivo");
		return (1);
	}

	dup2(error_fd, STDERR_FILENO);
	close(error_fd);

	fprintf(stderr, "error no error");

	return (0);
}