/************************************************************
yyacoutp.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdio>
#include <climits>
#else
#include <stdio.h>
#include <limits.h>
#endif

#include "yyclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void yylexer::yyoutput(int ch)
{
	// debugging
#ifdef YYDEBUG
	if (yygetglobaldebug() || yydebug) {
		char string[128];

		sprintf(string, "%p: output: \'", (void*)this);
		yydebugoutput(string);
		yydebugoutput(ch);
		sprintf(string, "\' (0x%02x)\n", (int)ch);
		yydebugoutput(string);
	}
#endif

	yyassert(yyout != NULL);

#ifdef YYSTDCPPLIB
#ifdef __BORLANDC__
	yyout->put((char)ch);
#else
	yyout->put(ch);
#endif
#else
#ifdef __BORLANDC__
	putc((char)ch, yyout);
#else
	putc(ch, yyout);
#endif
#endif
}

_YL_END

#endif
