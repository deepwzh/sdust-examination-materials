/************************************************************
yyacucin.cpp
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

yybool yyparser::yyunclearin()
{
	if (!yylookahead && yychar != -1) {
		yylookahead = yytrue;
		return yytrue;
	}
	return yyfalse;
}

_YL_END

#endif
