//not finished
char line[100];

mkfifo("mario",0644);
*from_client = open( "mario", O_RDONLY );
read(*from_client,line,sizeof(line));



to_client = open(line,O_WRONLY);
strncpy(
