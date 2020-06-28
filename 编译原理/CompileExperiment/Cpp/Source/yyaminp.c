/************************************************************
yyaminp.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#include <cctype>
#else
#include <stdio.h>
#include <ctype.h>
#endif

#include "yymlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yyminput(yymlexer_t YYFAR *yy)
#else
YYEXPFUNC(int) YYCDECL yyminput(yy)
yymlexer_t YYFAR *yy;
#endif
{
	int ch;
	yyassert(yy != NULL);

	if (yy->yymunputindex > 0) {
		ch = yy->yymunputbufptr[--yy->yymunputindex];
	}
	else {
		ch = yy->yymgetchar(yy);
	}
	if (ch == '\n') {
		yy->yymlineno++;
	}

	/* debugging */
#ifdef YYDEBUG
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];

		sprintf(string, "%p: input: \'", (void *) yy);
		yymlexerdebugoutput(yy, string);
		yymdebugoutput(yy, ch);
		if (ch >= 0) {
			sprintf(string, "\' (0x%02x)\n", (int) ch);
		}
		else {
			sprintf(string, "\' (%d)\n", (int) ch);
		}
		yymlexerdebugoutput(yy, string);
	}
#endif

	return ch;
}

_YL_END
