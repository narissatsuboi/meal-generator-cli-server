/**
 @file  main.cpp - Driver file which runs the server side of the application. 
 @authors Phuc T, Narissa T
 @date 3/13/22
 @version 3.0
 */

#include "RPCServer.h"
#include <cstdio>       // printf
#include <iostream>     // C++ IO

int main(int argc, char const* argv[])
{
	cout << "main: Starting in main...\n";
	// New server object init. 
	const char* serverIP = argv[1]; // Holds server's IP address. 
	// int port = atoi(argv[2]);       // holds port number. 
	const int port = 10327;

	bool statusOk = true;           // Holds server status, true when server is running. 
	RPCServer* serverObj = new RPCServer(serverIP, port);

	// TODO: Remove later, preprocessor directive is basically a comment block. 
#if 0
	std::vector<std::string> tokArray;
	char buffer[128] = { "connect;mike;mike" };
	serverObj->ParseTokens(buffer, tokArray);
#endif
	// Print it out

	statusOk = serverObj->StartServer();
	while (statusOk)
	{
		statusOk = serverObj->ListenForClient();
		//statusOk = serverObj->ProcessRPC(); // Launch thread
	}

	delete serverObj;
	return 0;
}

//int main(int argc, char const* argv[])
//{
//
//	const char* serverIP = argv[1];
//	int port = atoi(argv[2]);
//
//	bool statusOk = true;
//	RPCServer* serverObj = new RPCServer(serverIP, port);
//
//	// Print it out
//
//	statusOk = serverObj->StartServer();
//	printf("Endless loop, as server is up always");
//	while (statusOk)
//	{
//		statusOk = serverObj->ListenForClient();
//		statusOk = serverObj->ProcessRPC(); // Launch thread
//	}
//
//	delete serverObj;
//	return 0;
//}