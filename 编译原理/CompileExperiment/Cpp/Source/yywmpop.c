/************************************************************
yywmpop.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yywmpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmpop(yywmparser_t YYFAR *yy, int num)
#else
YYEXPFUNC(void) YYCDECL yywmpop(yy, num)
yywmparser_t YYFAR *yy;
int num;
#endif
{
	yyassert(yy != NULL);
	yyassert(num >= 0);
	yy->yymtop -= num;
	yyassert(yy->yymtop >= -1);

	/* debugging */
	if (yygetglobaldebug() || yy->yymdebug) {
		if (num > 0) {
			wchar_t string[128];

			swprintf(string, L"%p: pop %d state(s)", (void *) yy, (int) num);
			yywmparserdebugoutput(yy, string);
			if (yy->yymtop >= 0) {
				swprintf(string, L" uncovering state %d",
					(int) yy->yymstackptr[yy->yymtop]);
				yywmparserdebugoutput(yy, string);
			}
			yywmparserdebugoutput(yy, L"\n");
		}
	}
}
#endif

_YL_END
