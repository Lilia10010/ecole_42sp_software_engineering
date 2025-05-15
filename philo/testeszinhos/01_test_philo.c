#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

pthread_mutex_t fork01;
pthread_mutex_t fork02;

long timestamp_ms()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000L) + (tv.tv_usec * 1000L));
}

void log_status_philo(int id, const char *status)
{
	printf("%ldms Filósofo %d %s\n", timestamp_ms(), id, status);
}

void *fisolopho(void *arg)
{
	int id = *(int *)arg;

	while(1)
	{
		log_status_philo(id, "está pensando cricricri 🤔");
		usleep(500000);

		log_status_philo(id, "tentando pegar o garfo 1 🥢");
		usleep(500000);

		log_status_philo(id,  "pegou o garfo 01");
		usleep(100000); //pausinha antes de pegar o segundo gaufo

		log_status_philo(id, "tentando pegar o garfo 02");
		pthread_mutex_lock(&fork02);

		log_status_philo(id, "pegou o garfo 02 e esta a comer 🍝");
		usleep(500000);

		pthread_mutex_unlock(&fork02);
		log_status_philo(id, "soltou o garfo 02");

		pthread_mutex_unlock(&fork01);
		log_status_philo(id, "soltou o garfo 01");

		log_status_philo(id, "esta dormindo 😴");
		usleep(300000);
	}
	return (NULL);
}

int main()
{
	pthread_t f1, f2;
	int id01 = 1;
	int id02 = 2;

	pthread_mutex_init(&fork01, NULL);
	pthread_mutex_init(&fork02, NULL);

	pthread_create(&f1, NULL, fisolopho, &id01);
	pthread_create(&f2, NULL, fisolopho, &id02);

	pthread_join(f1, NULL);
	pthread_join(f2, NULL);

	pthread_mutex_destroy(&fork01);
	pthread_mutex_destroy(&fork02);

	return (0);
}