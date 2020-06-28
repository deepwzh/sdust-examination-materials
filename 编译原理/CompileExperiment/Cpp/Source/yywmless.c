/************************************************************
yywmless.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yywmlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmless(yywmlexer_t YYFAR *yy, int length)
#else
YYEXPFUNC(void) YYCDECL yywmless(yy, length)
yywmlexer_t YYFAR *yy;
int length;
#endif
{
	yyassert(yy != NULL);
	yyassert(length >= 0 && length <= yy->yymleng);
	while (yy->yymleng > length) {
		(*yy->yymunput)(yy, (wchar_t) yy->yymtext[--yy->yymleng]);
	}
	if (yy->yymleng > 0) {
		yy->yymeol = (YYBOOL) (yy->yymtext[yy->yymleng - 1] == L'\n');
	}
	else {
		yy->yymeol = yy->yymoldeol;
	}
}

_YL_END
