/************************************************************
yyamldbg.c
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

#include "yymlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

#ifdef YYWIN32
#include <windows.h>
#include <winbase.h>
#endif

_YL_BEGIN

#ifdef YYDEBUG

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdmatch(yymlexer_t YYFAR *yy, int expr)
#else
YYEXPFUNC(void) YYCDECL yymdmatch(yy, expr)
yymlexer_t YYFAR *yy;
int expr;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];
		int i;

		sprintf(string, "%p: match: \"", (void *) yy);
		yymlexerdebugoutput(yy, string);
		for (i = 0; i < yy->yymleng; i++) {
			yymdebugoutput(yy, yy->yymtext[i]);
		}
		sprintf(string, "\", %d\n", (int) expr);
		yymlexerdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymlexerdebugoutput(yymlexer_t YYFAR *yy, YYCONST char YYFAR *string)
#else
YYEXPFUNC(void) YYCDECL yymlexerdebugoutput(yy, string)
yymlexer_t YYFAR *yy;
YYCONST char YYFAR *string;
#endif
{
	yyassert(yy != NULL);
	yyassert(string != NULL);

#ifdef YYWIN32
	if (yy->yymdebugout != NULL) {
#else
		yyassert(yy->yymdebugout != NULL);
#endif
		while (*string != '\0') {
			putc(*string++, yy->yymdebugout);
		}

		if (yygetglobaldebugflush() || yy->yymdebugflush) {
			fflush(yy->yymdebugout);
		}
#ifdef YYWIN32
	}
	else {
		OutputDebugString(string);
		Sleep(0);		// makes sure debug string is processed
	}
#endif
}

#endif

_YL_END
