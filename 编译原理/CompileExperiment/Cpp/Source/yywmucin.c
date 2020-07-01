/************************************************************
yywmucin.c
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
YYEXPFUNC(YYBOOL) YYCDECL yywmunclearin(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(YYBOOL) YYCDECL yywmunclearin(yy)
yywmparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	if (!yy->yymlookahead && yy->yymchar != -1) {
		yy->yymlookahead = YYTRUE;
		return YYTRUE;
	}
	return YYFALSE;
}

_YL_END
