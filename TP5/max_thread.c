#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <sys/resource.h>

void *f(void *param){
    int *i = (int *) param;
    *i=-(*i);
    return (void *)i;
}


int main(int argc, char *argv[]) {

    struct rlimit *l=(struct rlimit *)malloc(sizeof(struct  rlimit));
    int res = getrlimit(RLIMIT_NPROC,l);
    printf("nb max de thread : %d \n",(int)l->rlim_cur+(int)l->rlim_max);
    free(l);
    /*int tab[100000];
    pthread_t t[100000];
    int i;
    for(i=0;i<100000;i++){
        tab[i]=i;
        int err=pthread_create(&t[i],NULL,&f,(void *)&tab[i]);
        if(err!=0){
            perror("Erreur dans pthread_create");
        }
    }
   
   for(i=0;i<100000;i++){
       int err=pthread_join(t[i],NULL);
       if(err!=0){
           perror("Erreur dans pthread_join");
       }
   }*/

   return 0;
}