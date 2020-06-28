/************************************************************
yywmsin.c
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
YYEXPFUNC(void) YYCDECL yywmsetin(yywmparser_t YYFAR *yy, yywint_t token)
#else
YYEXPFUNC(void) YYCDECL yywmsetin(yy, token)
yywmparser_t YYFAR *yy;
yywint_t token;
#endif
{
	yyassert(yy != NULL);
	if (token < 0) {
		token = 0;
	}
	yy->yymchar = token;
	yy->yymlookahead = YYTRUE;
}

_YL_END
