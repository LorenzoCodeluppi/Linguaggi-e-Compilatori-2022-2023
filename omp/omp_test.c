#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 5
#define M 5

// aggiungo uno sleep all'interno del body per fare in modo che un'iterazione del loop
// sia in generale più costosa della generazione/gestione dei thread.
// la componente random è stata inserita per osservare variazioni in un contesto di schedulazione
// dynamic
int main() {
  const int MAX_WAIT = 4;
  srand(time(NULL)); 
  struct timespec start, finish;
  clock_gettime(CLOCK_REALTIME, &start);
  #pragma omp parallel for schedule(dynamic, 1) num_threads(4)
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < M; j++) {
      int random_sleep_time = (rand() % MAX_WAIT) + 1;
      sleep(random_sleep_time);
    }
  }
  clock_gettime(CLOCK_REALTIME, &finish);
  // tempo troncato ai secondi, non preciso ma comunque si ottiene una corretta approssimazione
  // dei tempi di esecuzione
  double elapsed_time = ((double) (finish.tv_sec - start.tv_sec));
  printf("%f\n", elapsed_time);
  return 0;
}