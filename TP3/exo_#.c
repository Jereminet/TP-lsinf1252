#include <stdio.h>
#include <stdlib.h>

typedef struct vector_t {
    int size;
    float *v;
}vector_t;

struct vector_t * init(int i, float f)
{
    vector_t *vecteur = (vector_t *)malloc(sizeof(vector_t));
    vecteur->size = i;
    
    float *temp = (float *)malloc(sizeof(float));
    
    int j;
    for(j=0; j<i; j++) {
        *temp = f;
        temp++;
    }
    vecteur->v=temp;
    return vecteur;
}


float get(struct vector_t * vecteur, int i)
{
    return *(vecteur->v+i);
}


void set(struct vector_t * vecteur, int i, float f)
{
    *(vecteur->v+i) = f;
}


void destroy(struct vector_t * vecteur)
{
    free(vecteur->v);
    free(vecteur);
}

int main (int argc, char *argv[]){
	return 0;
}
