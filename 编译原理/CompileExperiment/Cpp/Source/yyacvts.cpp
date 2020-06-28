/************************************************************
yyacvts.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstring>
#else
#include <string.h>
#endif

#include "yycpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

// the Visual C++ v1.52 compiler generates an error in NT if this isn't present!
#ifdef _MSC_VER
#if defined(M_I86HM) && defined(NDEBUG)
#pragma function(memcpy)
#endif
#endif

void yyparser::yyvaltostack(int index)
{
	yyassert(index >= 0 && index < yystack_size);
	memcpy(&((char YYFAR*)yyattributestackptr)
		[index * yyattribute_size], yyvalptr, yyattribute_size);
}

_YL_END

#endif
