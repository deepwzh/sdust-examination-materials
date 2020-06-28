/************************************************************
yyassin.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#include "yypars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yysetin(int token)
#else
void YYCDECL yysetin(token)
int token;
#endif
{
	if (token < 0) {
		token = 0;
	}
	yychar = token;
	yylookahead = YYTRUE;
}

_YL_END

#endif
