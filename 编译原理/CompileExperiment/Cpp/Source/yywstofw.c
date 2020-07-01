/************************************************************
yywstofw.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yywtextoverflow(void)
#else
void YYCDECL yywtextoverflow()
#endif
{
	wchar_t string[128];
	swprintf(string, L"lexer text buffer overflow (%d)\n", (int) yywtext_size);
	yywlexererror(string);
}

_YL_END

#endif
