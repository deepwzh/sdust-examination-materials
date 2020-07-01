/************************************************************
yyampop.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yympars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yympop(yymparser_t YYFAR *yy, int num)
#else
YYEXPFUNC(void) YYCDECL yympop(yy, num)
yymparser_t YYFAR *yy;
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
			char string[128];

			sprintf(string, "%p: pop %d state(s)", (void *) yy, (int) num);
			yymparserdebugoutput(yy, string);
			if (yy->yymtop >= 0) {
				sprintf(string, " uncovering state %d",
					(int) yy->yymstackptr[yy->yymtop]);
				yymparserdebugoutput(yy, string);
			}
			yymparserdebugoutput(yy, "\n");
		}
	}
}
#endif

_YL_END
