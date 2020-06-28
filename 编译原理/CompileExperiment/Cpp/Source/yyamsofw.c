/************************************************************
yyamsofw.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yympars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymstackoverflow(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymstackoverflow(yy)
yymparser_t YYFAR *yy;
#endif
{
	char string[128];
	yyassert(yy != NULL);
	sprintf(string, "parser stack overflow (%d)", (int) yy->yymstack_size);
	(*yy->yymerror)(yy, string);
}

_YL_END
