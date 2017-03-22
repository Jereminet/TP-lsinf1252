/**************************************
 * pthread-philo.c
 *
 * Programme d'exemple de pthread avec
 * philosophes qui dinent et mutex
 *
 **************************************/

///valgrind --tool=helgrind ./tp6_4



/*
Thread #3: lock order "0x6020F0 before 0x6020C8" violated
Faire atention à l'ordre des threads pour éviter deadlock
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define PHILOSOPHES 3

pthread_t phil[PHILOSOPHES];
pthread_mutex_t baguette[PHILOSOPHES];

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
    pthread_mutex_lock(&baguette[left]);
    printf("Philosophe [%d] possÃ¨de baguette gauche [%d]\n",*id,left);
    pthread_mutex_lock(&baguette[right]);
    printf("Philosophe [%d] possÃ¨de baguette droite [%d]\n",*id,right);
    mange(*id);
    pthread_mutex_unlock(&baguette[left]);
    printf("Philosophe [%d] a libÃ©rÃ© baguette gauche [%d]\n",*id,left);
    pthread_mutex_unlock(&baguette[right]);
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
      pthread_mutex_init( &baguette[i], NULL);

   for (i = 0; i < PHILOSOPHES; i++)
     pthread_create(&phil[i], NULL, philosophe, (void*)&(id[i]) );

   for (i = 0; i < PHILOSOPHES; i++)
      pthread_join(phil[i], NULL);

   return (EXIT_SUCCESS);
}

