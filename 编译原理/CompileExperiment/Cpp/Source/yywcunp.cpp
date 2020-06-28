/************************************************************
yywcunp.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <climits>
#else
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
#endif

#include "yywclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void yywlexer::yyunput(yywint_t ch)
{
	yyassert(ch >= 0 && ch <= 0xffff || ch == -1);
	yyassert(yyunputindex >= 0 && yyunputindex <= yyunput_size);

	// check unput buffer size
	if (yyunputindex == yyunput_size) {
		do {
			if (yyunputgrow) {
				int size;
				if (yyunput_size != 0) {
					size = yyunput_size * 2;
					if (size / 2 != yyunput_size) {		// overflow check
						size = yyunput_max;
					}
				}
				else {
					size = 100;
				}
				if (yyunput_max != 0) {
					if (size > yyunput_max) {
						size = yyunput_max;
					}
				}
				if (size > yyunput_size) {
					if (yysetunputsize(size)) {
						break;
					}
				}
			}
			yyunputoverflow();
			exit(EXIT_FAILURE);
		}
		while (0);
	}

	yyunputbufptr[yyunputindex++] = ch;

	// check line number
	if (ch == L'\n') {
		yylineno--;
	}

	// debugging
#ifdef YYDEBUG
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];

		swprintf(string, L"%p: unput: \'", (void*)this);
		yydebugoutput(string);
		yydebugoutput(ch);
		if (ch >= 0) {
			swprintf(string, L"\' (0x%04lx)\n", (long)ch);
		}
		else {
			swprintf(string, L"\' (%ld)\n", (long)ch);
		}
		yydebugoutput(string);
	}
#endif
}

_YL_END

#endif
