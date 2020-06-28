/************************************************************
yywcnewa.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yywcpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void YYFAR* yywparser::yynewattribute(int count)
{
	yyassert(count >= 0);
	size_t attributecharsize = count * yyattribute_size;
	if ((int)(attributecharsize / yyattribute_size) != count) {
		return NULL;		// integer overflow
	}
	void YYFAR* attribute = new YYFAR char[attributecharsize];
	return attribute;
}

_YL_END

#endif
