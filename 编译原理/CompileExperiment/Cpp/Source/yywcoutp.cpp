/************************************************************
yywcoutp.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdio>
#include <climits>
#else
#include <stdio.h>
#include <limits.h>
#endif

#include "yywclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void yywlexer::yyoutput(yywint_t ch)
{
	// debugging
#ifdef YYDEBUG
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];

		swprintf(string, L"%p: output: \'", (void*)this);
		yydebugoutput(string);
		yydebugoutput(ch);
		swprintf(string, L"\' (0x%04lx)\n", (long)ch);
		yydebugoutput(string);
	}
#endif

	yyassert(yyout != NULL);

#ifdef YYSTDCPPLIB
	yyout->put(ch);
#else
	putwc((wchar_t)ch, yyout);
#endif
}

_YL_END

#endif
