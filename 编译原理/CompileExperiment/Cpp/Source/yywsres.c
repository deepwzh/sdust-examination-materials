/************************************************************
yywsres.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yywreset(void)
#else
void YYCDECL yywreset()
#endif
{
	yywleng = 0;
	yywlineno = 1;
	yywunputindex = 0;
	yywmoreflg = YYFALSE;
	yywrejectflg = YYFALSE;
	yyweol = YYTRUE;
	yywoldeol = YYTRUE;
	yywstart = 0;
}

_YL_END

#endif
