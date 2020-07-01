/************************************************************
yyassup.c
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
int YYCDECL yysetup(void)
#else
int YYCDECL yysetup()
#endif
{
	/* initialise variables */
	yytop = -1;
	yylookahead = YYFALSE;
	yyskip = 0;
	yyerrorcount = 0;
	yychar = -1;
	yypopflg = YYFALSE;

	/* push initial state onto the stack */
	if (!yypush(0)) {
#ifdef YYDEBUG
		yydabort();
#endif
		return 1;
	}
	return 0;
}

_YL_END

#endif
