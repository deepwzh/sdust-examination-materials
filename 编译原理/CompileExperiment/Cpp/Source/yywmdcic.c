/************************************************************
yywmdcic.c
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
YYEXPFUNC(void) YYCDECL yywmcdestructclearin(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywmcdestructclearin(yy)
yywmparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	yyassert(yywmiscompactparser(yy));	/* make sure it's a compact parser */

	if (yy->yymlookahead) {
		/* clean up any token attributes */
		if (yy->yymctokendestptr != NULL) {
			YYCONST yywmctokendest_t YYNEARFAR *tokendestptr = yy->yymctokendestptr;
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
