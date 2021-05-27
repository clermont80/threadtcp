#pragma once
#include <string>
class Erreuraccept {};
class ErreurCreation {};
class Erreurbind {};

class server
{
private:

	int port = 2590;
	std::string ip = "192.168.64.183";
	int sock;
	int socketclient;
	char buffer[10];
	int taille = 10;

public:

	void createsocket();
	void connect();
	void receiv();
	void readbuffer();
	void close();



};

