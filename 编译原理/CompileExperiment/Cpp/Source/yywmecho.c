/************************************************************
yywmecho.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywmlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmecho(yywmlexer_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywmecho(yy)
yywmlexer_t YYFAR *yy;
#endif
{
	int i;
	yyassert(yy != NULL);

	for (i = 0; i < yy->yymleng; i++) {
		(*yy->yymoutput)(yy, yy->yymtext[i]);
	}
}

_YL_END
