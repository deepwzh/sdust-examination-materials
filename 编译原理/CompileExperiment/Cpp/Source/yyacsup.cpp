/************************************************************
yyacsup.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yycpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

int yyparser::yysetup()
{
	// initialise variables
	yytop = -1;
	yylookahead = yyfalse;
	yyskip = 0;
	yyerrorcount = 0;
	yychar = -1;
	yypopflg = yyfalse;

	// push initial state onto the stack
	if (!yypush(0)) {
#ifdef YYDEBUG
		yydabort();
#endif
		return 1;
	}
	return 0;
}

_YL_END

#endif
