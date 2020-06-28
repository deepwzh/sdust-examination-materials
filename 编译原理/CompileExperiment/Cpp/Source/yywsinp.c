/************************************************************
yywsinp.c
This file can be freely modified for the generation of
custom code.

[Unicode]

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

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
yywint_t YYCDECL yywinput(void)
#else
yywint_t YYCDECL yywinput()
#endif
{
	yywint_t ch;
	if (yywunputindex > 0) {
		ch = yywunputbufptr[--yywunputindex];
	}
	else {
		ch = yywgetchar();
	}
	if (ch == L'\n') {
		yywlineno++;
	}

#ifdef YYDEBUG
	if (yygetglobaldebug() || yywlexerdebug) {
		wchar_t string[128];

		yywlexerdebugoutput(L"input: \'");
		yywdebugoutput(ch);
		if (ch >= 0) {
			swprintf(string, L"\' (0x%04lx)\n", (long) ch);
		}
		else {
			swprintf(string, L"\' (%ld)\n", (long) ch);
		}
		yywlexerdebugoutput(string);
	}
#endif

	return ch;
}

_YL_END

#endif
