/************************************************************
yyampcln.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yympars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymcleanupparser(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymcleanupparser(yy)
yymparser_t YYFAR *yy;
#endif
{
	if (yy->yymstackptr != yy->yymsstackptr) {
		free(yy->yymstackptr);
		yy->yymstackptr = yy->yymsstackptr;
	}
	if (yy->yymattributestackptr != yy->yymsattributestackptr) {
		free(yy->yymattributestackptr);
		yy->yymattributestackptr = yy->yymsattributestackptr;
	}
	yy->yymstack_size = yy->yymsstack_size;

	yy->yymtop = -1;
}

_YL_END
