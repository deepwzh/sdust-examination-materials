/************************************************************
yyaslcln.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yylex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yycleanuplexer(void)
#else
void YYCDECL yycleanuplexer()
#endif
{
	if (yytext != yystext) {
		free(yytext);
		yytext = yystext;
	}
	if (yystatebuf != yysstatebuf) {
		free(yystatebuf);
		yystatebuf = yysstatebuf;
	}
	if (yyunputbufptr != yysunputbufptr) {
		free(yyunputbufptr);
		yyunputbufptr = yysunputbufptr;
	}
	yytext_size = yystext_size;
	yyunput_size = yysunput_size;

	if (yytext != NULL) {
		*yytext = '\0';
	}
	yyleng = 0;
	yyunputindex = 0;
}

_YL_END

#endif
