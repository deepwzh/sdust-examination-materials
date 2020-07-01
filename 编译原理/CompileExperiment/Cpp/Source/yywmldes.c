/************************************************************
yywmldes.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yywmlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdestroylexer(yywmlexer_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywmdestroylexer(yy)
yywmlexer_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);

	yywmcleanuplexer(yy);
	free(yy->yymstext);
	free(yy->yymsstatebuf);
	free(yy->yymsunputbufptr);
}

_YL_END
