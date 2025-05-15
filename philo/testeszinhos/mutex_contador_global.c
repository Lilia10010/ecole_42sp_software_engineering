#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUM_THREADS 3
#define NUM_INCREMENT 1000000

int count = 0;
pthread_mutex_t lock;

void *increment(void *arg)
{
	int i = 0;
	while (i < NUM_INCREMENT)
	{
		pthread_mutex_lock(&lock);
		++count;
		pthread_mutex_unlock(&lock);
		++i;
	}
	return (NULL);
}

int main(void)
{
	pthread_t threads[NUM_THREADS];

	pthread_mutex_init(&lock, NULL);

	for (int i = 0; i < NUM_THREADS; i++)
	{
		if(pthread_create(&threads[i], NULL, increment, NULL) !=0)
		{
			perror("Failed to create thread");
			exit(1);
		}
	}

	for (int i = 0; i < NUM_THREADS; i++)
		pthread_join(threads[i], NULL);

	pthread_mutex_destroy(&lock);
	printf("Total count: %d", count);
	
	return (0);
}