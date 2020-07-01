/************************************************************
yywmsssz.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#include <cstring>
#else
#include <stdlib.h>
#include <string.h>
#endif

#include "yywmpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yywmsetstacksize(yywmparser_t YYFAR *yy, int size)
#else
YYEXPFUNC(YYBOOL) YYCDECL yywmsetstacksize(yy, size)
yywmparser_t YYFAR *yy;
int size;
#endif
{
	yyassert(yy != NULL);
	yyassert(size >= 0);
	if (yy->yymstack_size != size) {
		yywstack_t YYFAR *stackptr;
#if defined(__STDC__) || defined(__cplusplus)
		void YYFAR *attributestackptr;
#else
		char YYFAR *attributestackptr;
#endif
		size_t stackcharsize;
		size_t attributestackcharsize;

		if (size <= yy->yymtop) {
			return YYFALSE;
		}

		if (yy->yymstack_max != 0) {
			if (size > yy->yymstack_max) {
				return YYFALSE;
			}
		}

		stackcharsize = size * sizeof(yywstack_t);
		if ((int) (stackcharsize / sizeof(yywstack_t)) != size) {
			return YYFALSE;		/* integer overflow */
		}
		attributestackcharsize = size * yy->yymattribute_size;
		if ((int) (attributestackcharsize / yy->yymattribute_size) != size) {
			return YYFALSE;		/* integer overflow */
		}

		/* allocate */
		if (size <= yy->yymsstack_size) {
			stackptr = yy->yymsstackptr;
			attributestackptr = yy->yymsattributestackptr;
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
		if (stackptr != yy->yymstackptr) {
			size_t charsize = yy->yymstack_size * sizeof(yywstack_t);
			memcpy(stackptr, yy->yymstackptr, yymin(stackcharsize, charsize));
		}
		if (attributestackptr != yy->yymattributestackptr) {
			size_t charsize = yy->yymstack_size * yy->yymattribute_size;
			memcpy(attributestackptr, yy->yymattributestackptr, yymin(attributestackcharsize,
				charsize));
		}

		/* free */
		if (yy->yymstackptr != yy->yymsstackptr) {
			free(yy->yymstackptr);
		}
		if (yy->yymattributestackptr != yy->yymsattributestackptr) {
			free(yy->yymattributestackptr);
		}

		/* assign */
		yy->yymstackptr = stackptr;
		yy->yymattributestackptr = attributestackptr;
		yy->yymstack_size = size;
	}
	return YYTRUE;
}

_YL_END
