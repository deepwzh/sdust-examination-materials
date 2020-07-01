/************************************************************
yyamgtok.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yympars.h"
#include "yymlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yymgettoken(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(int) YYCDECL yymgettoken(yy)
yymparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	yyassert(yy->yymlexerptr != NULL);
	return yymlex(yy->yymlexerptr);
}

_YL_END
