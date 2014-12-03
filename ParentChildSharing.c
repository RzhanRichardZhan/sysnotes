#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

/*
02/12/14
Aim: Sharing is caring!
*/

int main(){  
  if (!fork()){
    printf("HI\n");
  }
  else{
    int i;
    wait(i);
    printf("Hello~\n");
  }
  return 0;
}

/*
File access is slow. Memory is fast.
File access causes file concurrency issues
//Shared memory is quickly accessible and contains information that can be accessed by multiple processes (no signals)
Shared memory (more IPC)
  A segment of heap memory that can be accessed by multiple processes
  Shared memory is accessed via some key that is known by any process that needs to access it
  *Shared memory does not get released when a program exits
  5 Key Shared Memory Operations:
    Create the segment (Happens once) //control
    Access the segment (Happens oncer per process)
    Attach the segment to a variable (pointer) (once per process)
    Detach the segment from a variable (once per process)
    Remove the segment (happens once) //control

  shmget - <sys/shm.h>, <sys/ipc.h>
    Create or access a shared memory segment
    returns shared memory descriptor or 01 if it fails (errnos)
    shmget( key, size, flags )
      key - unique integer identifier for the shared memory segment
      size - how much memory to request
      flags - signals whether to create the segment
        Includes permissions for the segment
	Combine with bitwise or
	IPC_CREAT: create the segment will set value to all 0s
	IPC_EXCL: if created, fail
*/
