/************************************************************
yywmsofw.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yywmpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmstackoverflow(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywmstackoverflow(yy)
yywmparser_t YYFAR *yy;
#endif
{
	wchar_t string[128];
	yyassert(yy != NULL);
	swprintf(string, L"parser stack overflow (%d)", (int) yy->yymstack_size);
	(*yy->yymerror)(yy, string);
}

_YL_END
