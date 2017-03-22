#include <stdlib.h>
#include <stdio.h>

extern int one(){
int a;
__asm__(
	"movl $1,a;"
);
return a;
}
