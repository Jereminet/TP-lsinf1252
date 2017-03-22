#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc,char *argv[]){
    if (strcmp(argv[2],"-eq")==0){
        eq(atoi(argv[1]),atoi(argv[3])); 
    }else if (strcmp(atoi(argv[2]),"-ne")==0){
        ne(atoi(argv[1]),atoi(argv[3]));
    }else if (strcmp(atoi(argv[2]),"-ge")==0){
        ge(atoi(argv[1]),atoi(argv[3]));
    }else if (strcmp(atoi(argv[2]),"-gt")==0){
        gt(atoi(argv[1]),atoi(argv[3]));
    }else if (strcmp(atoi(argv[2]),"-le")==0){
        le(atoi(argv[1]),atoi(argv[3]));
    }else if (strcmp(atoi(argv[2]),"-lt")==0){
        lt(atoi(argv[1]),atoi(argv[3]));
    }else{
        printf("Besoin de 2 arguments");
    }
}

int eq(int a,int b){
    if (a==b){
        return 0;
	}else{
        return 1;
    }
}

int ne(int a,int b){
    if (a==b){
        return 1;
    }else{ 
        return 0;
    }
}

int ge(int a,int b){
    if (a>=b){
        return 0;
    }else{
        return 1;
    }
}

int gt(int a,int b){
    if (a>b){
        return 0;
    }else{
        return 1;
    }
}

int le(int a,int b){
    if (a<=b){
        return 0;
    }else{
        return 1;
    }
}

int lt(int a,int b){
    if (a<b){
        return 0;
    }else{
        return 1;
    }
}
