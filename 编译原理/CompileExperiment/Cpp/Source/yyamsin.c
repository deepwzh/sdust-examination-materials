/************************************************************
yyamsin.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yympars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymsetin(yymparser_t YYFAR *yy, int token)
#else
YYEXPFUNC(void) YYCDECL yymsetin(yy, token)
yymparser_t YYFAR *yy;
int token;
#endif
{
	yyassert(yy != NULL);
	if (token < 0) {
		token = 0;
	}
	yy->yymchar = token;
	yy->yymlookahead = YYTRUE;
}

_YL_END
