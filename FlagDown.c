#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
/*
05/12/14
Aim: How do we flag down a resource?

Semaphores (created by Edsgar Dijkstra)
  IPC construct used to controll access to a shared resource (like a file or shared memory)
  
  Essentially, a sempahore is a counter that represents how many processes can access a resource at any given time
  If a semaphore has a value of 3 -> can have 3 active users
  if 0 -> unavailable
  
  Most semapore operations are "atomic", meaning they will not split up into multiple processor instructions
  Semaphore operations:
    Create a sempahore
    Set an initial value
    Uo(S) / V(S)
      Release the semaphore to signal you are done with it's association resource
      Pseudocode:
        S++; (note it's atomic)
    Down(S) / P(S)
      Attempt to take the semaphore
      If semaphore is 0, wait for it to be avaliable
      Pseudocode:
      while (S == 0){
        block;
      }
      S--;
  semget - <sys/types.h> <sys/ipc.h> <sys/sem.h>
    Create/Get access to a semaphore
    This is not the same as Up(s), the semaphore is not modified by semget
    Returns a semaphore descriptor or -1 (errno)
    semget ( key, amount, flags ) //not atomic
      Key - unique semiphore identifier (use ftok)
      amount - Semaphore are actually sored as sempahore sets with possibly many semaphores stored together. This parameter set the number of semaphores to create/get
      flags - signals whether to create the semaphore including permissions
        IPC_CREAT, IPC_EXCL
    
*/

int main(){
  int semd;
  semd = semget(ftok("file/dir"),1,0644 | IPC_CREAT);
  return 0;
}

