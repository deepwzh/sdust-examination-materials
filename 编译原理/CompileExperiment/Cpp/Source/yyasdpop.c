/************************************************************
yyasdpop.c
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
void YYCDECL yydestructpop(int num)
#else
void YYCDECL yydestructpop(num)
int num;
#endif
{
	yyassert(num >= 0);
	yyassert(yytop - num >= -1);

	if (yydestructorptr != NULL) {
		while (num > 0) {
			yystack_t state = yypeek();
			int action = yydestructorptr[state];
			if (action != -1) {
				/* user actions in here */
				memcpy(yyvalptr, &((char YYFAR *) yyattributestackptr)
					[yytop * yyattribute_size], yyattribute_size);
				yypop(1);
				yyparseraction(action);
			}
			else {
				yypop(1);
			}
			num--;
		}
	}
	else {
		yypop(num);
	}
}

_YL_END

#endif
