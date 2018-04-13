#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define QUEUELIMIT 5

int main (int argc, char * argv[]) {

	int serverSocket;
	int clientSocket;
	struct sockaddr_in serverSocketAddr;
	struct sockaddr_in clientSocketAddr;
	unsigned short serverPort;
	unsigned int clientLen;

	if ( argc != 2 ) {
		fprintf(stderr, "argument count mismatch error.\n");
		exit(EXIT_FAILURE);
	}

	if ((serverPort = (unsigned short) atoi(argv[1])) == 0) {
		fprintf(stderr, "invalid port number.\n");
		exit(EXIT_FAILURE);
	}

	if (( serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0 ) {
		perror("socket() failed.");
		exit(EXIT_FAILURE);
	}

	memset( &serverSocketAddr, 0, sizeof(serverSocketAddr));
	serverSocketAddr.sin_family			= AF_INET;
	serverSocketAddr.sin_addr.s_addr	= htonl(INADDR_ANY);
	serverSocketAddr.sin_port			= htons(serverPort);

	if (bind(serverSocket, (struct sockaddr *)&serverSocketAddr, sizeof(serverSocketAddr) ) < 0 ) {
		perror("bind() failed.");
		exit(EXIT_FAILURE);
	}

	if (listen(serverSocket, QUEUELIMIT) < 0) {
		perror("listen() failed.");
		exit(EXIT_FAILURE);
	}

	while(1) {

		clientLen = sizeof(clientSocketAddr);
		if (( clientSocket = accept(serverSocket, (struct sockaddr *)&clientSocketAddr, &clientLen)) < 0 ) {
			printf("%d\n", errno);
			printf("%d\n", clientSocket);
			perror("accept() failed.");
			exit(EXIT_FAILURE);
		}

		printf("conected from %s.\n", inet_ntoa(clientSocketAddr.sin_addr));
		close(clientSocket);
	}

	return 0;
}


