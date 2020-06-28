/************************************************************
yyasres.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#include "yylex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yyreset(void)
#else
void YYCDECL yyreset()
#endif
{
	yyleng = 0;
	yylineno = 1;
	yyunputindex = 0;
	yymoreflg = YYFALSE;
	yyrejectflg = YYFALSE;
	yyeol = YYTRUE;
	yyoldeol = YYTRUE;
	yystart = 0;
}

_YL_END

#endif
