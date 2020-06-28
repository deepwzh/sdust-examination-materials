/************************************************************
yyasperr.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yypars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yyparsererror(YYCONST char YYFAR *text)
#else
void YYCDECL yyparsererror(text)
YYCONST char YYFAR *text;
#endif
{
	yyassert(text != NULL);
	yyassert(yyparsererr != NULL);
	while (*text != '\0') {
		putc(*text++, yyparsererr);
	}
	putc('\n', yyparsererr);
}

_YL_END

#endif
