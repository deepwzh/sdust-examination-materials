/************************************************************
yyassofw.c
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
void YYCDECL yystackoverflow(void)
#else
void YYCDECL yystackoverflow()
#endif
{
	char string[128];
	sprintf(string, "parser stack overflow (%d)", (int) yystack_size);
	yyparsererror(string);
}

_YL_END

#endif
