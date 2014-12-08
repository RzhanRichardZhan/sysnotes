#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/types.h>
/*
08/12/14

System V IPC - standard systems

semctl - <sys/types.h> <sys/ipc.h> <sys/sem.h>
  Control the semaphore, including:
    Set the semaphore value (only way to change without up or down)
    Remove the semaphore
    Get the current Value
    Get information about the semaphore
  semctl ( descriptor, index, operation, buffer );
    descriptor - the return value of semget
    index - the index of the semaphore you want to control in the semaphore set identified by the descriptor
      for a single semaphore set, 0
    operation - one of the following constants (there are others as well)
      IPC_RMID - remove the semaphore
      SETVAL - set the value (requires buffer)
      GETVAL - return the value
      IPC_STAT - populate buffer with information about the semaphore (requires buffer)
*/
int main(){
  //struct
  struct foo {
    int x;
    char y;
  };
  struct foo myfoo;
  myfoo.x = 5;
  //union
  union bar {
    int x;
    char y;
  };
  union bar mybar;
  mybar.y='a';
  /*
    struct foo stores 5 bytes
    union bar stores 4 bytes
      unions store the largest data (in this case the int is 4 bytes)
      unions can only contain one of its data members
  */
  return 0;
}
/*
union semun{
  int val;
  struct semid_ds *buf;
  u_short *array;
};
struct semid_ds {
  struct ipc_perm sem_perm;
  ...
};
Setting the semaphore:
  union semen su;
  su.val = 3;
  semctl(semd,0,SETVAL,su);
Getting the value:
  int sval;
  sval = semctl(semd, 0 , GETVAL);
Removing the semaphore:
  semctl(semd, 0, IPC_RMID);
*/
