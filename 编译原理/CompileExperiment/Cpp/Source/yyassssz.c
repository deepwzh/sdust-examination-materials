/************************************************************
yyassssz.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#include <cstring>
#else
#include <stdlib.h>
#include <string.h>
#endif

#include "yypars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYBOOL YYCDECL yysetstacksize(int size)
#else
YYBOOL YYCDECL yysetstacksize(size)
int size;
#endif
{
	yyassert(size >= 0);
	if (yystack_size != size) {
		yystack_t YYFAR *stackptr;
#if defined(__STDC__) || defined(__cplusplus)
		void YYFAR *attributestackptr;
#else
		char YYFAR *attributestackptr;
#endif
		size_t stackcharsize;
		size_t attributestackcharsize;

		if (size <= yytop) {
			return YYFALSE;
		}

		if (yystack_max != 0) {
			if (size > yystack_max) {
				return YYFALSE;
			}
		}

		stackcharsize = size * sizeof(yystack_t);
		if ((int) (stackcharsize / sizeof(yystack_t)) != size) {
			return YYFALSE;		/* integer overflow */
		}
		attributestackcharsize = size * yyattribute_size;
		if ((int) (attributestackcharsize / yyattribute_size) != size) {
			return YYFALSE;		/* integer overflow */
		}

		/* allocate */
		if (size <= yysstack_size) {
			stackptr = yysstackptr;
			attributestackptr = yysattributestackptr;
		}
		else {
			stackptr = (yystack_t YYFAR *) malloc(stackcharsize);
			if (stackptr == NULL) {
				return YYFALSE;
			}
			attributestackptr = malloc(attributestackcharsize);
			if (attributestackptr == NULL) {
				free(stackptr);		/* clean up */
				return YYFALSE;
			}
		}

		/* copy */
		if (stackptr != yystackptr) {
			size_t charsize = yystack_size * sizeof(yystack_t);
			memcpy(stackptr, yystackptr, yymin(stackcharsize, charsize));
		}
		if (attributestackptr != yyattributestackptr) {
			size_t charsize = yystack_size * yyattribute_size;
			memcpy(attributestackptr, yyattributestackptr, yymin(attributestackcharsize,
				charsize));
		}

		/* free */
		if (yystackptr != yysstackptr) {
			free(yystackptr);
		}
		if (yyattributestackptr != yysattributestackptr) {
			free(yyattributestackptr);
		}

		/* assign */
		yystackptr = stackptr;
		yyattributestackptr = attributestackptr;
		yystack_size = size;
	}
	return YYTRUE;
}

_YL_END

#endif
