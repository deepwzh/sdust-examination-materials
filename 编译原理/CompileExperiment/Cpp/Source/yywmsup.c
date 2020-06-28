/************************************************************
yywmsup.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yywmpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yywmsetup(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(int) YYCDECL yywmsetup(yy)
yywmparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);

	/* initialise variables */
	yy->yymtop = -1;
	yy->yymlookahead = YYFALSE;
	yy->yymskip = 0;
	yy->yymerrorcount = 0;
	yy->yymchar = -1;
	yy->yympopflg = YYFALSE;

	/* push initial state onto the stack */
	if (!yywmpush(yy, 0)) {
#ifdef YYDEBUG
		yywmdabort(yy);
#endif
		return 1;
	}
	return 0;
}

_YL_END
