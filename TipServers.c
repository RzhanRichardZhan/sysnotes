#include<stdio.h>
#include<stdlib.h>
/*
  Aim: Always remember to tip your server
  
  Server/Client Program Paradigms
    Basic Server
      1 - Server creates the WKP
      2 - Server waits for WKP connection
      3 - Client creates a "private" named pipe
      4 - Client connects to server and sends the private pipe name
      5 - Client waits for private pipe connection
      6 - Server receives the client's message and removes the WKP (keeps the connection and prevents other clients from entering the WKP)
      7 - Server connects to client pipe, sending an inital acknowledgement message
      8 - Client receives server's message, removes it's private pipe.
      9 - Once the client exits, the server recreates a new WKP, removes the old client connections and the steps restart.
      * ONLY ONE CONNECTION AT A TIME
    Forking Server
      1 - 5
      6 - Server receives the client's message
      7 - Serve forks off a subserver (duplicate file table/has the connection, has the copy of client's message
      8 - Main server removes the WKP and closes the connection with the client
      9 - Main server creates a new WKP and waits for a new client
      10 - Subserver connects to client page sending an inital acknowldgement messages
      11 - Client receives server's message it's private pipe
      
*/

int main(){
  return 0;
}
