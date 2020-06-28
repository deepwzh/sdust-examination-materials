/************************************************************
yywspcln.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yywcleanupparser(void)
#else
void YYCDECL yywcleanupparser()
#endif
{
	if (yywstackptr != yywsstackptr) {
		free(yywstackptr);
		yywstackptr = yywsstackptr;
	}
	if (yywattributestackptr != yywsattributestackptr) {
		free(yywattributestackptr);
		yywattributestackptr = yywsattributestackptr;
	}
	yywstack_size = yywsstack_size;

	yywtop = -1;
}

_YL_END

#endif
