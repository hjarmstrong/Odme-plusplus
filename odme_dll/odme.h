#ifndef ODME_H
#define ODME_H
/*

	Here we define our direct interfaces with odme, every instance must pass a name
	There is no default constructor for this reason.

*/

#include <string>

#define ODME_DLL_API __declspec(dllexport)

class odme
{
public:
	//The one and only constructor
	ODME_DLL_API odme(std::string name);

	ODME_DLL_API virtual ~odme();

	ODME_DLL_API void connect(std::string ip, std::string port = "6667");


private:
	bool isconected = false;
	const std::string name;
};

#endif