/************************************************************
yywssskp.c
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

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
void YYCDECL yywsetskip(int skip)
#else
void YYCDECL yywsetskip(skip)
int skip;
#endif
{
	yyassert(skip >= 0);

	/* debugging */
	if (yygetglobaldebug() || yywparserdebug) {
		if (skip > 0) {
			if (yywskip == 0) {
				yywparserdebugoutput(L"entering error recovery\n");
			}
		}
		else {
			if (yywskip > 0) {
				yywparserdebugoutput(L"leaving error recovery\n");
			}
		}
	}

	yywskip = skip;
}
#endif

_YL_END

#endif
