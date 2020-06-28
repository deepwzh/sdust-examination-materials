/************************************************************
yyamlini.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yymlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yyminitlexer(yymlexer_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yyminitlexer(yy)
yymlexer_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);

	yy->yymin = stdin;
	yy->yymout = stdout;
	yy->yymerr = stderr;
#ifdef YYDEBUG
	yy->yymdebugout = stdout;
#endif
}

_YL_END
