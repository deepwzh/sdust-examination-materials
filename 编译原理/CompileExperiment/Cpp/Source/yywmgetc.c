/************************************************************
yywmgetc.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#include <cassert>
#else
#include <stdio.h>
#include <assert.h>
#endif

#include "yywmlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(yywint_t) YYCDECL yywmgetchar(yywmlexer_t YYFAR *yy)
#else
YYEXPFUNC(yywint_t) YYCDECL yywmgetchar(yy)
yywmlexer_t YYFAR *yy;
#endif
{
	yywint_t wc;
	yyassert(yy != NULL);
	yyassert(yy->yymin != NULL);

	wc = getwc(yy->yymin);

	/* convert WEOF to EOF so that lexer can process input correctly */
	if (wc == WEOF && (feof(yy->yymin) || ferror(yy->yymin))) {
		wc = EOF;
	}
	return wc;
}

_YL_END
