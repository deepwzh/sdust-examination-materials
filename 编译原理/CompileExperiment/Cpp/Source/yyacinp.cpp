/************************************************************
yyacinp.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdio>
#include <cctype>
#else
#include <stdio.h>
#include <ctype.h>
#endif

#include "yyclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

int yylexer::yyinput()
{
	int ch;
	if (yyunputindex > 0) {
		ch = yyunputbufptr[--yyunputindex];
	}
	else {
		ch = yygetchar();
	}
	if (ch == '\n') {
		yylineno++;
	}

#ifdef YYDEBUG
	if (yygetglobaldebug() || yydebug) {
		char string[128];

		sprintf(string, "%p: input: \'", (void*)this);
		yydebugoutput(string);
		yydebugoutput(ch);
		if (ch >= 0) {
			sprintf(string, "\' (0x%02x)\n", (int)ch);
		}
		else {
			sprintf(string, "\' (%d)\n", (int)ch);
		}
		yydebugoutput(string);
	}
#endif

	return ch;
}

_YL_END

#endif
