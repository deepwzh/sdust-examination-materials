/************************************************************
yywmwip.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#else
#include <string.h>
#endif

#include "yywmpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmwipe(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywmwipe(yy)
yywmparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	yyassert(yywmisfastparser(yy));	/* make sure it's a fast parser */

	yywmdestructpop(yy, yy->yymtop + 1);
	yywmdestructclearin(yy);
}

_YL_END
