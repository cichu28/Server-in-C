/******************* SERVER CODE *****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include "LedON.h"

int main(){
  init();
  
  int welcomeSocket, newSocket, portNum, clientLen, nBytes;
  unsigned char buffer[1024];
  //int buffer[1024];
  struct sockaddr_in serverAddr;
  struct sockaddr_storage serverStorage;
  socklen_t addr_size;
  int i = 0;
  int PWM_value;
  int PWM_value2;
  welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
  portNum = 8080;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(portNum);
  serverAddr.sin_addr.s_addr = inet_addr("172.24.1.1");
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  
  bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
  addr_size = sizeof serverStorage;
  if(listen(welcomeSocket,5)==0)    printf("Listening\n");
  else    							printf("Error\n");
  close(newSocket);
  /*loop to keep accepting new connections*/
  while(1){
    newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
    /*fork a child process to handle the new connection*/
    //if(!fork())
    //{
      nBytes = 1;
      /*loop while connection is live*/
      while(nBytes!=0)
      {
		  i++;
		  nBytes = recv(newSocket,buffer,1024,0);  
		  PWM_value = (int)buffer[0];
		  PWM_value2 = (int)buffer[1];
		  printf("Connect! #%d		PWM: %d		PWM2: %d\n", i, PWM_value, PWM_value2); 
		  Led(PWM_value, PWM_value2);
		  //PWM_value -= 48;
		  //printf("PWM: %i\n\n", PWM_value);
		  //Led(PWM_value);
		  //send(newSocket,buffer,nBytes,0);
     }
      
      //close(newSocket);
      //exit(0);
    //}
    
    /*if parent, close the socket and go back to listening new requests*/
    //else
    //{
    //  close(newSocket);
    //}
  }

  return 0;
}
