/************************************************************
yywclcon.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yywclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

yywlexer::yywlexer()
{
	yystart = 0;
	yyeol = yytrue;
	yyoldeol = yytrue;
	yystatebuf = NULL;
	yysstatebuf = NULL;
	yystext = NULL;
	yytext_size = 0;
	yystext_size = 0;
	yytext_max = 0;
	yyunputbufptr = NULL;
	yysunputbufptr = NULL;
	yyunput_size = 0;
	yysunput_size = 0;
	yyunputindex = 0;
	yyunput_max = 0;
	yymoreflg = yyfalse;
	yyrejectflg = yyfalse;
	yyreturnflg = yyfalse;
	yyparserptr = NULL;
	yytextgrow = yytrue;
	yyunputgrow = yytrue;
#ifdef YYSTDCPPLIB
	yyin = &std::wcin;
	yyout = &std::wcout;
	yyerr = &std::wcerr;
#else
	yyin = stdin;
	yyout = stdout;
	yyerr = stderr;
#endif
	yytext = NULL;
	yyleng = 0;
	yylineno = 1;

	// debugging
#ifdef YYDEBUG
	yydebug = yyfalse;
	yydebugflush = yyfalse;
#ifdef YYSTDCPPLIB
	yydebugout = &std::wcout;
#else
	yydebugout = stdout;
#endif
#endif
}

yywlexer::~yywlexer()
{
	yydestroy();
}

_YL_END

#endif
