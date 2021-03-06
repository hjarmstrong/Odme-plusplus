#ifndef ODME_H
#define ODME_H
/*

	Here we define our direct interfaces with odme, every instance must pass a name
	There is no default constructor for this reason.

*/

#include <string>

#include <WinSock2.h>
#include <Windows.h>

#if defined _WIN64 || defined _WIN32
#define ODME_DLL_API __declspec(dllexport)
#else
#define ODME_DLL_API   // As far as I know on g++ we only need to get Public in the definition.
#endif

class odme
{
public:
	//The one and only constructor
	ODME_DLL_API odme(std::string name, std::string ip, int port = 6667);

	//We close our sockets when deleted.
	ODME_DLL_API virtual ~odme();

	ODME_DLL_API void join(std::string channel);


private:
	//Used by status function
	bool isconected = false;
	const std::string name;

	SOCKET cSock;
	HOSTENT *host;
	SOCKADDR_IN addr;
};

#endif