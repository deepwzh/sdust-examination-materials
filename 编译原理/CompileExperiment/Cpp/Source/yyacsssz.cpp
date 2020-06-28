/************************************************************
yyacsssz.cpp
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

#include "yycpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

yybool yyparser::yysetstacksize(int size)
{
	yyassert(size >= 0);
	if (yystack_size != size) {
		if (size <= yytop) {
			return yyfalse;
		}

		if (yystack_max != 0) {
			if (size > yystack_max) {
				return yyfalse;
			}
		}

		// allocate
		yystack_t YYFAR* stackptr;
		void YYFAR* attributestackptr;
		if (size <= yysstack_size) {
			stackptr = yysstackptr;
			attributestackptr = yysattributestackptr;
		}
		else {
			stackptr = new YYFAR yystack_t[size];
			if (stackptr == NULL) {
				return yyfalse;
			}
			attributestackptr = yynewattribute(size);
			if (attributestackptr == NULL) {
				delete[] stackptr;		// clean up
				return yyfalse;
			}
		}

		// copy
		if (stackptr != yystackptr) {
			int count = yymin(size, yystack_size);
			for (int i = 0; i < count; i++) {
				stackptr[i] = yystackptr[i];
			}
		}
		if (attributestackptr != yyattributestackptr) {
			int count = yymin(size, yystack_size);
			yycopyattribute(attributestackptr, yyattributestackptr, count);
		}

		// free
		if (yystackptr != yysstackptr) {
			delete[] yystackptr;
		}
		if (yyattributestackptr != yysattributestackptr) {
			yydeleteattribute(yyattributestackptr);
		}

		// assign
		yystackptr = stackptr;
		yyattributestackptr = attributestackptr;
		yystack_size = size;
	}
	return yytrue;
}

_YL_END

#endif
