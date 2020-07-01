/************************************************************
yyacldes.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yyclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void yylexer::yydestroy()
{
	yycleanup();
	delete[] yystext;
	yystext = NULL;
	yytext = NULL;
	delete[] yysstatebuf;
	yysstatebuf = NULL;
	yystatebuf = NULL;
	delete[] yysunputbufptr;
	yysunputbufptr = NULL;
	yyunputbufptr = NULL;
}

_YL_END

#endif
