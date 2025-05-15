#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char **argv, char **env)
{
	if (argc != 5)
	{
		fprintf(stderr, "Uso: %s <comando_a_ser_executado (ls)> <arg1> <arg2> ..\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	//apenas para testing
	int i = 0;
	while(env[i] != NULL)
	{
		printf("env[%d]: %s\n", i, env[i]);
		++i;
	}

	pid_t pid;

	pid = fork();

	//tratar erro do fork
	if (pid < 0)
	{
		perror("Erro ao criar processo filhote");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		//execve(const char *pathname, char *const argv[], char *const envp[]);
		/* execve("/caminho/invalido", &argv[1], env); */ //implicar error
		execve(argv[1], &argv[1], env);
		perror("Error ao executar execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		int status;
		wait(&status);
		printf("Status do filhote: %d\n", WEXITSTATUS(status));
	}

	return (0);
}


//./test /bin/ls -l
