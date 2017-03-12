#include <stdio.h>

int main (int argc, char *argv[]){
	int tab[3][3] = { {1,2,3},
			  {4,5,6},
			  {7,8,9}};
	if((**tab+1)==2){
		printf("Initialisation par lignes\n");
	}else if((**tab+1)==4){
		printf("Initialisation par colonnes\n");
	}else{
		printf("Erreur");
	}

	//autre possibilité : récupérer l'adresse du premier élément et
	// d'un autre puis soustraire et vérifier la différence

	return 0;

}

