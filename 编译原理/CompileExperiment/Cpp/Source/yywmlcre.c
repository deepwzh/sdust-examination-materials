/************************************************************
yywmlcre.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yywmlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yywmcreatelexer(yywmlexer_t YYFAR *yy, YYCONST yywmlexer_t YYFAR *src)
#else
YYEXPFUNC(YYBOOL) YYCDECL yywmcreatelexer(yy, src)
yywmlexer_t YYFAR *yy;
YYCONST yywmlexer_t YYFAR *src;
#endif
{
	size_t textcharsize;
	size_t statebufcharsize;
	size_t unputbufcharsize;
	yyassert(yy != NULL);
	yyassert(src != NULL);

	*yy = *src;

	/* get sizes first */
	textcharsize = (yy->yymstext_size + 1) * sizeof(wchar_t);	/* include the '\0' */
	if ((int) (textcharsize / sizeof(wchar_t) - 1) != yy->yymstext_size) {
		return YYFALSE;		/* integer overflow */
	}
	if (yy->yymstext_size != 0) {
		statebufcharsize = yy->yymstext_size * sizeof(int);
		if ((int) (statebufcharsize / sizeof(int)) != yy->yymstext_size) {
			return YYFALSE;		/* integer overflow */
		}
	}
	else {
		statebufcharsize = 0;
	}
	if (yy->yymsunput_size != 0) {
		unputbufcharsize = yy->yymsunput_size * sizeof(yywint_t);
		if ((int) (unputbufcharsize / sizeof(yywint_t)) != yy->yymsunput_size) {
			return YYFALSE;		/* integer overflow */
		}
	}
	else {
		unputbufcharsize = 0;
	}

	/* allocate the memory if necessary */
	yy->yymstext = (wchar_t YYFAR *) malloc(textcharsize);
	if (yy->yymstext == NULL) {
		return YYFALSE;
	}
	if (statebufcharsize != 0) {
		yy->yymsstatebuf = (int YYFAR *) malloc(statebufcharsize);
		if (yy->yymsstatebuf == NULL) {
			free(yy->yymstext);
			return YYFALSE;
		}
	}
	else {
		yy->yymsstatebuf = NULL;
	}
	if (unputbufcharsize != 0) {
		yy->yymsunputbufptr = (yywint_t YYFAR *) malloc(unputbufcharsize);
		if (yy->yymsunputbufptr == NULL) {
			free(yy->yymstext);
			free(yy->yymsstatebuf);
			return YYFALSE;
		}
	}
	else {
		yy->yymsunputbufptr = NULL;
	}

	/* assign any other variables */
	yy->yymtext_size = yy->yymstext_size;
	yy->yymtext = yy->yymstext;
	yy->yymstatebuf = yy->yymsstatebuf;
	yy->yymunput_size = yy->yymsunput_size;
	yy->yymunputbufptr = yy->yymsunputbufptr;

	/* make sure we are ready to go */
	yywmreset(yy);

	return YYTRUE;
}

_YL_END
