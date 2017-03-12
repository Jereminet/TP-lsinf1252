#include <stdio.h>
#include <stdlib.h>

typedef struct __attribute__((packed)) test{
        char c;
	long l;
        short s;

} test_t;

int main(int argc,char *argv[]){
	struct test *n=(struct test*) malloc(sizeof(struct test));
	printf("%p \n",&(n->c));
	printf("%p \n",&(n->l));
	printf("%p \n",&(n->s));
	free(n);
	n=NULL;
}

//taille de 24 au lieu de 11 pcq les variables sont alignés sur 8 bytes pour
//éviter qu'un long empiète sur 2 espaces mémoires

//packed permet d'optimiser l'organisation de la structure (la taille 
//passe donc à 11)
