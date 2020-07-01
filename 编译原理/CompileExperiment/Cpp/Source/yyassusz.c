/************************************************************
yyassusz.c
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

#include "yylex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYBOOL YYCDECL yysetunputsize(int size)
#else
YYBOOL YYCDECL yysetunputsize(size)
int size;
#endif
{
	yyassert(size >= 0);
	if (yyunput_size != size) {
		int YYFAR *unputbufptr;

		size_t unputbufcharsize;

		if (size < yyunputindex) {
			return YYFALSE;
		}

		if (yyunput_max != 0) {
			if (size > yyunput_max) {
				return YYFALSE;
			}
		}

		unputbufcharsize = size * sizeof(int);
		if ((int) (unputbufcharsize / sizeof(int)) != size) {
			return YYFALSE;		/* integer overflow */
		}

		/* allocate */
		if (size <= yysunput_size) {
			unputbufptr = yysunputbufptr;
		}
		else {
			unputbufptr = (int YYFAR *) malloc(unputbufcharsize);
			if (unputbufptr == NULL) {
				return YYFALSE;
			}
		}

		/* copy */
		if (unputbufptr != yyunputbufptr) {
			size_t charsize = yyunput_size * sizeof(int);
			memcpy(unputbufptr, yyunputbufptr, yymin(unputbufcharsize, charsize));
		}

		/* free */
		if (yyunputbufptr != yysunputbufptr) {
			free(yyunputbufptr);
		}

		/* assign */
		yyunputbufptr = unputbufptr;
		yyunput_size = size;
	}
	return YYTRUE;
}

_YL_END

#endif
