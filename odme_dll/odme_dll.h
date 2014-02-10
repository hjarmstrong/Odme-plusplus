// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ODME_DLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ODME_DLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef ODME_DLL_EXPORTS
#define ODME_DLL_API __declspec(dllexport)
#else
#define ODME_DLL_API __declspec(dllimport)
#endif

// This class is exported from the odme_dll.dll
class ODME_DLL_API Codme_dll {
public:
	Codme_dll(void);
	// TODO: add your methods here.
};

extern ODME_DLL_API int nodme_dll;

ODME_DLL_API int fnodme_dll(void);
