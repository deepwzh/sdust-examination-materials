/************************************************************
yywcsskp.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywcpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
void yywparser::yysetskip(int skip)
{
	yyassert(skip >= 0);

	// debugging
	if (yygetglobaldebug() || yydebug) {
		if (skip > 0) {
			if (yyskip == 0) {
				wchar_t string[128];

				swprintf(string, L"%p: entering error recovery\n", (void*)this);
				yydebugoutput(string);
			}
		}
		else {
			if (yyskip > 0) {
				wchar_t string[128];

				swprintf(string, L"%p: leaving error recovery\n", (void*)this);
				yydebugoutput(string);
			}
		}
	}

	yyskip = skip;
}
#endif

_YL_END

#endif
