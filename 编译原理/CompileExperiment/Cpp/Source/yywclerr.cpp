/************************************************************
yywclerr.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void yywlexer::yyerror(const wchar_t YYFAR* text)
{
	yyassert(text != NULL);
	yyassert(yyerr != NULL);
	while (*text != L'\0') {
#ifdef YYSTDCPPLIB
		yyerr->put(*text++);
#else
		putwc(*text++, yyerr);
#endif
	}
#ifdef YYSTDCPPLIB
	yyerr->put(L'\n');
#else
	putwc(L'\n', yyerr);
#endif
}

_YL_END

#endif
