#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main(){
  int welcomeSocket, clientSocket, newSocket;
  char buffer1[1024], buffer2[1024];
  struct sockaddr_in serverAddr;
  socklen_t addr_size;
  char message[30] = "1\n";
  struct sockaddr_storage serverStorage;//***
  
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(8080);
  serverAddr.sin_addr.s_addr = inet_addr("172.24.1.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

  bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));//***

//CONNECT
  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);
//SEND ***
		strcpy(buffer2,message);
		send(newSocket,buffer2,13,0);
  
  
//READ
  recv(clientSocket, buffer2, 1024, 0);
  printf("S->C: %s",buffer2);   

  return 0;
}
