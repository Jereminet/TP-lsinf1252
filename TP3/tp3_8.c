#include <stdio.h>
#include <stdlib.h>

int global;  //adresse ne bouge pas (stockée dans les données N-I)
void main(void)
{
        int local; //bouge (stockée sur la Stack)
        int *ptr1 = (int *)malloc(sizeof(*ptr1)); //bougent (stockées dans le Heap)
        int *ptr2 = (int *)malloc(sizeof(*ptr2));

        printf("global %p loc %p p1 %p p2 %p\n", &global, &local, ptr1, ptr2);
}
