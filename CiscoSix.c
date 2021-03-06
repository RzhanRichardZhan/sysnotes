/*
  Aim: Cisco In An Hour VI: The Undiscovered Country
  
  Sockets
    connect (tcp client only)
      connect to an existing network socket
      connect(<descriptor>,<address>,<address size>)
        address: pointer to address
	size: regular sizeof call
      returns 0 or -1
    listen (tcp server only)
      Put the socket into a listening state
      listen(<descriptor>,<queue size>)
        descriptor - return value of socket
	queue - number of connections that can wait, doesn't work anymore
        listen(sd,1);
	-> returns 0 or -1
     accept(tcp server only) //forever loop
       handles the required 3-way handshake
       creates a new socket with the correct client end, returns a descriptor to the new socket
       accept(<descriptor>,<address>,<address length>)
         descriptor: return value of socket
	 address/address length : Information about the specific client that is connected to the new socket. (can be left NULL);
	 address - pointer to sockaddr to fill it with info
     recvfrom (UDP sockets only)
       recvfrom(<descriptor>,<buffer>,<buffer size>,<flags>,<socket address>,<address length>);
         buffer: where to put the data flags: not going into that her
*/
