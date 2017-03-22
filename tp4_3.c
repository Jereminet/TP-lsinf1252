#include <sys/time.h>
#include <stdio.h>

#define SIZE 10000

int matrix[SIZE][SIZE];

int sum() {
  int sum=0;
  for(int i=0;i<SIZE;i++) {
    for(int j=0;j<SIZE;j++) {
      sum+=matrix[i][j];
    }
  }
  return sum;
}

int sum2() {
  int sum=0;
  for(int i=0;i<SIZE;i++) {
    for(int j=0;j<SIZE;j++) {
      sum+=matrix[j][i];
    }
  }
  return sum;
}

int main (int argc, char *argv[]){
	

	struct timeval start1,start2,end1,end2;
	
        gettimeofday(&start2,NULL);
        sum2();
        gettimeofday(&end2,NULL);
        printf("Temps pour sum2 : %ld \n",(end2.tv_sec*1000000+end2.tv_usec)-(start2.tv_sec*1000000+start2.tv_usec));



	gettimeofday(&start1,NULL);
	sum();
	gettimeofday(&end1,NULL);
	printf("Temps pour sum : %ld \n",(end1.tv_sec*1000000+end1.tv_usec)-(start1.tv_sec*1000000+start1.tv_usec));
}
        
 //Sum est plus rapide étant donné que le stockage en mémoire se fait successivement comme suit : tab[0][0],tab[0][1],tab[0][2],... et profite donc de la localité spatiale.
 //Sum 2 lui va faire des accès mémoire strillé, c'est à dire par bond de SIZE.
