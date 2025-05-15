#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

typedef struct s_trhreadArg
{
	int id;
	char *name;
} ThreadArg;

void *print_id(void *arg)
{
	ThreadArg *data = (ThreadArg *)arg; //converter void* para ThreadArg
	printf("Hello theread id: [%d] - name [%s]\n", data->id, data->name);
	return (NULL);
}

int main(void)
{
	pthread_t threads[NUM_THREADS];
	ThreadArg args[NUM_THREADS];

	char *names[] = {"Folinha", "Místico", "STL", "Fuego", "Ventania"};
	for (int i = 0; i < NUM_THREADS; i++)
	{
		args[i].id = i + 1;
		args[i].name = names[i];
		if(pthread_create(&threads[i], NULL, print_id, &args[i]) != 0)
			perror("Failed to create thread");
	}
	for (int i = 0; i < NUM_THREADS; i++)
		pthread_join(threads[i], NULL);

	printf("All threads completed!\n");
	return (0);
}