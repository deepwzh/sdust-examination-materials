/************************************************************
yywsucin.c
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
YYBOOL YYCDECL yywunclearin(void)
#else
YYBOOL YYCDECL yywunclearin()
#endif
{
	if (!yywlookahead && yywchar != -1) {
		yywlookahead = YYTRUE;
		return YYTRUE;
	}
	return YYFALSE;
}

_YL_END

#endif
