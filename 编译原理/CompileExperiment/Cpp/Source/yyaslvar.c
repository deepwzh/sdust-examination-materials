/************************************************************
yyaslvar.c
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

int YYNEAR YYDCDECL yyleng = 0;
int YYNEAR YYDCDECL yylineno = 1;
int YYNEAR YYDCDECL yyunputindex = 0;
YYBOOL YYNEAR YYDCDECL yymoreflg = YYFALSE;
YYBOOL YYNEAR YYDCDECL yyrejectflg;
YYBOOL YYNEAR YYDCDECL yyreturnflg;
YYBOOL YYNEAR YYDCDECL yytextgrow = YYTRUE;
YYBOOL YYNEAR YYDCDECL yyunputgrow = YYTRUE;
YYBOOL YYNEAR YYDCDECL yyeol = YYTRUE;
YYBOOL YYNEAR YYDCDECL yyoldeol = YYTRUE;
int YYNEAR YYDCDECL yystart = 0;

#ifndef YYNINITSTREAM
FILE YYFAR *YYNEAR YYDCDECL yyin = stdin;
FILE YYFAR *YYNEAR YYDCDECL yyout = stdout;
FILE YYFAR *YYNEAR YYDCDECL yylexererr = stderr;
#else
FILE YYFAR *YYNEAR YYDCDECL yyin = NULL;
FILE YYFAR *YYNEAR YYDCDECL yyout = NULL;
FILE YYFAR *YYNEAR YYDCDECL yylexererr = NULL;
#endif

_YL_END

#endif
