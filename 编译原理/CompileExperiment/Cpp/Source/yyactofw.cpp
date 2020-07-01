/************************************************************
yyactofw.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yyclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void yylexer::yytextoverflow()
{
	char string[128];
	sprintf(string, "lexer text buffer overflow (%d)", (int)yytext_size);
	yyerror(string);
}

_YL_END

#endif
