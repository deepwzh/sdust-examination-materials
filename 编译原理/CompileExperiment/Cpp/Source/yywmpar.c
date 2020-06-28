/************************************************************
yywmpar.c
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
YYEXPFUNC(int) YYCDECL yywmparse(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(int) YYCDECL yywmparse(yy)
yywmparser_t YYFAR *yy;
#endif
{
	int n;
	yyassert(yy != NULL);
	yyassert(yywmisfastparser(yy));	/* make sure it's a fast parser */

	n = yywmsetup(yy);
	if (n != 0) {
		return n;
	}
	return yywmwork(yy);
}

_YL_END
