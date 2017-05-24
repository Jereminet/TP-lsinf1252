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

void mange(int id) {
  printf("Philosophe [%d] mange\n",id);
  for(int i=0;i< rand(); i++) {
    // philosophe mange
  }
}

void *check_time(void *param){
    int sval1;
    int sval2;
    int sval3;
    int res1;
    int res2;
    int res3;
    while(true){
        sem_getvalue(&baguette[0],&sval1);
        sem_getvalue(&baguette[1],&sval2);
        sem_getvalue(&baguette[2],&sval3);
        res1=sval1;
        res2=sval2;
        res3=sval3;
        sleep(10);
        sem_getvalue(&baguette[0],&sval1);
        sem_getvalue(&baguette[1],&sval2);
        sem_getvalue(&baguette[2],&sval3);
        if(res1==sval1 && res2==sval2 && res3==sval3){
            printf("Sémaphores ne sont pas modifiées \n");
            exit(EXIT_FAILURE);
        }
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

   for (i = 0; i < PHILOSOPHES; i++){
     pthread_create(&phil[i], NULL, philosophe, (void*)&(id[i]) );
   }

  pthread_t checktime;
   pthread_create(&checktime,NULL,check_time,NULL);

   for (i = 0; i < PHILOSOPHES; i++){
      pthread_join(phil[i], NULL);
   }

    pthread_join(checktime,NULL);
   return (EXIT_SUCCESS);
}
