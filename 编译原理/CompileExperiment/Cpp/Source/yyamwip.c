/************************************************************
yyamwip.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#else
#include <string.h>
#endif

#include "yympars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymwipe(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymwipe(yy)
yymparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	yyassert(yymisfastparser(yy));	/* make sure it's a fast parser */

	yymdestructpop(yy, yy->yymtop + 1);
	yymdestructclearin(yy);
}

_YL_END
