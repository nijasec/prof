/* Replace "dll.h" with the name of your header */
#include "cppdll.h"
#include <windows.h>

extern "C" __declspec(dllexport) int start();

DllClass::DllClass()
{

}

DllClass::~DllClass()
{

}

void DllClass::HelloWorld()
{
	MessageBox(0, "Hello World !\n","Hi",MB_ICONINFORMATION);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
		//	DllClass().HelloWorld();
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}

int start()
{
//	DllClass().HelloWorld();
MessageBox(0, "Hello World from DLL!\n","Hi",MB_ICONINFORMATION);
 HWND hwnd = GetDesktopWindow();
	return 0;
	
}
