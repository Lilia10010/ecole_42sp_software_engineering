philo/
├── Makefile
├── main.c
├── philo.h
├── init.c
├── routine.c
├── time.c
└── utils.c

gcc deadlock.c -o deadlock -pthread
valgrind --tool=helgrind ./deadlock

helgrind é uma ferramenta do Valgrind que detecta problemas de concorrência em programas multithreaded. Ele pode ajudar a identificar:
Condições de corrida (race conditions).
Deadlocks (bloqueios mútuos entre threads).
Uso incorreto de mutexes.

Dica [porém é função proíbida segundo o pdf]:
Em vez de bloquear indefinidamente usar pthread_mutex_trylock
