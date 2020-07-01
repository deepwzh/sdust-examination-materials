/************************************************************
yyacback.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yyclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

yybool yylexer::yyback(const yymatch_t YYNEARFAR* p, int action)
{
	yyassert(p != NULL);
	yyassert(action < 0);
	while (*p != 0) {
		if (*p++ == action) {
			return yytrue;
		}
	}
	return yyfalse;
}

_YL_END

#endif
