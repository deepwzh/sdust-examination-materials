/************************************************************
yywcsin.cpp
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

void yywparser::yysetin(yywint_t token)
{
	if (token < 0) {
		token = 0;
	}
	yychar = token;
	yylookahead = yytrue;
}

_YL_END

#endif
