/************************************************************
yywctofw.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yywclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void yywlexer::yytextoverflow()
{
	wchar_t string[128];
	swprintf(string, L"lexer text buffer overflow (%d)", (int)yytext_size);
	yyerror(string);
}

_YL_END

#endif
