#pragma once
class client
{
private:

	int sock;
	char buffertosend[9] = " yo node";


public:

	void createsocket();
	void connectnode();
	void senddata();
	void close();
};

