#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

typedef void (*sighandler_t)(int);

int sig_ignored(int signum){
    sighandler_t p = signal(signum,SIG_IGN); //remplacement du handler associé à signum
    // on peut mettre ce qu'on veut comme 2e argument de signal
    signal(signum,p); // nouvel appel pour rétablir le handler
    return (p==SIG_IGN);
}

int main(int argc,char *argv[]){
    int i = atoi(argv[1]);
    printf("sig_ignored : %d \n",sig_ignored(i));
}
