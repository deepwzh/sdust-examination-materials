/************************************************************
yywsdcic.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#else
#include <string.h>
#endif

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yywcdestructclearin(void)
#else
void YYCDECL yywcdestructclearin()
#endif
{
	if (yywlookahead) {
		/* clean up any token attributes */
		if (yywctokendestptr != NULL) {
			YYCONST yywctokendest_t YYNEARFAR *tokendestptr = yywctokendestptr;
			while (tokendestptr->yytoken != -1) {
				if (tokendestptr->yytoken == yywchar) {
					/* user actions in here */
					memcpy(yywvalptr, yywlvalptr, yywattribute_size);

					yywparseraction(tokendestptr->yyaction);

					memcpy(yywlvalptr, yywvalptr, yywattribute_size);								
					break;
				}
				tokendestptr++;
			}
		}
		yywlookahead = YYFALSE;
	}
}

_YL_END

#endif
