#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
	int a;
	char b;
}jeremy;

void *f(void *param){
	struct jeremy *test = (struct jeremy*) param;
	int i = test->a;
	char c = test->b;
	return NULL; // return n'importe quoi mais le type cast en (void *)
}

void main(void){
	pthread_t data;
	struct jeremy *test = malloc(sizeof(struct jeremy));
	test->a=1252;
	test->b='c';
	int error=pthread_create(&data,NULL,&f,test);

	pthread_join(data,NULL);
}
