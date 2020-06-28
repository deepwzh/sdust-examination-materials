/************************************************************
yywcpcon.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yywcpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

yywparser::yywparser()
{
	yystackptr = NULL;
	yysstackptr = NULL;
	yyattributestackptr = NULL;
	yysattributestackptr = NULL;
	yystack_size = 0;
	yysstack_size = 0;
	yystack_max = 0;
	yytop = -1;
	yyattribute_size = 0;
	yyvalptr = NULL;
	yylookahead = yyfalse;
	yychar = -1;
	yywipeflg = yytrue;
	yypopflg = yyfalse;
	yyskip = 0;
	yyexitflg = yyfalse;
	yyretireflg = yyfalse;
	yyerrorflg = yyfalse;
	yyexitcode = 0;
	yyretirecode = 0;
	yyerrorpop = 0;
	yylexerptr = NULL;
	yystackgrow = yytrue;
	yylvalptr = NULL;
#ifdef YYSTDCPPLIB
	yyerr = &std::wcerr;
#else
	yyerr = stderr;
#endif
	yyerrorcount = 0;

#ifdef YYDEBUG
	yydebug = yyfalse;
	yydebugstack = yyfalse;
	yydebugflush = yyfalse;
#ifdef YYSTDCPPLIB
	yydebugout = &std::wcout;
#else
	yydebugout = stdout;
#endif
#endif
}

yywparser::~yywparser()
{
	yydestroy();
}

_YL_END

#endif
