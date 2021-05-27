#include <iostream>
#include <thread>
#include "client.h"
#include "server.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <mutex>

void workerThreadsend()
{
	while(1)
	{ 
		Sleep(2000);
		client* clienttcp;
		clienttcp = new client;
		clienttcp->createsocket();
		clienttcp->connectnode();
		clienttcp->senddata();
		clienttcp->close();

		Sleep(2000);
	}
}

void workerThreadreceiv()
{
	while (1)
	{
		server* servertcp;
		servertcp = new server;
		servertcp->createsocket();
		servertcp->connect();
		servertcp->receiv();
		servertcp->close();
		Sleep(2000);
	}
}

int main(int argc, char ** argv)
{
	while (1)	
	{
		std::thread worker(workerThreadreceiv);
		worker.detach();
		std::thread worker2(workerThreadsend);
		worker2.detach();
	}
		

	return 0;
}

