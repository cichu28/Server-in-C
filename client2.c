/******************* CLIENT CODE *****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
//SET VARIABLES
  int clientSocket, portNum, nBytes;
  char buffer[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  portNum = 8080;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(portNum);
  serverAddr.sin_addr.s_addr = inet_addr("172.24.1.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
  addr_size = sizeof serverAddr;
//CONNECT
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);

  while(1){
//SEND
    //printf("Type a sentence to send to server:\n");
    fgets(buffer,1024,stdin);
    printf("You typed: %s",buffer);
    nBytes = strlen(buffer) + 1;
    send(clientSocket,buffer,nBytes,0);
//RECIVE
    //recv(clientSocket, buffer, 1024, 0);
    //printf("Received from server: %s\n\n",buffer);   
  }

  return 0;
}
