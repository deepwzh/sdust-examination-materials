/************************************************************
yyamperr.c
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

#include "yympars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymparsererror(yymparser_t YYFAR *yy, YYCONST char YYFAR *text)
#else
YYEXPFUNC(void) YYCDECL yymparsererror(yy, text)
yymparser_t YYFAR *yy;
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
