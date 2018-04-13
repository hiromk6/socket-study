#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MSGSIZE 32
#define MAX_MSGSIZE 1024
#define BUFSIZE (MSGSIZE + 1)

int main (int argc, char * argv[]) {

	int sock;
	struct sockaddr_in serverSocketAddr;
	unsigned short serverPort;
	char recvBuffer[BUFSIZE];
	int byteRcvd, totalBytesRcvd;

	if ( argc != 3 ) {
		fprintf(stderr, "argument count mismatch error.\n");
		exit(EXIT_FAILURE);
	}

	memset(&serverSocketAddr, 0, sizeof(serverSocketAddr));
	serverSocketAddr.sin_family = AF_INET;

	if (inet_aton(argv[1], &serverSocketAddr.sin_addr) == 0) {
		fprintf(stderr, "invalid IP Address.\n");
		exit(EXIT_FAILURE);
	}

	if ((serverPort = (unsigned short) atoi(argv[2])) == 0) {
		fprintf(stderr, "invalid port number.\n");
		exit(EXIT_FAILURE);
	}
	serverSocketAddr.sin_port = htons(serverPort);

	if (( sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0 ) {
		perror("socket() failed.");
		exit(EXIT_FAILURE);
	}

	if (connect(sock, (struct sockaddr*)&serverSocketAddr, sizeof(serverSocketAddr)) < 0) {
		perror("connect() failed.");
		exit(EXIT_FAILURE);
	}

	printf("connect to %s\n", inet_ntoa(serverSocketAddr.sin_addr));

	totalBytesRcvd = 0;	

	while(totalBytesRcvd < MAX_MSGSIZE) {

		if ((byteRcvd = recv(sock, recvBuffer, MSGSIZE, 0)) > 0 ){
			recvBuffer[byteRcvd] = '\0';
			printf("%s", recvBuffer);
			totalBytesRcvd += byteRcvd;
		} else if(byteRcvd == 0) {
			perror("ERR_EMPTY_RESPONSE");
			exit(EXIT_FAILURE);
		} else {
			perror("recv() failed.");
			exit(EXIT_FAILURE);
		}
	}

	printf("\n");
	close(sock);

	return EXIT_SUCCESS;
}


