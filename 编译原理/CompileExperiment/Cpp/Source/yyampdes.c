/************************************************************
yyampdes.c
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
YYEXPFUNC(void) YYCDECL yymdestroyparser(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymdestroyparser(yy)
yymparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);

	yymcleanupparser(yy);
	free(yy->yymsstackptr);
	free(yy->yymsattributestackptr);

	free(yy->yymlvalptr);
	free(yy->yymvalptr);
}

_YL_END
