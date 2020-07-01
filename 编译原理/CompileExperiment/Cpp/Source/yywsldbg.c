/************************************************************
yywsldbg.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

#ifdef YYWIN32
#include <windows.h>
#include <winbase.h>
#endif

_YL_BEGIN

#ifdef YYDEBUG

YYBOOL YYNEAR YYDCDECL yywlexerdebug = YYFALSE;
YYBOOL YYNEAR YYDCDECL yywlexerdebugflush = YYFALSE;
#ifndef YYNINITSTREAM
FILE YYFAR *YYNEAR YYDCDECL yywlexerdebugout = stdout;
#else
FILE YYFAR *YYNEAR YYDCDECL yywlexerdebugout = NULL;
#endif

#ifdef YYPROTOTYPE
void YYCDECL yywdmatch(int expr)
#else
void YYCDECL yywdmatch(expr)
int expr;
#endif
{
	if (yygetglobaldebug() || yywlexerdebug) {
		wchar_t string[128];
		int i;

		yywlexerdebugoutput(L"match: \"");
		for (i = 0; i < yywleng; i++) {
			yywdebugoutput(yywtext[i]);
		}
		swprintf(string, L"\", %d\n", (int) expr);
		yywlexerdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yywlexerdebugoutput(YYCONST wchar_t YYFAR *string)
#else
void YYCDECL yywlexerdebugoutput(string)
YYCONST wchar_t YYFAR *string;
#endif
{
	yyassert(string != NULL);

#ifdef YYWIN32
	if (yywlexerdebugout != NULL) {
#else
		yyassert(yywlexerdebugout != NULL);
#endif
		while (*string != L'\0') {
			putwc(*string++, yywlexerdebugout);
		}

		if (yygetglobaldebugflush() || yywlexerdebugflush) {
			fflush(yywlexerdebugout);
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

#endif
