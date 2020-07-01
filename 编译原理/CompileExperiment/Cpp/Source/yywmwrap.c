/************************************************************
yywmwrap.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yywmlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef __BORLANDC__
#pragma argsused
#endif

#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yywmwrap(yywmlexer_t YYFAR *yy)
#else
YYEXPFUNC(int) YYCDECL yywmwrap(yy)
yywmlexer_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	return 1;
}

_YL_END
