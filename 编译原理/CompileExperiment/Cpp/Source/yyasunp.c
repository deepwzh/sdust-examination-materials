/************************************************************
yyasunp.c
This file can be freely modified for the generation of
custom code.

[MBCS]

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

#include "yylex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
void YYCDECL yyunput(int ch)
#else
void YYCDECL yyunput(ch)
int ch;
#endif
{
	yyassert(ch >= 0 && ch <= UCHAR_MAX || ch == EOF);
	yyassert(yyunputindex >= 0 && yyunputindex <= yyunput_size);

	/* check unput buffer size */
	if (yyunputindex == yyunput_size) {
		do {
			if (yyunputgrow) {
				int size;
				if (yyunput_size != 0) {
					size = yyunput_size * 2;
					if (size / 2 != yyunput_size) {		/* overflow check */
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

	/* check line number */
	if (ch == '\n') {
		yylineno--;
	}

	/* debugging */
#ifdef YYDEBUG
	if (yygetglobaldebug() || yylexerdebug) {
		char string[128];

		yylexerdebugoutput("unput: \'");
		yydebugoutput(ch);
		if (ch >= 0) {
			sprintf(string, "\' (0x%02x)\n", (int) ch);
		}
		else {
			sprintf(string, "\' (%d)\n", (int) ch);
		}
		yylexerdebugoutput(string);
	}
#endif
}

_YL_END

#endif
