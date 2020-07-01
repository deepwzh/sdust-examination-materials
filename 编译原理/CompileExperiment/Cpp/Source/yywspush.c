/************************************************************
yywspush.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#include <cstring>
#else
#include <stdlib.h>
#include <string.h>
#endif

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYBOOL YYCDECL yywpush(yywstack_t state)
#else
YYBOOL YYCDECL yywpush(state)
yywstack_t state;
#endif
{
	yywtop++;		/* increment first */
	if (yywtop == yywstack_size) {
		do {
			if (yywstackgrow) {
				int size;
				if (yywstack_size != 0) {
					size = yywstack_size * 2;
					if (size / 2 != yywstack_size) {		/* overflow check */
						size = yywstack_max;
					}
				}
				else {
					size = 100;
				}
				if (yywstack_max != 0) {
					if (size > yywstack_max) {
						size = yywstack_max;
					}
				}
				if (size > yywstack_size) {
					if (yywsetstacksize(size)) {
						break;
					}
				}
			}
			yywtop--;

			/* debugging */
#ifdef YYDEBUG
			if (yygetglobaldebug() || yywparserdebug) {
				yywparserdebugoutput(L"stack overflow\n");
			}
#endif

			yywstackoverflow();
			return YYFALSE;
		}
		while (0);
	}
	yywstackptr[yywtop] = state;

	/* debugging */
#ifdef YYDEBUG
	if (yygetglobaldebug() || yywparserdebug) {
		wchar_t string[128];

		swprintf(string, L"push state %d", (int) state);
		yywparserdebugoutput(string);
		if (yywtop > 0) {
			swprintf(string, L" covering state %d", (int) yywstackptr[yywtop - 1]);
			yywparserdebugoutput(string);
		}
		yywparserdebugoutput(L"\n");

		/* output stack contents */
		if (yygetglobaldebugstack() || yywparserdebugstack) {
			int rows;
			int i;
			int n;

			yywparserdebugoutput(L"\nstack");
			n = swprintf(string, L"\n     +");
			for (i = 0; i < 10; i++) {
				n += swprintf(&string[n], L" %5d", (int) i);
			}
			yywparserdebugoutput(string);

			rows = 1;
			if (yywtop >= 0) {
				rows += yywtop / 10;
			}
			for (i = 0; i < rows; i++) {
				int j;
				n = swprintf(string, L"\n %5d", (int) (10 * i));
				for (j = 0; j < 10; j++) {
					int index = 10 * i + j;
					if (index <= yywtop) {
						n += swprintf(&string[n], L" %5d", (int) yywstackptr[index]);
					}
					else {
						n += swprintf(&string[n], L"     -");
					}
				}
				yywparserdebugoutput(string);
			}
			yywparserdebugoutput(L"\n\n");
		}
	}
#endif

	return YYTRUE;
}

_YL_END

#endif
