#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>

int main(int argc, char const *argv[]) {
  key_t key;
  void * retour;
  int ret;
  void* ptr = malloc(4096);
  ret = shmget(key,4096,IPC_CREAT|S_IRUSR);
  retour = (void *) shmat(ret,ptr,SHM_RDONLY|SHM_RND|SHM_REMAP);
     pid_t var =  fork();
  printf("ptr: %p\n",ptr );
  printf("Retour:%p\n",retour  );
  return 0;
}