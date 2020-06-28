/************************************************************
yywslcln.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yywcleanuplexer(void)
#else
void YYCDECL yywcleanuplexer()
#endif
{
	if (yywtext != yywstext) {
		free(yywtext);
		yywtext = yywstext;
	}
	if (yywstatebuf != yywsstatebuf) {
		free(yywstatebuf);
		yywstatebuf = yywsstatebuf;
	}
	if (yywunputbufptr != yywsunputbufptr) {
		free(yywunputbufptr);
		yywunputbufptr = yywsunputbufptr;
	}
	yywtext_size = yywstext_size;
	yywunput_size = yywsunput_size;

	if (yywtext != NULL) {
		*yywtext = L'\0';
	}
	yywleng = 0;
	yywunputindex = 0;
}

_YL_END

#endif
