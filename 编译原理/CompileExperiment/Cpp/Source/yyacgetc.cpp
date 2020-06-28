/************************************************************
yyacgetc.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yyclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

int yylexer::yygetchar()
{
	yyassert(yyin != NULL);
#ifdef YYSTDCPPLIB
	std::istream::int_type ch = yyin->get();
	if (yyin->good()) {
		return ch;
	}
	return EOF;
#else
	return getc(yyin);
#endif
}

_YL_END

#endif
