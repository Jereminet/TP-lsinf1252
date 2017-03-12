#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char *str) {
	int i=0;
	while(*str!='\0'){
		str++;
		i++;
	}
	return i;
}

char *strcat(char *destination, const char *source) {
	size_t dest_len = strlen(destination);
	int i;
	for (i = 0 ; source[i] != '\0' ; i++)
       		 destination[dest_len + i] = source[i];
	destination[dest_len + i] = '\0';
	return destination;
}

int strcasecmp(const char *s1, const char *s2) {
	int c1=*s1;
	int c2=*s2;
	printf("Valeur de c1 : %d \n",c1);
	printf("Valeur de c2 : %d \n",c2);
	int sum=0;
	while(c1!='\0' || c2!='\0'){
		if(c1==c2 || (c1+32)==c2 || c1==(c2+32)){
			printf("Rentré dans if \n");
			c1=*(++s1);
			c2=*(++s2);
			printf("Valeur de c1 : %d \n",c1);
			printf("Valeur de c2 : %d \n",c2);
		}else{
			printf("Rentré dans else \n");
			sum=sum+(c1-c2);
			printf("Valeur de sum : %d \n",sum);
			c1=*(++s1);
			c2=*(++s2);
			printf("Valeur de c1 : %d \n",c1);
			printf("Valeur de c2 : %d \n",c2);			
		}
	}
	return sum;
}
			


int main (int argc, char *argv[]){
	char *t1=NULL;
	char *t2=NULL;
        char src[4]="oui";
	char dest[7]="bonjou";
	printf("Comparasion : %d \n",strcasecmp(dest,src));

}

