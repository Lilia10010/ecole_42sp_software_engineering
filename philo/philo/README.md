philosophers/
├── includes/
│ └── philo.h <- Header principal com structs e protótipos
├── src/
│ ├── main.c <- main, mallocs, joins
│ ├── init.c <- inicializações dos structs e variáveis
│ ├── routine.c <- rotina principal do filósofo
│ ├── utils.c <- funções utilitárias (get_time_ms, print, etc)
│ ├── monitor.c <- thread que verifica morte
│ └── forks.c <- funções de pegar e soltar garfos
├── Makefile

gcc deadlock.c -o deadlock -pthread
valgrind --tool=helgrind ./deadlock

helgrind é uma ferramenta do Valgrind que detecta problemas de concorrência em programas multithreaded. Ele pode ajudar a identificar:
Condições de corrida (race conditions).
Deadlocks (bloqueios mútuos entre threads).
Uso incorreto de mutexes.

Dica [porém é função proíbida segundo o pdf]:
Em vez de bloquear indefinidamente usar pthread_mutex_trylock

notas
[ ] se o tempo de comer for maior que o tempo de morrer, no codigo atual ele morre, verificar se realmente é para ele morrer ou se tem que criar alguma lógica para ser impedido de morrer quando este safado começar a comer
[ ] último parametro timestamp_in_ms X died

5 800 400 400
2 200 100 100
 ./philo 2 400 200 200 
