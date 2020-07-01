/************************************************************
yywssofw.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yywstackoverflow(void)
#else
void YYCDECL yywstackoverflow()
#endif
{
	wchar_t string[128];
	swprintf(string, L"parser stack overflow (%d)", (int) yywstack_size);
	yywparsererror(string);
}

_YL_END

#endif
