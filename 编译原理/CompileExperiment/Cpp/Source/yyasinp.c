/************************************************************
yyasinp.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#include <cctype>
#else
#include <stdio.h>
#include <ctype.h>
#endif

#include "yylex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
int YYCDECL yyinput(void)
#else
int YYCDECL yyinput()
#endif
{
	int ch;
	if (yyunputindex > 0) {
		ch = yyunputbufptr[--yyunputindex];
	}
	else {
		ch = yygetchar();
	}
	if (ch == '\n') {
		yylineno++;
	}

#ifdef YYDEBUG
	if (yygetglobaldebug() || yylexerdebug) {
		char string[128];

		yylexerdebugoutput("input: \'");
		yydebugoutput(ch);
		if (ch >= 0) {
			sprintf(string, "\' (0x%02x)\n", (int) ch);
		}
		else {
			sprintf(string, "\' (%d)\n", (int) ch);
		}
		yylexerdebugoutput(string);
	}
#endif

	return ch;
}

_YL_END

#endif
