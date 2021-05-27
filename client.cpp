#include "client.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WS2tcpip.h>
#pragma comment (lib,"ws2_32.lib")

void client::createsocket()
{
	sock = socket(AF_INET, SOCK_STREAM, 0);

	if (sock == INVALID_SOCKET)
	{
		printf("socket invalide \n");
	}
	else
	{
		printf("socket cree \n");
	}
}

void client::connectnode()
{
	struct hostent *hostinfo = NULL;
	SOCKADDR_IN sin = { 0 }; /* initialise la structure avec des 0 */
	const char *hostname = "127.0.0.1";

	
/*
	if (hostinfo == NULL) 
	{
		fprintf(stderr, "Unknown host %s.\n", hostname);
		exit(EXIT_FAILURE);
	}
*/
	sin.sin_addr.s_addr = inet_addr(hostname);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(2500); 
	

	if (connect(sock, (SOCKADDR *)&sin, sizeof(SOCKADDR)) == SOCKET_ERROR)
	{
		printf("erreur de connexion \n");
	}
	else
	{
		printf("connecte \n");
	}
}

void client::senddata()
{
	send(sock, buffertosend, strlen(buffertosend), 0);
}

void client::close()
{
	closesocket(sock);
}