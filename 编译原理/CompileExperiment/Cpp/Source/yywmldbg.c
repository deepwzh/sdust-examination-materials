/************************************************************
yywmldbg.c
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

#include "yywmlex.h"

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
YYEXPFUNC(void) YYCDECL yywmdmatch(yywmlexer_t YYFAR *yy, int expr)
#else
YYEXPFUNC(void) YYCDECL yywmdmatch(yy, expr)
yywmlexer_t YYFAR *yy;
int expr;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];
		int i;

		swprintf(string, L"%p: match: \"", (void *) yy);
		yywmlexerdebugoutput(yy, string);
		for (i = 0; i < yy->yymleng; i++) {
			yywmdebugoutput(yy, yy->yymtext[i]);
		}
		swprintf(string, L"\", %d\n", (int) expr);
		yywmlexerdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmlexerdebugoutput(yywmlexer_t YYFAR *yy, YYCONST wchar_t YYFAR *string)
#else
YYEXPFUNC(void) YYCDECL yywmlexerdebugoutput(yy, string)
yywmlexer_t YYFAR *yy;
YYCONST wchar_t YYFAR *string;
#endif
{
	yyassert(yy != NULL);
	yyassert(string != NULL);

#ifdef YYWIN32
	if (yy->yymdebugout != NULL) {
#else
		yyassert(yy->yymdebugout != NULL);
#endif
		while (*string != L'\0') {
			putwc(*string++, yy->yymdebugout);
		}

		if (yygetglobaldebugflush() || yy->yymdebugflush) {
			fflush(yy->yymdebugout);
		}
#ifdef YYWIN32
	}
	else {
		OutputDebugStringW(string);
		Sleep(0);		// makes sure debug string is processed
	}
#endif
}

#endif

_YL_END
