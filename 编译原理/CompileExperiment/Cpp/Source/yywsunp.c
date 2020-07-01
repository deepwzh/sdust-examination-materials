/************************************************************
yywsunp.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
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

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yywunput(yywint_t ch)
#else
void YYCDECL yywunput(ch)
yywint_t ch;
#endif
{
	yyassert(ch >= 0 && ch <= 0xffff || ch == -1);
	yyassert(yywunputindex >= 0 && yywunputindex <= yywunput_size);

	/* check unput buffer size */
	if (yywunputindex == yywunput_size) {
		do {
			if (yywunputgrow) {
				int size;
				if (yywunput_size != 0) {
					size = yywunput_size * 2;
					if (size / 2 != yywunput_size) {		/* overflow check */
						size = yywunput_max;
					}
				}
				else {
					size = 100;
				}
				if (yywunput_max != 0) {
					if (size > yywunput_max) {
						size = yywunput_max;
					}
				}
				if (size > yywunput_size) {
					if (yywsetunputsize(size)) {
						break;
					}
				}
			}
			yywunputoverflow();
			exit(EXIT_FAILURE);
		}
		while (0);
	}

	yywunputbufptr[yywunputindex++] = ch;

	/* check line number */
	if (ch == L'\n') {
		yywlineno--;
	}

	/* debugging */
#ifdef YYDEBUG
	if (yygetglobaldebug() || yywlexerdebug) {
		wchar_t string[128];

		yywlexerdebugoutput(L"unput: \'");
		yywdebugoutput(ch);
		if (ch >= 0) {
			swprintf(string, L"\' (0x%04lx)\n", (long) ch);
		}
		else {
			swprintf(string, L"\' (%ld)\n", (long) ch);
		}
		yywlexerdebugoutput(string);
	}
#endif
}

_YL_END

#endif
