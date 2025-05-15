#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>


long get_timestamp_ms()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	/* clock tem uma maior precisao
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec * 1000L) + (ts.tv_nsec / 1000000L);
	*/
	
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

int main(void)
{
	long start = get_timestamp_ms();
	printf("Tempo inicial %d ms\n", start);
	usleep(500000); //500ms
	long end = get_timestamp_ms();
	printf("Tempo decorridis %d ms\n", end - start);
	printf("Tempo atual %d ms\n", end);

	return (0);
}

/*
💡

    Se for usado usleep(1000) (1 ms), o sistema pode te dar um delay maior por causa do granularity do agendador de processos. Em geral, é mais seguro trabalhar com valores de 5ms ou mais!
*/