/************************************************************
yywmlcln.c
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
YYEXPFUNC(void) YYCDECL yywmcleanuplexer(yywmlexer_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywmcleanuplexer(yy)
yywmlexer_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	if (yy->yymtext != yy->yymstext) {
		free(yy->yymtext);
		yy->yymtext = yy->yymstext;
	}
	if (yy->yymstatebuf != yy->yymsstatebuf) {
		free(yy->yymstatebuf);
		yy->yymstatebuf = yy->yymsstatebuf;
	}
	if (yy->yymunputbufptr != yy->yymsunputbufptr) {
		free(yy->yymunputbufptr);
		yy->yymunputbufptr = yy->yymsunputbufptr;
	}
	yy->yymtext_size = yy->yymstext_size;
	yy->yymunput_size = yy->yymsunput_size;

	if (yy->yymtext != NULL) {
		*yy->yymtext = L'\0';
	}
	yy->yymleng = 0;
	yy->yymunputindex = 0;
}

_YL_END
