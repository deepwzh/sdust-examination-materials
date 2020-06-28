/************************************************************
yywmstsz.c
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

#include "yywmlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yywmsettextsize(yywmlexer_t YYFAR *yy, int size)
#else
YYEXPFUNC(YYBOOL) YYCDECL yywmsettextsize(yy, size)
yywmlexer_t YYFAR *yy;
int size;
#endif
{
	yyassert(yy != NULL);
	yyassert(size >= 0);
	if (yy->yymtext_size != size) {
		wchar_t YYFAR *text;
		int YYFAR *statebuf;

		size_t textcharsize;
		size_t statebufcharsize;

		if (size < yy->yymleng) {
			return YYFALSE;
		}

		if (yy->yymtext_max != 0) {
			if (size > yy->yymtext_max) {
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
		if (size <= yy->yymstext_size) {
			text = yy->yymstext;
			statebuf = yy->yymsstatebuf;
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
		if (text != yy->yymtext) {
			size_t charsize = (yy->yymtext_size + 1) * sizeof(wchar_t);
			memcpy(text, yy->yymtext, yymin(textcharsize, charsize));
		}
		if (statebuf != yy->yymstatebuf) {
			size_t charsize = yy->yymtext_size * sizeof(int);
			memcpy(statebuf, yy->yymstatebuf, yymin(statebufcharsize, charsize));
		}

		/* free */
		if (yy->yymtext != yy->yymstext) {
			free(yy->yymtext);
		}
		if (yy->yymstatebuf != yy->yymsstatebuf) {
			free(yy->yymstatebuf);
		}

		/* assign */
		yy->yymtext = text;
		yy->yymstatebuf = statebuf;
		yy->yymtext_size = size;
	}
	return YYTRUE;
}

_YL_END
