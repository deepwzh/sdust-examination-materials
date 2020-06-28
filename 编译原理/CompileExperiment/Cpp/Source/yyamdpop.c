/************************************************************
yyamdpop.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#else
#include <string.h>
#endif

#include "yympars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdestructpop(yymparser_t YYFAR *yy, int num)
#else
YYEXPFUNC(void) YYCDECL yymdestructpop(yy, num)
yymparser_t YYFAR *yy;
int num;
#endif
{
	yyassert(yy != NULL);
	yyassert(num >= 0);
	yyassert(yy->yymtop - num >= -1);

	if (yy->yymdestructorptr != NULL) {
		while (num > 0) {
			yystack_t state = yympeek(yy);
			int action = yy->yymdestructorptr[state];
			if (action != -1) {
				/* user actions in here */
				memcpy(yy->yymvalptr, &((char YYFAR *) yy->yymattributestackptr)
					[yy->yymtop * yy->yymattribute_size], yy->yymattribute_size);
				yympop(yy, 1);
				(*yy->yymaction)(yy, action);
			}
			else {
				yympop(yy, 1);
			}
			num--;
		}
	}
	else {
		yympop(yy, num);
	}
}

_YL_END
