/************************************************************
yyamgetc.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#include <cassert>
#else
#include <stdio.h>
#include <assert.h>
#endif

#include "yymlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yymgetchar(yymlexer_t YYFAR *yy)
#else
YYEXPFUNC(int) YYCDECL yymgetchar(yy)
yymlexer_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	yyassert(yy->yymin != NULL);
	return getc(yy->yymin);
}

_YL_END
