/************************************************************
yywslvar.c
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

int YYNEAR YYDCDECL yywleng = 0;
int YYNEAR YYDCDECL yywlineno = 1;
int YYNEAR YYDCDECL yywunputindex = 0;
YYBOOL YYNEAR YYDCDECL yywmoreflg = YYFALSE;
YYBOOL YYNEAR YYDCDECL yywrejectflg;
YYBOOL YYNEAR YYDCDECL yywreturnflg;
YYBOOL YYNEAR YYDCDECL yywtextgrow = YYTRUE;
YYBOOL YYNEAR YYDCDECL yywunputgrow = YYTRUE;
YYBOOL YYNEAR YYDCDECL yyweol = YYTRUE;
YYBOOL YYNEAR YYDCDECL yywoldeol = YYTRUE;
int YYNEAR YYDCDECL yywstart = 0;

#ifndef YYNINITSTREAM
FILE YYFAR *YYNEAR YYDCDECL yywin = stdin;
FILE YYFAR *YYNEAR YYDCDECL yywout = stdout;
FILE YYFAR *YYNEAR YYDCDECL yywlexererr = stderr;
#else
FILE YYFAR *YYNEAR YYDCDECL yywin = NULL;
FILE YYFAR *YYNEAR YYDCDECL yywout = NULL;
FILE YYFAR *YYNEAR YYDCDECL yywlexererr = NULL;
#endif

_YL_END

#endif
