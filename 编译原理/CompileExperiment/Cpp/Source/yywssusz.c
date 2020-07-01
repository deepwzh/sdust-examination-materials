/************************************************************
yywssusz.c
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

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYBOOL YYCDECL yywsetunputsize(int size)
#else
YYBOOL YYCDECL yywsetunputsize(size)
int size;
#endif
{
	yyassert(size >= 0);
	if (yywunput_size != size) {
		yywint_t YYFAR *unputbufptr;

		size_t unputbufcharsize;

		if (size < yywunputindex) {
			return YYFALSE;
		}

		if (yywunput_max != 0) {
			if (size > yywunput_max) {
				return YYFALSE;
			}
		}

		unputbufcharsize = size * sizeof(yywint_t);
		if ((int) (unputbufcharsize / sizeof(yywint_t)) != size) {
			return YYFALSE;		/* integer overflow */
		}

		/* allocate */
		if (size <= yywsunput_size) {
			unputbufptr = yywsunputbufptr;
		}
		else {
			unputbufptr = (yywint_t YYFAR *) malloc(unputbufcharsize);
			if (unputbufptr == NULL) {
				return YYFALSE;
			}
		}

		/* copy */
		if (unputbufptr != yywunputbufptr) {
			size_t charsize = yywunput_size * sizeof(yywint_t);
			memcpy(unputbufptr, yywunputbufptr, yymin(unputbufcharsize, charsize));
		}

		/* free */
		if (yywunputbufptr != yywsunputbufptr) {
			free(yywunputbufptr);
		}

		/* assign */
		yywunputbufptr = unputbufptr;
		yywunput_size = size;
	}
	return YYTRUE;
}

_YL_END

#endif
