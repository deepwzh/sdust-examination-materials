/************************************************************
yywcuofw.cpp
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

void yywlexer::yyunputoverflow()
{
	wchar_t string[128];
	swprintf(string, L"lexer unput buffer overflow (%d)", (int)yyunput_size);
	yyerror(string);
}

_YL_END

#endif
