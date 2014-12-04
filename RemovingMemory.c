#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
/*
 ipcs - interprocess communication : tells you what interprocess resources used

 shmdt - <sys/shm.h>, <sys/ipc.h>
   Detaches a variable from a shared memory segment
   Returns 0 (-1 upon failure (errno))
   shmdt (pointer)
     pointer - the address used to access the segment
     - Does not remove the shared descriptor (so you can reattach)
     - Does not remove memory
     
 shmctl
   Each shared memory segment has metadata that can be stored in a struct (struct shmid_ds)
   Some of that data is stored: last access, size, pid of creator, pid of last modification
   Perform operations on the shared memory segment
   shmctl (descriptor, command, buffer)
     descriptor - return value of shmget
     commands:
       IPC_STAT - populate the buffer (struct shmid_ds) with information
       IPC_SET - set some of the information for the segment to the info in buffer
       IPC_RMID: remove a shared memory segment
     returns - 0 if success -1 else (errno)
     example:
       struct shmid_ds d;
       shmctl(sd, IPC_RMID, &d); //will remove the memory
*/
int main(){
  int key = ftok("makefile",29);
  int sd;
  int * p;
  sd = shmget(key,4,IPC_CREAT | 0644);
  printf("sd: %d\n",sd);
  p = (int *)shmat(sd,NULL,0);
  *p = 34782;
  printf("p: %p\n",p);
  printf("*p: %d\n",*p);
  shmdt(p); //p = (int *)shmdt(p); -> will reset p to 0
  //printf("p: %p\n",p); Works
  //printf("*p: %d\n",*p); Seg faults (using memory you don't have access to)

  return 0;
}
