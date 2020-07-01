/************************************************************
yywsdisc.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef __BORLANDC__
#pragma argsused
#endif

#ifdef YYPROTOTYPE
void YYCDECL yywdiscard(yywint_t token)
#else
void YYCDECL yywdiscard(token)
yywint_t token;
#endif
{
	yyassert(token > 0);
	/* do nothing */
}

_YL_END

#endif
