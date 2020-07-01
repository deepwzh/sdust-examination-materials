/************************************************************
yyamoutp.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#include <climits>
#else
#include <stdio.h>
#include <limits.h>
#endif

#include "yymlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymoutput(yymlexer_t YYFAR *yy, int ch)
#else
YYEXPFUNC(void) YYCDECL yymoutput(yy, ch)
yymlexer_t YYFAR *yy;
int ch;
#endif
{
	yyassert(yy != NULL);

	/* debugging */
#ifdef YYDEBUG
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];

		sprintf(string, "%p: output: \'", (void *) yy);
		yymlexerdebugoutput(yy, string);
		yymdebugoutput(yy, ch);
		sprintf(string, "\' (0x%02x)\n", (int) ch);
		yymlexerdebugoutput(yy, string);
	}
#endif

	yyassert(yy->yymout != NULL);

#ifdef __BORLANDC__
	putc((char) ch, yy->yymout);
#else
	putc(ch, yy->yymout);
#endif
}

_YL_END
