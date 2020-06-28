/************************************************************
yywsoutp.c
This file can be freely modified for the generation of
custom code.

[Unicode]

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

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yywoutput(yywint_t ch)
#else
void YYCDECL yywoutput(ch)
yywint_t ch;
#endif
{
	/* debugging */
#ifdef YYDEBUG
	if (yygetglobaldebug() || yywlexerdebug) {
		wchar_t string[128];

		yywlexerdebugoutput(L"output: \'");
		yywdebugoutput(ch);
		swprintf(string, L"\' (0x%04lx)\n", (long) ch);
		yywlexerdebugoutput(string);
	}
#endif

	yyassert(yywout != NULL);

	putwc((wchar_t) ch, yywout);
}

_YL_END

#endif
