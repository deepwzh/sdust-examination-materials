/************************************************************
yywmerr.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywmpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmerror(yywmparser_t YYFAR *yy, YYCONST wchar_t YYFAR *text)
#else
YYEXPFUNC(void) YYCDECL yywmerror(yy, text)
yywmparser_t YYFAR *yy;
YYCONST wchar_t YYFAR *text;
#endif
{
	yyassert(yy != NULL);
	yyassert(text != NULL);
	yyassert(yy->yymerr != NULL);
	while (*text != L'\0') {
		putwc(*text++, yy->yymerr);
	}
	putwc(L'\n', yy->yymerr);
}

_YL_END
