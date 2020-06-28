/************************************************************
yywsless.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yywless(int length)
#else
void YYCDECL yywless(length)
int length;
#endif
{
	yyassert(length >= 0 && length <= yywleng);
	while (yywleng > length) {
		yywunput((wchar_t) yywtext[--yywleng]);
	}
	if (yywleng > 0) {
		yyweol = (YYBOOL) (yywtext[yywleng - 1] == L'\n');
	}
	else {
		yyweol = yywoldeol;
	}
}

_YL_END

#endif
