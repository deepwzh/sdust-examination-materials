/************************************************************
yywmpini.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yywmpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywminitparser(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywminitparser(yy)
yywmparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);

	yy->yymerr = stderr;
#ifdef YYDEBUG
	yy->yymdebugout = stdout;
#endif
}

_YL_END
