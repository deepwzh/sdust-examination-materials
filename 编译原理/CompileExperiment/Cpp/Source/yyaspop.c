/************************************************************
yyaspop.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#include "yypars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
void YYCDECL yypop(int num)
#else
void YYCDECL yypop(num)
int num;
#endif
{
	yyassert(num >= 0);
	yytop -= num;
	yyassert(yytop >= -1);

	/* debugging */
	if (yygetglobaldebug() || yyparserdebug) {
		if (num > 0) {
			char string[128];

			sprintf(string, "pop %d state(s)", (int) num);
			yyparserdebugoutput(string);
			if (yytop >= 0) {
				sprintf(string, " uncovering state %d", (int) yystackptr[yytop]);
				yyparserdebugoutput(string);
			}
			yyparserdebugoutput("\n");
		}
	}
}
#endif

_YL_END

#endif
