#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

/*
  Aim: A pipe by any other name...
  Named Pipes
    Also known as FIFOs (First In First Out)
    Same as unnamed pipes except FIFOs have a name that can be used to identify them via different programs (Unidirectional)
    
    mkfifo
      shell command to make a FIFO
      mkfifo <pipe name>
      if you remove named pipe, it is still being used an unnamed pipe
      multiple pipes collect like ajax 
    
    mkfifo - <sys/types.h> <sys/stat.h>
      C function creates a FIFO
      Returns 0 on success and -1 on failure
      Once created, the FIFO acts like a regular gile, and we can use open, read, and write
      mkfifo ( <name> <permission> );
        -blocks on the open call until read or write
      
*/

int main(){
  int from_client;
  char[256];
  mkfifo("mario",0644);
  from_client(open("mario",O_RDONLY));
  read(from_client,line,sizeof(line_));
  close(from_client);

  return 0;
}
