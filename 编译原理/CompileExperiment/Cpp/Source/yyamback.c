/************************************************************
yyamback.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yymlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yymback(YYCONST yymatch_t YYNEARFAR *p, int action)
#else
YYEXPFUNC(YYBOOL) YYCDECL yymback(p, action)
YYCONST yymatch_t YYNEARFAR *p;
int action;
#endif
{
	yyassert(p != NULL);
	yyassert(action < 0);
	while (*p != 0) {
		if (*p++ == action) {
			return YYTRUE;
		}
	}
	return YYFALSE;
}

_YL_END
