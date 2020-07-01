/************************************************************
yyamres.c
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
YYEXPFUNC(void) YYCDECL yymreset(yymlexer_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymreset(yy)
yymlexer_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	yy->yymleng = 0;
	yy->yymlineno = 1;
	yy->yymunputindex = 0;
	yy->yymmoreflg = YYFALSE;
	yy->yymrejectflg = YYFALSE;
	yy->yymeol = YYTRUE;
	yy->yymoldeol = YYTRUE;
	yy->yymstart = 0;
}

_YL_END
