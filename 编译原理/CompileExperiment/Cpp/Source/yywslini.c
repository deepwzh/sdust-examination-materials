/************************************************************
yywslini.c
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
void YYCDECL yywinitlexer(void)
#else
void YYCDECL yywinitlexer()
#endif
{
	yywin = stdin;
	yywout = stdout;
	yywlexererr = stderr;
#ifdef YYDEBUG
	yywlexerdebugout = stdout;
#endif
}

_YL_END

#endif
