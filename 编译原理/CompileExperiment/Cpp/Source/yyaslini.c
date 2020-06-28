/************************************************************
yyaslini.c
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
void YYCDECL yyinitlexer(void)
#else
void YYCDECL yyinitlexer()
#endif
{
	yyin = stdin;
	yyout = stdout;
	yylexererr = stderr;
#ifdef YYDEBUG
	yylexerdebugout = stdout;
#endif
}

_YL_END

#endif
