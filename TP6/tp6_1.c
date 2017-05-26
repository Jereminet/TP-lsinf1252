#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int global=0;
static int static_global=0;

void * fun(void *arg){
	global++;
	static_global++;
	foo(); //+return
}

void foo(void){
	int local=0;
	int static_local=0; //valeur conservee entre les appels de fonctions, stockee dans la memoire "global"
	static_local++; //+return
}

pthread_t thread;

int main (int argc, char *argv[]){
	int var;
	pthread_create(&thread,NULL,&fun,&var);
	foo();
	global++;
        static_global++;
	var++;
	pthread_join(thread,NULL);	
}
