/************************************************************
yyamdci.c
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
YYEXPFUNC(void) YYCDECL yymdestructclearin(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymdestructclearin(yy)
yymparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	yyassert(yymisfastparser(yy));	/* make sure it's a fast parser */

	if (yy->yymlookahead) {
		/* clean up any token attributes */
		if (yy->yymtokendestbaseptr != NULL) {
			int i;
			for (i = 0; i < yy->yymtokendestbase_size; i++) {
				int index = yy->yymtokendestbaseptr[i] + yy->yymchar;
				if (index >= 0 && index < yy->yymtokendest_size) {
					if (yy->yymtokendestptr[index].yymcheck == i) {
						/* user actions in here */
						int action = yy->yymtokendestptr[index].yymaction;
						yyassert(action != -1);
						memcpy(yy->yymvalptr, yy->yymlvalptr, yy->yymattribute_size);

						(*yy->yymaction)(yy, action);

						memcpy(yy->yymlvalptr, yy->yymvalptr, yy->yymattribute_size);
					}
				}
			}
		}
		yy->yymlookahead = YYFALSE;
	}
}

_YL_END
