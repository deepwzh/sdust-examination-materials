/************************************************************
yywccpya.cpp
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

void yywparser::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	yyassert(dest != NULL);
	yyassert(src != NULL);
	yyassert(count >= 0);
	size_t attributecharsize = count * yyattribute_size;
	memcpy(dest, src, attributecharsize);
}

_YL_END

#endif
