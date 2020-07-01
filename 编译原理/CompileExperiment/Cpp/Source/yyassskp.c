/************************************************************
yyassskp.c
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

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
void YYCDECL yysetskip(int skip)
#else
void YYCDECL yysetskip(skip)
int skip;
#endif
{
	yyassert(skip >= 0);

	/* debugging */
	if (yygetglobaldebug() || yyparserdebug) {
		if (skip > 0) {
			if (yyskip == 0) {
				yyparserdebugoutput("entering error recovery\n");
			}
		}
		else {
			if (yyskip > 0) {
				yyparserdebugoutput("leaving error recovery\n");
			}
		}
	}

	yyskip = skip;
}
#endif

_YL_END

#endif
