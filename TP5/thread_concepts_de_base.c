#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void * fthread(void * n){
	if(n==NULL){
		return NULL;
	}
	int *size = (int *) n;
	int *tab = malloc((*size)*sizeof(int));
	int i;
	for(i=0;i<(*size);i++){
		tab[i]=1;
	}
	pthread_exit(tab);
}

int * getThreadRet(pthread_t th){
	int *ptr;
	int err = pthread_join(th,NULL);
	if(err!=0){
		return NULL;
	}
	ptr=&err;
	return ptr;
}
