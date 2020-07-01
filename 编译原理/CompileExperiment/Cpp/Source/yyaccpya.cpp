/************************************************************
yyaccpya.cpp
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

void yyparser::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	yyassert(dest != NULL);
	yyassert(src != NULL);
	yyassert(count >= 0);
	size_t attributecharsize = count * yyattribute_size;
	memcpy(dest, src, attributecharsize);
}

_YL_END

#endif
