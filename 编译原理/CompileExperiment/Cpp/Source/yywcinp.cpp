/************************************************************
yywcinp.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdio>
#include <cctype>
#else
#include <stdio.h>
#include <ctype.h>
#endif

#include "yywclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

yywint_t yywlexer::yyinput()
{
	yywint_t ch;
	if (yyunputindex > 0) {
		ch = yyunputbufptr[--yyunputindex];
	}
	else {
		ch = yygetchar();
	}
	if (ch == L'\n') {
		yylineno++;
	}

#ifdef YYDEBUG
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];

		swprintf(string, L"%p: input: \'", (void*)this);
		yydebugoutput(string);
		yydebugoutput(ch);
		if (ch >= 0) {
			swprintf(string, L"\' (0x%04lx)\n", (long)ch);
		}
		else {
			swprintf(string, L"\' (%ld)\n", (long)ch);
		}
		yydebugoutput(string);
	}
#endif

	return ch;
}

_YL_END

#endif
