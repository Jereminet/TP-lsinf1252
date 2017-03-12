#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
	int *tab = (int *) malloc(sizeof(int)*1000);
	int i;
	for(i=0;i<1000;i++){
		tab[i]=1252;
	}
	free(tab);
	tab=NULL;
}

