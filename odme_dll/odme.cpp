//precompiled header(mostly dll crap)
#include "stdafx.h"

// Our own class comes first.
#include "odme.h"

#include <string>

// Winsockets need to be linked explicilty
#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>

#include <Windows.h>

// My sad attempt at making this cross platform one day...
#undef ODME_DLL_API
#if defined _WIN64 || defined _WIN32
#define ODME_DLL_API extern "C" __declspec(dllexport)
#elif defined __GNUC__
#define ODME_DLL_API extern "C"
#else
#define ODME_DLL_API extern "C"
#endif
// The one and ONLY constructor
odme::odme(std::string name, std::string ip, int port) : name(name)
{
	WSAData wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		throw(std::string("Error Initalizing Winsockets :(\n Please try agian\n"));

	std::string hostname;
	hostname.reserve(128);
	std::string Address;

	gethostname(&hostname[0], 128);

	this->host = gethostbyname(ip.c_str());
	Address = inet_ntoa(*(in_addr*)host->h_addr_list[0]);

	this->addr.sin_addr.s_addr = inet_addr(Address.c_str());
	this->addr.sin_family = AF_INET;
	this->addr.sin_port = htons(port);

	this->cSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (connect(this->cSock, (SOCKADDR*)&addr, sizeof(addr)) == SOCKET_ERROR)
		exit(1);

	send(this->cSock, ("USER custom 0 0 " + this->name + "\r\n" ).c_str() , strlen( ("USER custom 0 0 " + this->name + "\r\n").c_str() ) , NULL);
	send(this->cSock, ("NICK " + this->name + "\r\n").c_str(), strlen( ("NICK " + this->name + "\r\n" ).c_str() ), NULL);
}

odme::~odme()
{
	closesocket(this->cSock);
}

void odme::join(std::string channel)
{

}