#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
int *tableau = (int *) malloc(sizeof(int)*1000);
        int j;
        for(j=0;j<500;j++){
                tableau[j]=1252;
                tableau[999-j]=1252;
        }
        free(tableau);
	tableau=NULL;
}
