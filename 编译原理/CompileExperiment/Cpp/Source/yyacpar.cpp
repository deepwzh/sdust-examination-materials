/************************************************************
yyacpar.cpp
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

int yyparser::yyparse()
{
	int n = yysetup();
	if (n != 0) {
		return n;
	}
	return yywork();
}

_YL_END

#endif
