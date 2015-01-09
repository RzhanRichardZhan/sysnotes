/*
  1/9/15
  Aim: Cisco in an hour™ Part II: Electric Boogaloo
  
  Physical Layer
    Types of connections
    Ethernet
      Multiple computers connect to a single hub or switch
      Hub
        Broadcasts the data to all the computers
      Switch
        Sends data to a specific computer (Needs to look at Data link Layer)
      The more computers you add to an ethernet network, the greate the chance of collisions

   Data Link Layer
     Point-to-point transmission between devices on the same (local) network
     Each device is given a unique 6-byte MAC (Media Access Control) address, this is set on each network card when it is made
     Data is packaged into frames
       Ethernet Frame:
         <prefix><dest><source><...><data><checksum>
	     8     6      6      6  46-1500   4
	 prefix: 10101010*7 + 10101011
	 destination/source: MAC Adresses
	 ...: information about the frame type
	 checksum: to ensure data integrity
	 
      
*/
