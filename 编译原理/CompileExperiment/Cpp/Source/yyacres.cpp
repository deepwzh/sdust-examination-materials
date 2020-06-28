/************************************************************
yyacres.cpp
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

void yylexer::yyreset()
{
	yyleng = 0;
	yylineno = 1;
	yyunputindex = 0;
	yymoreflg = yyfalse;
	yyrejectflg = yyfalse;
	yyeol = yytrue;
	yyoldeol = yytrue;
	yystart = 0;
}

_YL_END

#endif
