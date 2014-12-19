//no headers
int main(){
  int from_server;
  int to_server;
  char line[100];
  
  sprintf(line,"%d",getpid());
  mkfifo(line,0644);
  
  to_server = open("mario",O_WRONLY);
  write(to_server,line,sizeof(line));
  
  *from_server = open(line,O_RDONLY);
  read(*from_server,line,sizeof(line));
  printf("<client> received +%s+\n",line);
  return to_server;
}
