/**************************************
 * writeperf.c
 *
 * Programme d'exemple d'utilisation de
 * write - performances
 *
 *************************************/
///AAA
#define _BSD_SOURCE  // pour mkstemp

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
#include <getopt.h>



#define TESTSIZE 100000000   // 100 MB

extern char *optarg;
extern int optind, opterr, optopt;

void exit_on_error(char *s) {
  perror(s);
  exit(EXIT_FAILURE);
}

void usage() {
  printf("Usage : writeperf [-s] -l size\n");
  printf("        -s synchronisation des ecritures avec sync (defaut : off)\n");
  printf("        -l size taille des write en bytes (defaut : 10000)\n");
  exit(EXIT_FAILURE);
}

int main (int argc, char *argv[])  {
  int fd;
  int err;
  char **endptr=NULL;

  int c;

  int syncflag=false;
  long size=10000;

  while ((c = getopt (argc, argv, "sl:")) != -1) {
    switch (c)
      {
      case 's':
	syncflag = true;
	break;
      case 'l':
	size=strtol(optarg,endptr,10);
	if(endptr!=NULL||size<0||size>(TESTSIZE/10))
	  usage();
	break;
	   case 'h':
      case '?':
	usage();
      }
  }

  void *mem=malloc(TESTSIZE);
  char template[]="testperfXXXXXX";
  fd=mkstemp(template);
  if(fd==-1)
    exit_on_error("mkstemp");
  err=unlink(template);
  if(err==-1)
    exit_on_error("unlink");
  for(void *ptr=mem;ptr<mem+TESTSIZE;ptr=ptr+size) {
    if( write(fd, (void *) ptr, size) == -1 )
      exit_on_error("write");
    if(syncflag)
      sync();
  }

  err=close(fd);
  if(err==-1){
   perror("close");
    exit(EXIT_FAILURE);
  }

  return(EXIT_SUCCESS);
}
/*

jeremy@jeremy-N551VW:~/Documents/UCL/Info/TP/TP9$ time ./perf -l 100000
real	0m0.067s
user	0m0.000s
sys	0m0.064s
jeremy@jeremy-N551VW:~/Documents/UCL/Info/TP/TP9$ time ./perf -l 100

real	0m1.003s
user	0m0.020s
sys	0m0.980s
jeremy@jeremy-N551VW:~/Documents/UCL/Info/TP/TP9$ time ./perf -s -l 100000

real	1m25.001s
user	0m0.000s
sys	0m4.864s
jeremy@jeremy-N551VW:~/Documents/UCL/Info/TP/TP9$ time ./perf -s -l 100

ne se finit jamais
*/





