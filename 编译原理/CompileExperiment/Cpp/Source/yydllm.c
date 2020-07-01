/************************************************************
yydllm.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yyglobal.h"

#ifdef YYWIN32
#include <windows.h>
#endif

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

#ifdef YYBUILDDLL
#ifdef YYDLLENTRYPOINT
#ifdef YYPROTOTYPE
BOOL WINAPI DllEntryPoint(HANDLE hDLL, DWORD dwReason, LPVOID lpReserved)
#else
BOOL WINAPI DllEntryPoint(hDLL, dwReason, lpReserved)
HANDLE hDLL;
DWORD dwReason;
LPVOID lpReserved;
#endif
#else
#ifdef YYPROTOTYPE
BOOL WINAPI DllMain(HANDLE hDLL, DWORD dwReason, LPVOID lpReserved)
#else
BOOL WINAPI DllMain(hDLL, dwReason, lpReserved)
HANDLE hDLL;
DWORD dwReason;
LPVOID lpReserved;
#endif
#endif
{
	switch (dwReason) {
	case DLL_PROCESS_ATTACH:
		yyinit();
		break;
	case DLL_PROCESS_DETACH:
		yydelete();
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	default:
		break;
	}
	return TRUE;
}
#endif
