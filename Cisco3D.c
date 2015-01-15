/*
  Aim: Cisco in an hour™ Part III: In 3-D!
  
  Network Layer
    Transmission of data between two or more separate networks
    Is not concerned with whether or not data was sent successfully (connectionless)
    Major features of this layer are addressing, routing and packeting forward
    IP (Internet protocol) addresses
      IPv4: 4 byte adress
        [0-255].[0-255].[0-225].[0-255]
	ARP - Address Resoltion Protocol
	Translates IP <---> MAC
    Data is broken into units similar to frames but modified for Network Layer (like using IP addresses instead of MACs
    Packets and Datagrams are different kinds of such units.
    IPv4 MTU is 65,535 Bytes (Maximum transition unit) (amount of data transfered by one packet)
    
    IPv6 (VERY BIG CHANGE)
      Major Changes
        Address space goes from 2^32 -> 2^128
	Addresses are written as 8 groups of 4 hex
	0000 : 0000 : 0000 : ffff : 149.89.150.100
	Jumbograms
	  increases MTU to 2^32
*/
