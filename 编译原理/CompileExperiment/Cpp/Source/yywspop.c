/************************************************************
yywspop.c
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

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
void YYCDECL yywpop(int num)
#else
void YYCDECL yywpop(num)
int num;
#endif
{
	yyassert(num >= 0);
	yywtop -= num;
	yyassert(yywtop >= -1);

	/* debugging */
	if (yygetglobaldebug() || yywparserdebug) {
		if (num > 0) {
			wchar_t string[128];

			swprintf(string, L"pop %d state(s)", (int) num);
			yywparserdebugoutput(string);
			if (yywtop >= 0) {
				swprintf(string, L" uncovering state %d", (int) yywstackptr[yywtop]);
				yywparserdebugoutput(string);
			}
			yywparserdebugoutput(L"\n");
		}
	}
}
#endif

_YL_END

#endif
