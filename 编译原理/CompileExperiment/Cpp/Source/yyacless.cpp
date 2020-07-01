/************************************************************
yyacless.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yyclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void yylexer::yyless(int length)
{
	yyassert(length >= 0 && length <= yyleng);
	while (yyleng > length) {
		yyunput((unsigned char)yytext[--yyleng]);
	}
	if (yyleng > 0) {
		yyeol = (yybool)(yytext[yyleng - 1] == '\n');
	}
	else {
		yyeol = yyoldeol;
	}
}

_YL_END

#endif
