/************************************************************
yyasdci.c
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
void YYCDECL yydestructclearin(void)
#else
void YYCDECL yydestructclearin()
#endif
{
	if (yylookahead) {
		/* clean up any token attributes */
		if (yytokendestbaseptr != NULL) {
			int i;
			for (i = 0; i < yytokendestbase_size; i++) {
				int index = yytokendestbaseptr[i] + yychar;
				if (index >= 0 && index < yytokendest_size) {
					if (yytokendestptr[index].yycheck == i) {
						/* user actions in here */
						int action = yytokendestptr[index].yyaction;
						yyassert(action != -1);
						memcpy(yyvalptr, yylvalptr, yyattribute_size);

						yyparseraction(action);

						memcpy(yylvalptr, yyvalptr, yyattribute_size);
					}
				}
			}
		}
		yylookahead = YYFALSE;
	}
}

_YL_END

#endif
