//precompiled header
#include "stdafx.h"

#include "odme.h"
#include <string>
#define ODME_DLL_API extern "C" __declspec(dllexport)


odme::odme(std::string name) : name(name) {}

odme::~odme() {}

void odme::connect(std::string ip, std::string port)
{

}