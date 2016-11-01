/****************** SERVER CODE ****************/

#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include "LedON.h"

int main(){
	int welcomeSocket, newSocket;
int clientSocket;
	char buffer[1024];
char buffer_client[1024];
	struct sockaddr_in serverAddr;
	struct sockaddr_storage serverStorage;
	socklen_t addr_size;
	int counter = 0;
	//char counter_char;
	char message[30] = "From Server!!\n";
	int i=0;
	signed char PWM_value = 100;
	init();
	
	/*---- Create the socket. The three arguments are: ----*/
	/* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
	welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
	 
	/*---- Configure settings of the server address struct ----*/
	/* Address family = Internet */
	serverAddr.sin_family = AF_INET;
	/* Set port number, using htons function to use proper byte order */
	serverAddr.sin_port = htons(8080);
	/* Set IP address to localhost */
	serverAddr.sin_addr.s_addr = inet_addr("172.24.1.1");
	/* Set all bits of the padding field to 0 */
	memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);  

	/*---- Bind the address struct to the socket ----*/
	bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));

	while(1)
	{
		counter++;
		/*---- Listen on the socket, with 5 max connection requests queued ----*/
		if(listen(welcomeSocket,5)==0)		printf("Listening.........\n");
		else								printf("Error\n");

		/*---- Accept call creates a new socket for the incoming connection ----*/
		addr_size = sizeof serverStorage;
		newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);


// *** ODBIERANIE
recv(clientSocket, buffer_client, 1024, 0);
printf("Data: %s\n",buffer_client);   
		/*---- Send message to the socket of the incoming connection ----*/

		// *** WYSYLANIE
		strcpy(buffer,message);
		//strcpy(buffer, counter_char);
		printf("Message %i to send: %s\n", counter, buffer);
		send(newSocket,buffer,11,0);
		Led(PWM_value);
	}

	return 0;
}
