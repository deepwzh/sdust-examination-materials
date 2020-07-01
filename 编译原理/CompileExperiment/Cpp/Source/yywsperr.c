/************************************************************
yywsperr.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yywparsererror(YYCONST wchar_t YYFAR *text)
#else
void YYCDECL yywparsererror(text)
YYCONST wchar_t YYFAR *text;
#endif
{
	yyassert(text != NULL);
	yyassert(yywparsererr != NULL);
	while (*text != L'\0') {
		putwc(*text++, yywparsererr);
	}
	putwc(L'\n', yywparsererr);
}

_YL_END

#endif
