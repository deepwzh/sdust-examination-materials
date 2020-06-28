/************************************************************
yyaclerr.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yyclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void yylexer::yyerror(const char YYFAR* text)
{
	yyassert(text != NULL);
	yyassert(yyerr != NULL);
	while (*text != '\0') {
#ifdef YYSTDCPPLIB
		yyerr->put(*text++);
#else
		putc(*text++, yyerr);
#endif
	}
#ifdef YYSTDCPPLIB
	yyerr->put('\n');
#else
	putc('\n', yyerr);
#endif
}

_YL_END

#endif
