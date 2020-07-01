/************************************************************
yyamsup.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yympars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yymsetup(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(int) YYCDECL yymsetup(yy)
yymparser_t YYFAR *yy;
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
	if (!yympush(yy, 0)) {
#ifdef YYDEBUG
		yymdabort(yy);
#endif
		return 1;
	}
	return 0;
}

_YL_END
