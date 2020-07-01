/************************************************************
yywmpush.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#include <cstring>
#else
#include <stdlib.h>
#include <string.h>
#endif

#include "yywmpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yywmpush(yywmparser_t YYFAR *yy, yywstack_t state)
#else
YYEXPFUNC(YYBOOL) YYCDECL yywmpush(yy, state)
yywmparser_t YYFAR *yy;
yywstack_t state;
#endif
{
	yyassert(yy != NULL);

	yy->yymtop++;		/* increment first */
	if (yy->yymtop == yy->yymstack_size) {
		do {
			if (yy->yymstackgrow) {
				int size;
				if (yy->yymstack_size != 0) {
					size = yy->yymstack_size * 2;
					if (size / 2 != yy->yymstack_size) {		/* overflow check */
						size = yy->yymstack_max;
					}
				}
				else {
					size = 100;
				}
				if (yy->yymstack_max != 0) {
					if (size > yy->yymstack_max) {
						size = yy->yymstack_max;
					}
				}
				if (size > yy->yymstack_size) {
					if (yywmsetstacksize(yy, size)) {
						break;
					}
				}
			}
			yy->yymtop--;

			/* debugging */
#ifdef YYDEBUG
			if (yygetglobaldebug() || yy->yymdebug) {
				wchar_t string[128];

				swprintf(string, L"%p: stack overflow\n", (void *) yy);
				yywmparserdebugoutput(yy, string);
			}
#endif

			(*yy->yymstackoverflow)(yy);
			return YYFALSE;
		}
		while (0);
	}
	yy->yymstackptr[yy->yymtop] = state;

	/* debugging */
#ifdef YYDEBUG
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];

		swprintf(string, L"%p: push state %d", (void *) yy, (int) state);
		yywmparserdebugoutput(yy, string);
		if (yy->yymtop > 0) {
			swprintf(string, L" covering state %d",
				(int) yy->yymstackptr[yy->yymtop - 1]);
			yywmparserdebugoutput(yy, string);
		}
		yywmparserdebugoutput(yy, L"\n");

		/* output stack contents */
		if (yygetglobaldebugstack() || yy->yymdebugstack) {
			int rows;
			int i;
			int n;

			yywmparserdebugoutput(yy, L"\nstack");
			n = swprintf(string, L"\n     +");
			for (i = 0; i < 10; i++) {
				n += swprintf(&string[n], L" %5d", (int) i);
			}
			yywmparserdebugoutput(yy, string);

			rows = 1;
			if (yy->yymtop >= 0) {
				rows += yy->yymtop / 10;
			}
			for (i = 0; i < rows; i++) {
				int j;
				n = swprintf(string, L"\n %5d", (int) (10 * i));
				for (j = 0; j < 10; j++) {
					int index = 10 * i + j;
					if (index <= yy->yymtop) {
						n += swprintf(&string[n], L" %5d", (int) yy->yymstackptr[index]);
					}
					else {
						n += swprintf(&string[n], L"     -");
					}
				}
				yywmparserdebugoutput(yy, string);
			}
			yywmparserdebugoutput(yy, L"\n\n");
		}
	}
#endif

	return YYTRUE;
}

_YL_END
