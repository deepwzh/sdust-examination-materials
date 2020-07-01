/************************************************************
yywcgetc.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

yywint_t yywlexer::yygetchar()
{
	yyassert(yyin != NULL);
#ifdef YYSTDCPPLIB
	std::istream::int_type ch = yyin->get();
	if (yyin->good()) {
		return ch;
	}
	return EOF;
#else
	yywint_t wc = getwc(yyin);

	// convert WEOF to EOF so that lexer can process input correctly
	if (wc == WEOF && (feof(yyin) || ferror(yyin))) {
		wc = EOF;
	}
	return wc;
#endif
}

_YL_END

#endif
