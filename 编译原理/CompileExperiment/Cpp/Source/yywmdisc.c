/************************************************************
yywmdisc.c
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

#ifdef __BORLANDC__
#pragma argsused
#endif

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdiscard(yywmparser_t YYFAR *yy, yywint_t token)
#else
YYEXPFUNC(void) YYCDECL yywmdiscard(yy, token)
yywmparser_t YYFAR *yy;
yywint_t token;
#endif
{
	yyassert(yy != NULL);
	yyassert(token > 0);
	/* do nothing */
}

_YL_END
