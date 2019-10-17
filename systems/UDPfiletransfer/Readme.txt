

 ////// Explaining About UDP ///////////////
User Datagram Protocol (UDP) is a Transport Layer protocol. UDP is a part of Internet Protocol suite, referred as UDP/IP suite.
There are two major transport layer protocols to communicate between hosts : TCP and UDP.Transmission Control Protocol (TCP) is the dominant transport layer protocol used with most of Internet services; provides assured delivery, reliability and much more but all these services cost us with additional overhead and latency. Here, UDP comes into picture. For the realtime services like computer gaming, voice or video communication, live conferences; we need UDP. Since high performance is needed, UDP permits packets to be dropped instead of processing delayed packets. There is no error checking in UDP, so it also save bandwidth.
User Datagram Protocol (UDP) is more efficient in terms of both latency and bandwidth.

/************
In UDP, the client does not form a connection with the server like in TCP and instead just sends a datagram. Similarly, the server need not accept a connection and just waits for datagrams to arrive. Datagrams upon arrival contain the address of sender which the server uses to send data to the correct client. **********************/


Data can be transferred between two computers using Socket programming in C.

Similarly, files can easily be sent using UDP protocol and a simple client/server.

Security: Handled by encryption.


Protocol : UDP
Encryption: XOR encryption

/////////    ALGORITHM FOR CODE //////////////////


1. The server starts and waits for filename.
2. The client sends a filename.
3. The server receives filename.
   If file is present, server starts reading file  and continues to send a buffer filled with file contents encrypted until file-end is reached.
4. End is marked by EOF.
5. File is received as buffers until EOF is received. Then it is decrypted.
6. If Not present, a file not found is sent.

//////////////// Necessary Functions /////////////////

int socket(int domain, int type, int protocol)
Creates an unbound socket in the specified domain.
Returns socket file descriptor.

Arguments :
domain – Specifies the communication
domain ( AF_INET for IPv4/ AF_INET6 for IPv6 )
type – Type of socket to be created
( SOCK_STREAM for TCP / SOCK_DGRAM for UDP )
protocol – Protocol to be used by socket.
0 means use default protocol for the address family.

///// FUNCTION PROTOTYPE ////////
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
Assigns address to the unbound socket.
Arguments :
sockfd – File descriptor of socket to be binded
addr – Structure in which address to be binded to is specified
addrlen – Size of addr structure

///// FUNCTION PROTOTYPE ////////

ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
               const struct sockaddr *dest_addr, socklen_t addrlen)
Send a message on the socket

Arguments :
sockfd – File descriptor of socket
buf – Application buffer containing the data to be sent
len – Size of buf application buffer
flags – Bitwise OR of flags to modify socket behaviour
dest_addr – Structure containing address of destination
addrlen – Size of dest_addr structure

///// FUNCTION PROTOTYPE ////////

ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                 struct sockaddr *src_addr, socklen_t *addrlen)
Receive a message from the socket.

Arguments :
sockfd – File descriptor of socket
buf – Application buffer in which to receive data
len – Size of buf application buffer
flags – Bitwise OR of flags to modify socket behaviour
src_addr – Structure containing source address is returned
addrlen – Variable in which size of src_addr structure is returned

///// FUNCTION PROTOTYPE ////////

int close(int fd)
Close a file descriptor

Arguments :
fd – File descriptor

////// HOW TO COMPILE THE PROGRAM //////

Compile the server program (gcc server.c -o ser)
Run server using (./ser)
On another terminal, compile UDP client program (gcc client.c -o udpcli)
Run tcp client (./udpcli)
