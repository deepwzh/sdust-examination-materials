/************************************************************
yywcdop.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstring>
#include <cctype>
#else
#include <string.h>
#include <ctype.h>
#endif

#include "yywclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
void yywlexer::yydebugoutput(yywint_t ch) const
{
	wchar_t string[32];
	switch (ch) {
	case EOF:
		wcscpy(string, L"EOF");
		break;
	case L'\n':
		wcscpy(string, L"\\n");
		break;
	case L'\t':
		wcscpy(string, L"\\t");
		break;
	case L'\v':
		wcscpy(string, L"\\v");
		break;
	case L'\b':
		wcscpy(string, L"\\b");
		break;
	case L'\r':
		wcscpy(string, L"\\r");
		break;
	case L'\f':
		wcscpy(string, L"\\f");
		break;
	case L'\a':
		wcscpy(string, L"\\a");
		break;
	case L'\\':
		wcscpy(string, L"\\");
		break;
	case L'\?':
		wcscpy(string, L"\\\?");
		break;
	case L'\'':
		wcscpy(string, L"\\\'");
		break;
	case L'\"':
		wcscpy(string, L"\\\"");
		break;
	default:
		if (!iswascii(ch) || iswascii(ch) && iswprint(ch)) {
			string[0] = (wchar_t)ch;
			string[1] = L'\0';
		}
		else {
			swprintf(string, L"\\%03o", (unsigned int)ch);
		}
		break;
	}
	yydebugoutput(string);
}

#endif

_YL_END

#endif
