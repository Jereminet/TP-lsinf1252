#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> 

int global=0;
pthread_mutex_t mutex;

void *fun(void *param){
	pthread_mutex_lock(&mutex);
	pthread_mutex_lock(&mutex); // En theorie, si le meme thread lock 2 fois le meme mutex, ce n'est pas vraiment un problème
				    // Ici, il boucle, c'est du au choix de l'implementation
	global++;
	pthread_mutex_unlock(&mutex);
	pthread_mutex_unlock(&mutex); // AUCUN EFFET
	return NULL;
}

int main(int argc, char *argv[]){
	int res;
	pthread_t thread;

	pthread_mutex_init(&mutex,NULL);

	pthread_create(&thread,NULL,&fun,&res);

	pthread_join(thread,NULL);

	pthread_mutex_destroy(&mutex);	
}
