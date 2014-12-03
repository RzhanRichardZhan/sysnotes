#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<string.h>
/*
03/12/14

shmat <sys.shm>, <sys/ipc.h>
  Attach a shared memory segment to a variable
  Returns a pointer to the segment, or -1 (errno)
  shmat ( descriptor, address, flags )
    descriptor is the return value of shmget
    address (leave as 0, let's the OS provide the appropriate address)
    flags (usually 0)
      SHM_RDONLY - makes the memory read only
  char * p = shmat ( sd, 0, 0 );
  
ftok <sys/ipc.h>
  creates a key for ipc
  ftok ( char * path; int id );
    returns a key based on the path of a file and a random int
    path must be accessible by the running program
    sd = shmget( ftok("dir/file", 12), 1024, IPC_CREAT | 0664);

*/
int main(){
  int f, sd;
  char * p;
  sd=shmget(24601,1024,IPC_CREAT | 0664);//24601 is a key (bad key generation)
  f = fork();
  if (!f){
    p = shmat(sd, 0, 0); //they have the same key because child
    strncpy(p,"I like sharing",1024);
    printf("\tChild: *p = %s\n",p);
    
  }
  else{
    sleep(1);
    printf("Parent: *p = %s\n",p);
  }
  return 0;
}
