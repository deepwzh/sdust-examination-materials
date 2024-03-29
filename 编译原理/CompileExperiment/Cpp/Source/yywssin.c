/************************************************************
yywssin.c
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
void YYCDECL yywsetin(yywint_t token)
#else
void YYCDECL yywsetin(token)
yywint_t token;
#endif
{
	if (token < 0) {
		token = 0;
	}
	yywchar = token;
	yywlookahead = YYTRUE;
}

_YL_END

#endif
