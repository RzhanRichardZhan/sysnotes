#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/types.h>
#include<sys/sem.h>
/*
09/12/14

semop
  Perform semaphore operations (like Up/Down)
  All operations performed via semop are atomic!
  semop( descriptor. operation buffer, amount )
    descriptor - return of semget
    amount - the amount of semaphroes you want to operate on in the semaphore set
    operation buffer - a pointer to a struct sembuf value
      struct sembuf {
        short sem_op; //up(1) or down(-1) (any number works, you will be requesting/releasing that value from the semaphore) (0 waits until the semaphore hits 0)
	short sem_num; //index of semaphore you want to wrok on
	short sem_flag; // provide further options
	  SEM_UNDO - allow the OS to undo the given operation. Useful in event that a program exits before it could release a semaphore
	  IPC_NOWAIT - instead of waiting for the semaphore to be available, return an error
      };
      


*/
int main(int argc, char **argv) {
  int key = ftok("makefile",'a');
  int semid;
  if (strcmp(argv[1],"--create")==0){
    semid=semget(key,1,IPC_CREAT | IPC_EXCL | 0644);
    union semun su;
    su.val=1;
    semctl(semid,0,SETVAL,su);
  }
  else if (strcmp(argv[1],"--remove")==0){
    semid=semget(key,1,0644);
    semctl(semid,0,IPC_RMID);
  }
  return 0;
}
