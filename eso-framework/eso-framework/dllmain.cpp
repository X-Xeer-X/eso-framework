// dllmain.cpp : Defines the entry point for the DLL application.
#include <windows.h>
#include "EsoMgr.h"

DWORD WINAPI DllOnLoad(LPVOID hModule)
{
	MessageBoxA(0, "DllOnLoad", "", 0);
	EsoMgr::GetSingleton()->Initialize();
	return 0;
}

DWORD WINAPI DllOnUnload(LPVOID dummy)
{
	MessageBoxA(0, "DllOnUnload", "", 0);
	EsoMgr::GetSingleton()->Shutdown();
	return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, DllOnLoad, hModule, 0, 0);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		CreateThread(0, 0, DllOnUnload, hModule, 0, 0);
		break;
	}
	return TRUE;
}

