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

//si on reorganise la structure en mettant par exemple long,short puis char, alors la taille 
//vaut 11 et s'aligne donc sur le plus proche multiple de 8, soit 16 (au lieu de 24)

//packed permet d'optimiser l'organisation de la structure (la taille 
//passe donc à 11)
