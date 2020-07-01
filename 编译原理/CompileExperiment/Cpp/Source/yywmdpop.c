/************************************************************
yywmdpop.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#else
#include <string.h>
#endif

#include "yywmpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdestructpop(yywmparser_t YYFAR *yy, int num)
#else
YYEXPFUNC(void) YYCDECL yywmdestructpop(yy, num)
yywmparser_t YYFAR *yy;
int num;
#endif
{
	yyassert(yy != NULL);
	yyassert(num >= 0);
	yyassert(yy->yymtop - num >= -1);

	if (yy->yymdestructorptr != NULL) {
		while (num > 0) {
			yywstack_t state = yywmpeek(yy);
			int action = yy->yymdestructorptr[state];
			if (action != -1) {
				/* user actions in here */
				memcpy(yy->yymvalptr, &((char YYFAR *) yy->yymattributestackptr)
					[yy->yymtop * yy->yymattribute_size], yy->yymattribute_size);
				yywmpop(yy, 1);
				(*yy->yymaction)(yy, action);
			}
			else {
				yywmpop(yy, 1);
			}
			num--;
		}
	}
	else {
		yywmpop(yy, num);
	}
}

_YL_END
