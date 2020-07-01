/************************************************************
yywmsskp.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywmpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmsetskip(yywmparser_t YYFAR *yy, int skip)
#else
YYEXPFUNC(void) YYCDECL yywmsetskip(yy, skip)
yywmparser_t YYFAR *yy;
int skip;
#endif
{
	yyassert(yy != NULL);
	yyassert(skip >= 0);

	/* debugging */
	if (yygetglobaldebug() || yy->yymdebug) {
		if (skip > 0) {
			if (yy->yymskip == 0) {
				wchar_t string[128];

				swprintf(string, L"%p: entering error recovery\n", (void *) yy);
				yywmparserdebugoutput(yy, string);
			}
		}
		else {
			if (yy->yymskip > 0) {
				wchar_t string[128];

				swprintf(string, L"%p: leaving error recovery\n", (void *) yy);
				yywmparserdebugoutput(yy, string);
			}
		}
	}

	yy->yymskip = skip;
}
#endif

_YL_END
