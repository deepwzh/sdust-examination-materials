/************************************************************
yywmuofw.c
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
YYEXPFUNC(void) YYCDECL yywmunputoverflow(yywmlexer_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywmunputoverflow(yy)
yywmlexer_t YYFAR *yy;
#endif
{
	wchar_t string[128];
	yyassert(yy != NULL);
	swprintf(string, L"lexer unput buffer overflow (%d)", (int) yy->yymunput_size);
	yywmlexererror(yy, string);
}

_YL_END
