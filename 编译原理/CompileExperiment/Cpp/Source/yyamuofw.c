/************************************************************
yyamuofw.c
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
YYEXPFUNC(void) YYCDECL yymunputoverflow(yymlexer_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymunputoverflow(yy)
yymlexer_t YYFAR *yy;
#endif
{
	char string[128];
	yyassert(yy != NULL);
	sprintf(string, "lexer unput buffer overflow (%d)", (int) yy->yymunput_size);
	yymlexererror(yy, string);
}

_YL_END
