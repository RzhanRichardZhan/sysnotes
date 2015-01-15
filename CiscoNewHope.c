/*
  Aim: Cisco In An Hour IV: A New Hope


  Transport Layer
  Computer to computer connection over a network.
  
  Unconcerned with the individual hops of layer 3 traffic
  Each destination address has multiple ports, allowing for multiple kinds of connections per computer
  65,535 ports
  Ports < 1024 are well known/reserved
  Regulated by the Internet Assigned Numbers Authority (IANA)
  TCP Transmission Control Protocol
    Reliable connection
    Guarantees delivery of data
    Data is considered a continuous stream that arrives in the order it is sent
    Connections are established using the 3-way handshake
    Server "binds" to a port and waits
    1. Client sends SYN
    2. Server responds back SYN_ACK
    3. Client sends ACK
    Once this is done the connection is established and data can flow freely between the two
      Sockets are not uni-directional
    UDP - User Datagram Protocol
    Does not require an explicit connection
    Data is sent as discrete datagrams with sa set size as opposed to a continuous stream
    Datagrams maybe dropped or receive out of order
    UDP is much faster thanks o Samuel
    
*/
