/************************************************************
yywcpop.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yywcpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
void yywparser::yypop(int num)
{
	yyassert(num >= 0);
	yytop -= num;
	yyassert(yytop >= -1);

	// debugging
	if (yygetglobaldebug() || yydebug) {
		if (num > 0) {
			wchar_t string[128];

			swprintf(string, L"%p: pop %d state(s)", (void*)this, (int)num);
			yydebugoutput(string);
			if (yytop >= 0) {
				swprintf(string, L" uncovering state %d", (int)yystackptr[yytop]);
				yydebugoutput(string);
			}
			yydebugoutput(L"\n");
		}
	}
}
#endif

_YL_END

#endif
