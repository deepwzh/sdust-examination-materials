/************************************************************
yywmparc.c
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
YYEXPFUNC(int) YYCDECL yywmcparse(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(int) YYCDECL yywmcparse(yy)
yywmparser_t YYFAR *yy;
#endif
{
	int n;
	yyassert(yy != NULL);
	yyassert(yywmiscompactparser(yy));	/* make sure it's a compact parser */

	n = yywmsetup(yy);
	if (n != 0) {
		return n;
	}
	return yywmcwork(yy);
}

_YL_END
