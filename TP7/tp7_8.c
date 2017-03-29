/**************************************
 * pthread-philo-sem.c
 *
 * Programme d'exemple de pthread avec
 * philosophes qui dinent et sÃ©maphores
 *
 **************************************/

///AAA
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define PHILOSOPHES 3

pthread_t phil[PHILOSOPHES];
sem_t baguette[PHILOSOPHES];


pthread_t evolution; 

void mange(int id) {
  printf("Philosophe [%d] mange\n",id);
  for(int i=0;i< rand(); i++) {
    // philosophe mange
  }
}

void* philosophe ( void* arg )
{
  int *id=(int *) arg;
  int left = *id;
  int right = (left + 1) % PHILOSOPHES;
  while(true) {
    printf("Philosophe [%d] pense\n",*id);
    sem_wait(&baguette[left]);
    printf("Philosophe [%d] possÃ¨de baguette gauche [%d]\n",*id,left);
    sem_wait(&baguette[right]);
    printf("Philosophe [%d] possÃ¨de baguette droite [%d]\n",*id,right);
    mange(*id);
    sem_post(&baguette[left]);
    printf("Philosophe [%d] a libÃ©rÃ© baguette gauche [%d]\n",*id,left);
    sem_post(&baguette[right]);
    printf("Philosophe [%d] a libÃ©rÃ© baguette droite [%d]\n",*id,right);
  }
  return (NULL);
}
///BBB
int main ( int argc, char *argv[])
{
   long i;
   int id[PHILOSOPHES];

   srand(getpid());

   for (i = 0; i < PHILOSOPHES; i++)
     id[i]=i;

   for (i = 0; i < PHILOSOPHES; i++)
     sem_init( &baguette[i], 0 , 1);

   for (i = 0; i < PHILOSOPHES; i++)
     pthread_create(&phil[i], NULL, philosophe, (void*)&(id[i]) );

   for (i = 0; i < PHILOSOPHES; i++)
      pthread_join(phil[i], NULL);

   return (EXIT_SUCCESS);
}
