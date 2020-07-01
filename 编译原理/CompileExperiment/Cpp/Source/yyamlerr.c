/************************************************************
yyamlerr.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yymlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymlexererror(yymlexer_t YYFAR *yy, YYCONST char YYFAR *text)
#else
YYEXPFUNC(void) YYCDECL yymlexererror(yy, text)
yymlexer_t YYFAR *yy;
YYCONST char YYFAR *text;
#endif
{
	yyassert(yy != NULL);
	yyassert(text != NULL);
	yyassert(yy->yymerr != NULL);
	while (*text != '\0') {
		putc(*text++, yy->yymerr);
	}
	putc('\n', yy->yymerr);
}

_YL_END
