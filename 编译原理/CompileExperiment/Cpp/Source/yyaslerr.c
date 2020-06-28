/************************************************************
yyaslerr.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yylex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yylexererror(YYCONST char YYFAR *text)
#else
void YYCDECL yylexererror(text)
YYCONST char YYFAR *text;
#endif
{
	yyassert(text != NULL);
	yyassert(yylexererr != NULL);
	while (*text != '\0') {
		putc(*text++, yylexererr);
	}
	putc('\n', yylexererr);
}

_YL_END

#endif
