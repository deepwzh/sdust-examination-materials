/************************************************************
yywmgtok.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yywmpars.h"
#include "yywmlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(yywint_t) YYCDECL yywmgettoken(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(yywint_t) YYCDECL yywmgettoken(yy)
yywmparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	yyassert(yy->yymlexerptr != NULL);
	return yywmlex(yy->yymlexerptr);
}

_YL_END
