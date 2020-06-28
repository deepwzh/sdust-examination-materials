/************************************************************
yyasstsz.c
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
YYBOOL YYCDECL yysettextsize(int size)
#else
YYBOOL YYCDECL yysettextsize(size)
int size;
#endif
{
	yyassert(size >= 0);
	if (yytext_size != size) {
		char YYFAR *text;
		int YYFAR *statebuf;

		size_t textcharsize;
		size_t statebufcharsize;

		if (size < yyleng) {
			return YYFALSE;
		}

		if (yytext_max != 0) {
			if (size > yytext_max) {
				return YYFALSE;
			}
		}

		textcharsize = size + 1;	/* include the '\0' */
		if ((int) textcharsize <= size) {
			return YYFALSE;		/* integer overflow */
		}
		statebufcharsize = size * sizeof(int);
		if ((int) (statebufcharsize / sizeof(int)) != size) {
			return YYFALSE;		/* integer overflow */
		}

		/* allocate */
		if (size <= yystext_size) {
			text = yystext;
			statebuf = yysstatebuf;
		}
		else {
			text = (char YYFAR *) malloc(textcharsize);
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
		if (text != yytext) {
			size_t charsize = yytext_size + 1;
			memcpy(text, yytext, yymin(textcharsize, charsize));
		}
		if (statebuf != yystatebuf) {
			size_t charsize = yytext_size * sizeof(int);
			memcpy(statebuf, yystatebuf, yymin(statebufcharsize, charsize));
		}

		/* free */
		if (yytext != yystext) {
			free(yytext);
		}
		if (yystatebuf != yysstatebuf) {
			free(yystatebuf);
		}

		/* assign */
		yytext = text;
		yystatebuf = statebuf;
		yytext_size = size;
	}
	return YYTRUE;
}

_YL_END

#endif
