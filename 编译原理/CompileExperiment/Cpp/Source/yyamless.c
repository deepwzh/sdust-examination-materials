/************************************************************
yyamless.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yymlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymless(yymlexer_t YYFAR *yy, int length)
#else
YYEXPFUNC(void) YYCDECL yymless(yy, length)
yymlexer_t YYFAR *yy;
int length;
#endif
{
	yyassert(yy != NULL);
	yyassert(length >= 0 && length <= yy->yymleng);
	while (yy->yymleng > length) {
		(*yy->yymunput)(yy, (unsigned char) yy->yymtext[--yy->yymleng]);
	}
	if (yy->yymleng > 0) {
		yy->yymeol = (YYBOOL) (yy->yymtext[yy->yymleng - 1] == '\n');
	}
	else {
		yy->yymeol = yy->yymoldeol;
	}
}

_YL_END
