/************************************************************
yyampar.c
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
YYEXPFUNC(int) YYCDECL yymparse(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(int) YYCDECL yymparse(yy)
yymparser_t YYFAR *yy;
#endif
{
	int n;
	yyassert(yy != NULL);
	yyassert(yymisfastparser(yy));	/* make sure it's a fast parser */

	n = yymsetup(yy);
	if (n != 0) {
		return n;
	}
	return yymwork(yy);
}

_YL_END
