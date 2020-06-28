/************************************************************
yywmoutp.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#include <climits>
#else
#include <stdio.h>
#include <limits.h>
#endif

#include "yywmlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmoutput(yywmlexer_t YYFAR *yy, yywint_t ch)
#else
YYEXPFUNC(void) YYCDECL yywmoutput(yy, ch)
yywmlexer_t YYFAR *yy;
yywint_t ch;
#endif
{
	yyassert(yy != NULL);

	/* debugging */
#ifdef YYDEBUG
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];

		swprintf(string, L"%p: output: \'", (void *) yy);
		yywmlexerdebugoutput(yy, string);
		yywmdebugoutput(yy, ch);
		swprintf(string, L"\' (0x%04lx)\n", (long) ch);
		yywmlexerdebugoutput(yy, string);
	}
#endif

	yyassert(yy->yymout != NULL);

	putwc((wchar_t) ch, yy->yymout);
}

_YL_END
