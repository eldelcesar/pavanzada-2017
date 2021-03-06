#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <dispatch/dispatch.h>
#define NUM_THREADS 5

unsigned int total;
dispatch_semaphore_t forks[];

void thinking(int n) {
  sleep(rand()%n);
}

void eating(int n) {
  sleep(rand()%n);
}

void *lifeStyle(void *threadid){
  long tid;
  tid = (long)threadid;
  while (1) {
    thinking(3); //
    printf("I am phil %lu, I am hungry\n", tid); //
    dispatch_semaphore_wait(forks[tid], DISPATCH_TIME_FOREVER);
    dispatch_semaphore_wait(forks[(tid + 1)&NUM_THREADS], DISPATCH_TIME_FOREVER);
    eating(4); //
    printf("I am phil %lu, I am thinking\n", tid); //
    dispatch_semaphore_signal(forks[tid]);
    dispatch_semaphore_signal(forks[(tid + 1)&NUM_THREADS]);
  }

}

int main(int argc, char *argv[]){
  pthread_t threads[NUM_THREADS];
  int rc;
  long t;

  for (t = 0; t < NUM_THREADS; t++){
    forks[t] = dispatch_semaphore_create(1);
  }

  for (t = 0; t < NUM_THREADS; t++){
    printf("In main: creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, lifeStyle, (void *)t);
    if (rc)
    {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(-1);
    }
  }

  for (t = 0; t < NUM_THREADS; t++){
    pthread_join(threads[t], NULL);
  }

  printf("Final total = %d \n", total);
  /* Last thing that main() should do */
  pthread_exit(NULL);
}
