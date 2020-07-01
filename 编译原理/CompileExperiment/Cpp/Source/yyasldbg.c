/************************************************************
yyasldbg.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yylex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

#ifdef YYWIN32
#include <windows.h>
#include <winbase.h>
#endif

_YL_BEGIN

#ifdef YYDEBUG

YYBOOL YYNEAR YYDCDECL yylexerdebug = YYFALSE;
YYBOOL YYNEAR YYDCDECL yylexerdebugflush = YYFALSE;
#ifndef YYNINITSTREAM
FILE YYFAR *YYNEAR YYDCDECL yylexerdebugout = stdout;
#else
FILE YYFAR *YYNEAR YYDCDECL yylexerdebugout = NULL;
#endif

#ifdef YYPROTOTYPE
void YYCDECL yydmatch(int expr)
#else
void YYCDECL yydmatch(expr)
int expr;
#endif
{
	if (yygetglobaldebug() || yylexerdebug) {
		char string[128];
		int i;

		yylexerdebugoutput("match: \"");
		for (i = 0; i < yyleng; i++) {
			yydebugoutput(yytext[i]);
		}
		sprintf(string, "\", %d\n", (int) expr);
		yylexerdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yylexerdebugoutput(YYCONST char YYFAR *string)
#else
void YYCDECL yylexerdebugoutput(string)
YYCONST char YYFAR *string;
#endif
{
	yyassert(string != NULL);

#ifdef YYWIN32
	if (yylexerdebugout != NULL) {
#else
		yyassert(yylexerdebugout != NULL);
#endif
		while (*string != '\0') {
			putc(*string++, yylexerdebugout);
		}

		if (yygetglobaldebugflush() || yylexerdebugflush) {
			fflush(yylexerdebugout);
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

#endif
