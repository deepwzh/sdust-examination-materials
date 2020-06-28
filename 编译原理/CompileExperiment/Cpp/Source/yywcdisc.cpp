/************************************************************
yywcdisc.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yywcpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

#ifdef __BORLANDC__
#pragma argsused
#endif

void yywparser::yydiscard(yywint_t token)
{
	yyassert(token > 0);
	// do nothing
}

_YL_END

#endif
