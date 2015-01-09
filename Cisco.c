/*
  1/8/15
Aim: Cisco in an hour™

What needs to happen in order for 2 computers to communicate with each other?

OSI 7-Layer Model
  Used to help conceptualize the different parts of network connections

  The top layer is the most concrete, with each subsequent layer becoming more abstract (relying less on the physical connections and more on code)
  
  1. Physical
  2. Data Link
  3. Network
  4. Trasport
  5. Session
  6. Presentation
  7. Application

  If you are working on a particular layer, you should not have to think too much about the other layers.
  
  Physical Layer
    How computers are physically connedted
    Things lik electrons running across wires, radio signals pulsing through the air
    A brief history of wired connectiosn
    Thicknet - a single Coaxial runs throughout the network, "vampire taps" go into teh cable room to scare data out
    - any mesage is sent to everyone
    Thinnet - a single coaxial  runs throughout the network
      -T-Juctions usedt Spliced connections
      - signal degeneration
    Thicknet and Thinnet, all data is sent to all computers
    Each computer added increases the power drain on the entire system, degrading service

Token Ring
  -Each computer is connected in a ring to each other
  -Everyone can read and access memory but only one can send information (the one with the token)
  - 

 */
