/************************************************************
yyacpcln.cpp
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

void yyparser::yycleanup()
{
	if (yystackptr != yysstackptr) {
		delete[] yystackptr;
		yystackptr = yysstackptr;
	}
	if (yyattributestackptr != yysattributestackptr) {
		yydeleteattribute(yyattributestackptr);
		yyattributestackptr = yysattributestackptr;
	}
	yystack_size = yysstack_size;

	yytop = -1;
}

_YL_END

#endif
