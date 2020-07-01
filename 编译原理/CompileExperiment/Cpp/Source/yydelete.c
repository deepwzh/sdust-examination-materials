/************************************************************
yydelete.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yyglobal.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yydelete(void)
#else
YYEXPFUNC(void) YYCDECL yydelete()
#endif
{
	/* delete the mutexes */
	yydeletemutex();
}

_YL_END
