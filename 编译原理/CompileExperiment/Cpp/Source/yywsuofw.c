/************************************************************
yywsuofw.c
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
void YYCDECL yywunputoverflow(void)
#else
void YYCDECL yywunputoverflow()
#endif
{
	wchar_t string[128];
	yyassert(yywlexererr != NULL);
	swprintf(string, L"lexer unput buffer overflow (%d)", (int) yywunput_size);
	yywlexererror(string);
}

_YL_END

#endif
