/************************************************************
yyaspvar.c
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

YYBOOL YYNEAR YYDCDECL yylookahead = YYFALSE;	/* whether we have lookahead token */
YYBOOL YYNEAR YYDCDECL yystackgrow = YYTRUE;	/* do we allow stack to grow? */
YYBOOL YYNEAR YYDCDECL yyexitflg = YYFALSE;		/* whether yyexit called */
YYBOOL YYNEAR YYDCDECL yyretireflg = YYFALSE;	/* whether yyretire called */
YYBOOL YYNEAR YYDCDECL yyerrorflg = YYFALSE;	/* whether yyforceerror called */
YYBOOL YYNEAR YYDCDECL yypopflg = YYFALSE;		/* popping symbols during error recovery */
YYBOOL YYNEAR YYDCDECL yywipeflg = YYTRUE;		/* whether to "wipe" stack on abort */
int YYNEAR YYDCDECL yytop = -1;					/* the current top of the stack */
int YYNEAR YYDCDECL yychar = -1;				/* lookahead token */
int YYNEAR YYDCDECL yyskip = 0;					/* skip erroneous characters */
int YYNEAR YYDCDECL yyerrorcount = 0;			/* syntax error count */
int YYNEAR YYDCDECL yyexitcode;					/* yyexit exit code */
int YYNEAR YYDCDECL yyretirecode;				/* yyretire exit code */
int YYNEAR YYDCDECL yyerrorpop;					/* how many error transitions to pop */

#ifndef YYNINITSTREAM
FILE YYFAR *YYNEAR YYDCDECL yyparsererr = stderr;
#else
FILE YYFAR *YYNEAR YYDCDECL yyparsererr = NULL;
#endif

_YL_END

#endif
