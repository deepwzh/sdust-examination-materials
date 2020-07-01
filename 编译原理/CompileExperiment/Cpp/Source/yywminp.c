/************************************************************
yywminp.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#include <cctype>
#else
#include <stdio.h>
#include <ctype.h>
#endif

#include "yywmlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(yywint_t) YYCDECL yywminput(yywmlexer_t YYFAR *yy)
#else
YYEXPFUNC(yywint_t) YYCDECL yywminput(yy)
yywmlexer_t YYFAR *yy;
#endif
{
	yywint_t ch;
	yyassert(yy != NULL);

	if (yy->yymunputindex > 0) {
		ch = yy->yymunputbufptr[--yy->yymunputindex];
	}
	else {
		ch = (*yy->yymgetchar)(yy);
	}
	if (ch == L'\n') {
		yy->yymlineno++;
	}
	
	/* debugging */
#ifdef YYDEBUG
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];

		swprintf(string, L"%p: input: \'", (void *) yy);
		yywmlexerdebugoutput(yy, string);
		yywmdebugoutput(yy, ch);
		if (ch >= 0) {
			swprintf(string, L"\' (0x%04x)\n", (int) ch);
		}
		else {
		}
		yywmlexerdebugoutput(yy, string);
	}
#endif
	
	return ch;
}

_YL_END
