/************************************************************
yyamsskp.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yympars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymsetskip(yymparser_t YYFAR *yy, int skip)
#else
YYEXPFUNC(void) YYCDECL yymsetskip(yy, skip)
yymparser_t YYFAR *yy;
int skip;
#endif
{
	yyassert(yy != NULL);
	yyassert(skip >= 0);

	/* debugging */
	if (yygetglobaldebug() || yy->yymdebug) {
		if (skip > 0) {
			if (yy->yymskip == 0) {
				char string[128];

				sprintf(string, "%p: entering error recovery\n", (void *) yy);
				yymparserdebugoutput(yy, string);
			}
		}
		else {
			if (yy->yymskip > 0) {
				char string[128];

				sprintf(string, "%p: leaving error recovery\n", (void *) yy);
				yymparserdebugoutput(yy, string);
			}
		}
	}

	yy->yymskip = skip;
}
#endif

_YL_END
