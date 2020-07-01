/************************************************************
yyastofw.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#include "yylex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yytextoverflow(void)
#else
void YYCDECL yytextoverflow()
#endif
{
	char string[128];
	sprintf(string, "lexer text buffer overflow (%d)", (int) yytext_size);
	yylexererror(string);
}

_YL_END

#endif
