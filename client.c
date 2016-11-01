/****************** CLIENT CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
  int clientSocket;
int newSocket;
  char buffer[1024];

  struct sockaddr_in serverAddr;
  socklen_t addr_size;
	signed char PWM_value = 0;
	char message[30] = "From Client!\n";

  /*---- Create the socket. The three arguments are: ----*/
  /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
  clientSocket = socket(PF_INET, SOCK_STREAM, 0);
  
  /*---- Configure settings of the server address struct ----*/
  /* Address family = Internet */
  serverAddr.sin_family = AF_INET;
  /* Set port number, using htons function to use proper byte order */
  serverAddr.sin_port = htons(8080);
  /* Set IP address to localhost */
  serverAddr.sin_addr.s_addr = inet_addr("172.24.1.1");
  /* Set all bits of the padding field to 0 */
  memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

// *** napisa¢ zabebezpieczenie, ktora chroni, aby wartosc byla 0-100 
//	printf("Please write PWM value (0-100)\n");
//	scanf("%i", &PWM_value);

  /*---- Connect the socket to the server using the address struct ----*/
  addr_size = sizeof serverAddr;
  connect(clientSocket, (struct sockaddr *) &serverAddr, addr_size);




// *** WYSYLANIE
char buffer_client[1024];
strcpy(buffer_client,message);
printf("Message to send: %s\n\n", buffer_client);
send(newSocket,buffer,11,0);


	// *** ODBIERANIE
  /*---- Read the message from the server into the buffer ----*/
  recv(clientSocket, buffer, 1024, 0);

  /*---- Print the received message ----*/
  printf("Data: %s\n",buffer);   

  return 0;
}
