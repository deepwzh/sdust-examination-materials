/************************************************************
yywcstv.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstring>
#else
#include <string.h>
#endif

#include "yywcpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void yywparser::yystacktoval(int index)
{
	yyassert(index >= 0 && index < yystack_size);
	memcpy(yyvalptr, &((char YYFAR*)yyattributestackptr)
		[index * yyattribute_size], yyattribute_size);
}

_YL_END

#endif
