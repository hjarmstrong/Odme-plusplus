// odme_dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "odme_dll.h"


// This is an example of an exported variable
ODME_DLL_API int nodme_dll=0;

// This is an example of an exported function.
ODME_DLL_API int fnodme_dll(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see odme_dll.h for the class definition
Codme_dll::Codme_dll()
{
	return;
}
