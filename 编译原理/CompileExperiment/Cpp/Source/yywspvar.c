/************************************************************
yywspvar.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

YYBOOL YYNEAR YYDCDECL yywlookahead = YYFALSE;	/* whether we have lookahead token */
YYBOOL YYNEAR YYDCDECL yywstackgrow = YYTRUE;	/* do we allow stack to grow? */
YYBOOL YYNEAR YYDCDECL yywexitflg = YYFALSE;	/* whether yyexit called */
YYBOOL YYNEAR YYDCDECL yywretireflg = YYFALSE;	/* whether yyretire called */
YYBOOL YYNEAR YYDCDECL yywerrorflg = YYFALSE;	/* whether yyforceerror called */
YYBOOL YYNEAR YYDCDECL yywpopflg = YYFALSE;		/* popping symbols during error recovery */
YYBOOL YYNEAR YYDCDECL yywwipeflg = YYTRUE;		/* whether to "wipe" stack on abort */
int YYNEAR YYDCDECL yywtop = -1;				/* the current top of the stack */
yywint_t YYNEAR YYDCDECL yywchar = -1;			/* lookahead token */
int YYNEAR YYDCDECL yywskip = 0;				/* skip erroneous characters */
int YYNEAR YYDCDECL yywerrorcount = 0;			/* syntax error count */
int YYNEAR YYDCDECL yywexitcode;				/* yyexit exit code */
int YYNEAR YYDCDECL yywretirecode;				/* yyretire exit code */
int YYNEAR YYDCDECL yywerrorpop;				/* how many error transitions to pop */

#ifndef YYNINITSTREAM
FILE YYFAR *YYNEAR YYDCDECL yywparsererr = stderr;
#else
FILE YYFAR *YYNEAR YYDCDECL yywparsererr = NULL;
#endif

_YL_END

#endif
