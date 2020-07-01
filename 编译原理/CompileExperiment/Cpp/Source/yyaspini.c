/************************************************************
yyaspini.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#include "yypars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yyinitparser(void)
#else
void YYCDECL yyinitparser()
#endif
{
	yyparsererr = stderr;
#ifdef YYDEBUG
	yyparserdebugout = stdout;
#endif
}

_YL_END

#endif
