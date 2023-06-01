#include <time.h>
#include <stdio.h>

#define N 1000000000
#define M 10000

int main() {
  int a;
  clock_t start = clock();
  #pragma omp parallel for schedule(static) num_threads(4)
  for(int i = 0; i < N; i++) {

  }
  clock_t end = clock();
  double elapsed_time = (end-start)/(double)CLOCKS_PER_SEC;
  printf("%f\n", elapsed_time);
  return 0;
}