/************************************************************
yyacpop.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yycpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
void yyparser::yypop(int num)
{
	yyassert(num >= 0);
	yytop -= num;
	yyassert(yytop >= -1);

	// debugging
	if (yygetglobaldebug() || yydebug) {
		if (num > 0) {
			char string[128];

			sprintf(string, "%p: pop %d state(s)", (void*)this, (int)num);
			yydebugoutput(string);
			if (yytop >= 0) {
				sprintf(string, " uncovering state %d", (int)yystackptr[yytop]);
				yydebugoutput(string);
			}
			yydebugoutput("\n");
		}
	}
}
#endif

_YL_END

#endif
