/************************************************************
yyamdisc.c
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

#ifdef __BORLANDC__
#pragma argsused
#endif

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdiscard(yymparser_t YYFAR *yy, int token)
#else
YYEXPFUNC(void) YYCDECL yymdiscard(yy, token)
yymparser_t YYFAR *yy;
int token;
#endif
{
	yyassert(yy != NULL);
	yyassert(token > 0);
	/* do nothing */
}

_YL_END
