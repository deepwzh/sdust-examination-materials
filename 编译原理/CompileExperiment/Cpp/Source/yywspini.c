/************************************************************
yywspini.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yywinitparser(void)
#else
void YYCDECL yywinitparser()
#endif
{
	yywparsererr = stderr;
#ifdef YYDEBUG
	yywparserdebugout = stdout;
#endif
}

_YL_END

#endif
