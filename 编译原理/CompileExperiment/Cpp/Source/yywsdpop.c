/************************************************************
yywsdpop.c
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
void YYCDECL yywdestructpop(int num)
#else
void YYCDECL yywdestructpop(num)
int num;
#endif
{
	yyassert(num >= 0);
	yyassert(yywtop - num >= -1);

	if (yywdestructorptr != NULL) {
		while (num > 0) {
			yywstack_t state = yywpeek();
			int action = yywdestructorptr[state];
			if (action != -1) {
				/* user actions in here */
				memcpy(yywvalptr, &((char YYFAR *) yywattributestackptr)
					[yywtop * yywattribute_size], yywattribute_size);
				yywpop(1);
				yywparseraction(action);
			}
			else {
				yywpop(1);
			}
			num--;
		}
	}
	else {
		yywpop(num);
	}
}

_YL_END

#endif
