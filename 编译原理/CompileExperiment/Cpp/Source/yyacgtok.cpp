/************************************************************
yyacgtok.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yycpars.h"
#include "yyclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

int yyparser::yygettoken()
{
	yyassert(yylexerptr != NULL);
	return yylexerptr->yylex();
}

_YL_END

#endif
