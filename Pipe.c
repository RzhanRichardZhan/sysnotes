#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#define READ 0
#define WRITE 1
/*
  Aim: Ceci n'est pas une pipe
  
  Pipe
    A conduit between 2 separate processes
    Pipes have two ends, a read end and a write end
    A -> B (A has the write end, B has the read end)
    A <- B
    Pipes are unidirectional (a single pipe must be either read- or write-only in a process).
    You can transfer any data you like through a pipe using read/write
    Unnamed pipes have no external identification (liek a descriptor or name)
    
    pipe - <unistd.h>
      Create an unnamed pipe
      Returns 0 if the pipe was created, -1 if not
      pipe( int descriptors[2] ) //does not need open
        descriptors[0] RDONLY fd
	descriptors[1] WRONLY fd
	
*/

int main(){
  int fds[2];
  int f;
  double x;
  pipe(fds);
  f=fork();
  char line[128];
  if (!f){
    close(fds[0]);//close the read to write
    printf("Enter stuff:\n");
    fgets(line,sizeof(line),stdin);
    sleep(4);// this will block the parent as the parent has to wait for the pipe even though there is no wait
    write(fds[1],line,sizeof(line));
  }
  else{
    close(fds[WRITE]);
    read(fds[READ],line,sizeof(line));
    printf("Parent read %s\n",line);
  }

    
  return 0;
}

