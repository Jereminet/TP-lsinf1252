#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	struct foo_t {
        char a;
        int b;
	};

	printf("Taille : %lu \n",sizeof(struct foo_t));
	return 0;
}

