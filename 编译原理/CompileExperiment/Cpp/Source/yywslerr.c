/************************************************************
yywslerr.c
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

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yywlexererror(YYCONST wchar_t YYFAR *text)
#else
void YYCDECL yywlexererror(text)
YYCONST wchar_t YYFAR *text;
#endif
{
	yyassert(text != NULL);
	yyassert(yywlexererr != NULL);
	while (*text != L'\0') {
		putwc(*text++, yywlexererr);
	}
	putwc(L'\n', yywlexererr);
}

_YL_END

#endif
