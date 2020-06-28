/************************************************************
yyacsusz.cpp
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

yybool yylexer::yysetunputsize(int size)
{
	yyassert(size >= 0);
	if (yyunput_size != size) {
		if (size < yyunputindex) {
			return yyfalse;
		}

		if (yyunput_max != 0) {
			if (size > yyunput_max) {
				return yyfalse;
			}
		}

		// allocate
		int YYFAR* unputbufptr;
		if (size <= yysunput_size) {
			unputbufptr = yysunputbufptr;
		}
		else {
			unputbufptr = new YYFAR int[size];
			if (unputbufptr == NULL) {
				return yyfalse;
			}
		}

		// copy
		if (unputbufptr != yyunputbufptr) {
			int count = yymin(size, yyunput_size);
			for (int i = 0; i < count; i++) {
				unputbufptr[i] = yyunputbufptr[i];
			}
		}

		// free
		if (yyunputbufptr != yysunputbufptr) {
			delete[] yyunputbufptr;
		}

		// assign
		yyunputbufptr = unputbufptr;
		yyunput_size = size;
	}
	return yytrue;
}

_YL_END

#endif
