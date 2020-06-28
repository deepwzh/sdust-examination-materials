/************************************************************
yyaspcln.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yypars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yycleanupparser(void)
#else
void YYCDECL yycleanupparser()
#endif
{
	if (yystackptr != yysstackptr) {
		free(yystackptr);
		yystackptr = yysstackptr;
	}
	if (yyattributestackptr != yysattributestackptr) {
		free(yyattributestackptr);
		yyattributestackptr = yysattributestackptr;
	}
	yystack_size = yysstack_size;

	yytop = -1;
}

_YL_END

#endif
