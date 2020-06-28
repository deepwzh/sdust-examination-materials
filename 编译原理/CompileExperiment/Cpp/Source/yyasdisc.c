/************************************************************
yyasdisc.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yypars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef __BORLANDC__
#pragma argsused
#endif

#ifdef YYPROTOTYPE
void YYCDECL yydiscard(int token)
#else
void YYCDECL yydiscard(token)
int token;
#endif
{
	yyassert(token > 0);
	/* do nothing */
}

_YL_END

#endif
