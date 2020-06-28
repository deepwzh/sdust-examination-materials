/************************************************************
yyamdcic.c
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
YYEXPFUNC(void) YYCDECL yymcdestructclearin(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymcdestructclearin(yy)
yymparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	yyassert(yymiscompactparser(yy));	/* make sure it's a compact parser */

	if (yy->yymlookahead) {
		/* clean up any token attributes */
		if (yy->yymctokendestptr != NULL) {
			YYCONST yymctokendest_t YYNEARFAR *tokendestptr = yy->yymctokendestptr;
			while (tokendestptr->yymtoken != -1) {
				if (tokendestptr->yymtoken == yy->yymchar) {
					/* user actions in here */
					memcpy(yy->yymvalptr, yy->yymlvalptr, yy->yymattribute_size);

					(*yy->yymaction)(yy, tokendestptr->yymaction);

					memcpy(yy->yymlvalptr, yy->yymvalptr, yy->yymattribute_size);								
					break;
				}
				tokendestptr++;
			}
		}
		yy->yymlookahead = YYFALSE;
	}
}

_YL_END
