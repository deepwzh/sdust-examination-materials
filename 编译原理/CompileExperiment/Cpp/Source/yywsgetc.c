/************************************************************
yywsgetc.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
yywint_t YYCDECL yywgetchar(void)
#else
yywint_t YYCDECL yywgetchar()
#endif
{
	yywint_t wc;
	yyassert(yywin != NULL);

	wc = getwc(yywin);

	/* convert WEOF to EOF so that lexer can process input correctly */
	if (wc == WEOF && (feof(yywin) || ferror(yywin))) {
		wc = EOF;
	}
	return wc;
}

_YL_END

#endif
