/************************************************************
yywsgtok.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
yywint_t YYCDECL yywgettoken(void)
#else
yywint_t YYCDECL yywgettoken()
#endif
{
	return yywlex();
}

_YL_END

#endif
