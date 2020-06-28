/************************************************************
yywspar.c
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
int YYCDECL yywparse(void)
#else
int YYCDECL yywparse()
#endif
{
	int n = yywsetup();
	if (n != 0) {
		return n;
	}
	return yywwork();
}

_YL_END

#endif
