/************************************************************
yyamparc.c
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
YYEXPFUNC(int) YYCDECL yymcparse(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(int) YYCDECL yymcparse(yy)
yymparser_t YYFAR *yy;
#endif
{
	int n;
	yyassert(yy != NULL);
	yyassert(yymiscompactparser(yy));	/* make sure it's a compact parser */

	n = yymsetup(yy);
	if (n != 0) {
		return n;
	}
	return yymcwork(yy);
}

_YL_END
