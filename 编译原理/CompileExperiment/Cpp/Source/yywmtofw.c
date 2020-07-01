/************************************************************
yywmtofw.c
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
YYEXPFUNC(void) YYCDECL yywmtextoverflow(yywmlexer_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywmtextoverflow(yy)
yywmlexer_t YYFAR *yy;
#endif
{
	wchar_t string[128];
	yyassert(yy != NULL);
	swprintf(string, L"lexer text buffer overflow (%d)", (int) yy->yymtext_size);
	(*yy->yymerror)(yy, string);
}

_YL_END
