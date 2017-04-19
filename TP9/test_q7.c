#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main(int argc,char *argv[]){
	int fd1=open("touch_file.txt",O_RDWR);
	 int fd2=open("touch_file.txt",O_RDONLY); 

	printf("fd1 %d \n",fd1);
	printf("fd2 %d \n",fd2);
}
