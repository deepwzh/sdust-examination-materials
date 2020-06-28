/************************************************************
yywsdci.c
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
void YYCDECL yywdestructclearin(void)
#else
void YYCDECL yywdestructclearin()
#endif
{
	if (yywlookahead) {
		/* clean up any token attributes */
		if (yywtokendestbaseptr != NULL) {
			int i;
			for (i = 0; i < yywtokendestbase_size; i++) {
				long index = yywtokendestbaseptr[i] + yywchar;
				if (index >= 0 && index < yywtokendest_size) {
					if (yywtokendestptr[index].yycheck == i) {
						/* user actions in here */
						int action = yywtokendestptr[index].yyaction;
						yyassert(action != -1);
						memcpy(yywvalptr, yywlvalptr, yywattribute_size);

						yywparseraction(action);

						memcpy(yywlvalptr, yywvalptr, yywattribute_size);
					}
				}
			}
		}
		yywlookahead = YYFALSE;
	}
}

_YL_END

#endif
