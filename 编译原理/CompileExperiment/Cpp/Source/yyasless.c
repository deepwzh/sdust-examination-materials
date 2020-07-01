/************************************************************
yyasless.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#include "yylex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yyless(int length)
#else
void YYCDECL yyless(length)
int length;
#endif
{
	yyassert(length >= 0 && length <= yyleng);
	while (yyleng > length) {
		yyunput((unsigned char) yytext[--yyleng]);
	}
	if (yyleng > 0) {
		yyeol = (YYBOOL) (yytext[yyleng - 1] == '\n');
	}
	else {
		yyeol = yyoldeol;
	}
}

_YL_END

#endif
