/************************************************************
yywmlini.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yywmlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywminitlexer(yywmlexer_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywminitlexer(yy)
yywmlexer_t YYFAR *yy;
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
