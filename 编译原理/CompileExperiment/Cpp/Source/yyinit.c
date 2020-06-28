/************************************************************
yyinit.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yyglobal.h"
#include "yypars.h"
#include "yylex.h"
#ifndef YYNUNICODE
#include "yywpars.h"
#include "yywlex.h"
#endif

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yyinit(void)
#else
YYEXPFUNC(void) YYCDECL yyinit()
#endif
{
	/* initialise the streams */
#ifndef YYBUILDDLL
#ifdef YYNINITSTREAM
	yyinitparser();
	yyinitlexer();
#ifndef YYNUNICODE
	yywinitparser();
	yywinitlexer();
#endif
#endif
#endif

	/* initialise the mutexes */
	yyinitmutex();
}

_YL_END
