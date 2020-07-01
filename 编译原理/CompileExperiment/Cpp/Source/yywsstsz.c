/************************************************************
yywsstsz.c
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
YYBOOL YYCDECL yywsettextsize(int size)
#else
YYBOOL YYCDECL yywsettextsize(size)
int size;
#endif
{
	yyassert(size >= 0);
	if (yywtext_size != size) {
		wchar_t YYFAR *text;
		int YYFAR *statebuf;

		size_t textcharsize;
		size_t statebufcharsize;

		if (size < yywleng) {
			return YYFALSE;
		}

		if (yywtext_max != 0) {
			if (size > yywtext_max) {
				return YYFALSE;
			}
		}

		textcharsize = (size + 1) * sizeof(wchar_t);	/* include the '\0' */
		if ((int) (textcharsize / sizeof(wchar_t) - 1) != size) {
			return YYFALSE;		/* integer overflow */
		}
		statebufcharsize = size * sizeof(int);
		if ((int) (statebufcharsize / sizeof(int)) != size) {
			return YYFALSE;		/* integer overflow */
		}

		/* allocate */
		if (size <= yywstext_size) {
			text = yywstext;
			statebuf = yywsstatebuf;
		}
		else {
			text = (wchar_t YYFAR *) malloc(textcharsize);
			if (text == NULL) {
				return YYFALSE;
			}
			statebuf = (int YYFAR *) malloc(statebufcharsize);
			if (statebuf == NULL) {
				free(text);			/* clean up */
				return YYFALSE;
			}
		}

		/* copy */
		if (text != yywtext) {
			size_t charsize = (yywtext_size + 1) * sizeof(wchar_t);
			memcpy(text, yywtext, yymin(textcharsize, charsize));
		}
		if (statebuf != yywstatebuf) {
			size_t charsize = yywtext_size * sizeof(int);
			memcpy(statebuf, yywstatebuf, yymin(statebufcharsize, charsize));
		}

		/* free */
		if (yywtext != yywstext) {
			free(yywtext);
		}
		if (yywstatebuf != yywsstatebuf) {
			free(yywstatebuf);
		}

		/* assign */
		yywtext = text;
		yywstatebuf = statebuf;
		yywtext_size = size;
	}
	return YYTRUE;
}

_YL_END

#endif
