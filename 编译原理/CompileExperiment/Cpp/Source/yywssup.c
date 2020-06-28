/************************************************************
yywssup.c
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
int YYCDECL yywsetup(void)
#else
int YYCDECL yywsetup()
#endif
{
	/* initialise variables */
	yywtop = -1;
	yywlookahead = YYFALSE;
	yywskip = 0;
	yywerrorcount = 0;
	yywchar = -1;
	yywpopflg = YYFALSE;

	/* push initial state onto the stack */
	if (!yywpush(0)) {
#ifdef YYDEBUG
		yywdabort();
#endif
		return 1;
	}
	return 0;
}

_YL_END

#endif
