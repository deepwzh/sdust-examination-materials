/************************************************************
yyamwipc.c
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
YYEXPFUNC(void) YYCDECL yymcwipe(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymcwipe(yy)
yymparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	yyassert(yymiscompactparser(yy));	/* make sure it's a compact parser */

	yymdestructpop(yy, yy->yymtop + 1);
	yymcdestructclearin(yy);
}

_YL_END
