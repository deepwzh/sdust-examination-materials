/************************************************************
yycldbg.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

#ifdef YYWIN32
#include <windows.h>
#include <winbase.h>
#endif

_YL_BEGIN

#ifdef YYDEBUG

void yywlexer::yydmatch(int expr) const
{
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];

		swprintf(string, L"%p: match: \"", (void*)this);
		yydebugoutput(string);
		for (int i = 0; i < yyleng; i++) {
			yydebugoutput(yytext[i]);
		}
		swprintf(string, L"\", %d\n", (int)expr);
		yydebugoutput(string);
	}
}

void yywlexer::yydebugoutput(const wchar_t YYFAR* string) const
{
	yyassert(string != NULL);

#ifdef YYWIN32
	if (yydebugout != NULL) {
#else
		yyassert(yydebugout != NULL);
#endif
		while (*string != L'\0') {
#ifdef YYSTDCPPLIB
			yydebugout->put(*string++);
#else
			putwc(*string++, yydebugout);
#endif
		}

		if (yygetglobaldebugflush() || yydebugflush) {
#ifdef YYSTDCPPLIB
			yydebugout->flush();
#else
			fflush(yydebugout);
#endif
		}
#ifdef YYWIN32
	}
	else {
		OutputDebugStringW(string);
		Sleep(0);		// makes sure debug string is processed
	}
#endif
}

#endif

_YL_END

#endif
