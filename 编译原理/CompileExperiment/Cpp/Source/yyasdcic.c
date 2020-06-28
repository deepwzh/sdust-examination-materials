/************************************************************
yyasdcic.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#else
#include <string.h>
#endif

#include "yypars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yycdestructclearin(void)
#else
void YYCDECL yycdestructclearin()
#endif
{
	if (yylookahead) {
		/* clean up any token attributes */
		if (yyctokendestptr != NULL) {
			YYCONST yyctokendest_t YYNEARFAR *tokendestptr = yyctokendestptr;
			while (tokendestptr->yytoken != -1) {
				if (tokendestptr->yytoken == yychar) {
					/* user actions in here */
					memcpy(yyvalptr, yylvalptr, yyattribute_size);

					yyparseraction(tokendestptr->yyaction);

					memcpy(yylvalptr, yyvalptr, yyattribute_size);								
					break;
				}
				tokendestptr++;
			}
		}
		yylookahead = YYFALSE;
	}
}

_YL_END

#endif
