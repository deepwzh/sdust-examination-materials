/************************************************************
yywssssz.c
This file can be freely modified for the generation of
custom code.

[Unicode]

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

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYBOOL YYCDECL yywsetstacksize(int size)
#else
YYBOOL YYCDECL yywsetstacksize(size)
int size;
#endif
{
	yyassert(size >= 0);
	if (yywstack_size != size) {
		yywstack_t YYFAR *stackptr;
#if defined(__STDC__) || defined(__cplusplus)
		void YYFAR *attributestackptr;
#else
		char YYFAR *attributestackptr;
#endif
		size_t stackcharsize;
		size_t attributestackcharsize;

		if (size <= yywtop) {
			return YYFALSE;
		}

		if (yywstack_max != 0) {
			if (size > yywstack_max) {
				return YYFALSE;
			}
		}

		stackcharsize = size * sizeof(yywstack_t);
		if ((int) (stackcharsize / sizeof(yywstack_t)) != size) {
			return YYFALSE;		/* integer overflow */
		}
		attributestackcharsize = size * yywattribute_size;
		if ((int) (attributestackcharsize / yywattribute_size) != size) {
			return YYFALSE;		/* integer overflow */
		}

		/* allocate */
		if (size <= yywsstack_size) {
			stackptr = yywsstackptr;
			attributestackptr = yywsattributestackptr;
		}
		else {
			stackptr = (yywstack_t YYFAR *) malloc(stackcharsize);
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
		if (stackptr != yywstackptr) {
			size_t charsize = yywstack_size * sizeof(yywstack_t);
			memcpy(stackptr, yywstackptr, yymin(stackcharsize, charsize));
		}
		if (attributestackptr != yywattributestackptr) {
			size_t charsize = yywstack_size * yywattribute_size;
			memcpy(attributestackptr, yywattributestackptr, yymin(attributestackcharsize,
				charsize));
		}

		/* free */
		if (yywstackptr != yywsstackptr) {
			free(yywstackptr);
		}
		if (yywattributestackptr != yywsattributestackptr) {
			free(yywattributestackptr);
		}

		/* assign */
		yywstackptr = stackptr;
		yywattributestackptr = attributestackptr;
		yywstack_size = size;
	}
	return YYTRUE;
}

_YL_END

#endif
