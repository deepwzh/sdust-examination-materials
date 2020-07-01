/************************************************************
yyasoutp.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#include <climits>
#else
#include <stdio.h>
#include <limits.h>
#endif

#include "yylex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yyoutput(int ch)
#else
void YYCDECL yyoutput(ch)
int ch;
#endif
{
	/* debugging */
#ifdef YYDEBUG
	if (yygetglobaldebug() || yylexerdebug) {
		char string[128];

		yylexerdebugoutput("output: \'");
		yydebugoutput(ch);
		sprintf(string, "\' (0x%02x)\n", (int) ch);
		yylexerdebugoutput(string);
	}
#endif

	yyassert(yyout != NULL);

#ifdef __BORLANDC__
	putc((char) ch, yyout);
#else
	putc(ch, yyout);
#endif
}

_YL_END

#endif
