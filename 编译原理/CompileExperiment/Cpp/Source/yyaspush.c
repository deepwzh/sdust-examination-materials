/************************************************************
yyaspush.c
This file can be freely modified for the generation of
custom code.

[MBCS]

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

#include "yypars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYBOOL YYCDECL yypush(yystack_t state)
#else
YYBOOL YYCDECL yypush(state)
yystack_t state;
#endif
{
	yytop++;		/* increment first */
	if (yytop == yystack_size) {
		do {
			if (yystackgrow) {
				int size;
				if (yystack_size != 0) {
					size = yystack_size * 2;
					if (size / 2 != yystack_size) {		/* overflow check */
						size = yystack_max;
					}
				}
				else {
					size = 100;
				}
				if (yystack_max != 0) {
					if (size > yystack_max) {
						size = yystack_max;
					}
				}
				if (size > yystack_size) {
					if (yysetstacksize(size)) {
						break;
					}
				}
			}
			yytop--;

			/* debugging */
#ifdef YYDEBUG
			if (yygetglobaldebug() || yyparserdebug) {
				yyparserdebugoutput("stack overflow\n");
			}
#endif

			yystackoverflow();
			return YYFALSE;
		}
		while (0);
	}
	yystackptr[yytop] = state;

	/* debugging */
#ifdef YYDEBUG
	if (yygetglobaldebug() || yyparserdebug) {
		char string[128];

		sprintf(string, "push state %d", (int) state);
		yyparserdebugoutput(string);
		if (yytop > 0) {
			sprintf(string, " covering state %d", (int) yystackptr[yytop - 1]);
			yyparserdebugoutput(string);
		}
		yyparserdebugoutput("\n");

		/* output stack contents */
		if (yygetglobaldebugstack() || yyparserdebugstack) {
			int rows;
			int i;
			int n;

			yyparserdebugoutput("\nstack");
			n = sprintf(string, "\n     +");
			for (i = 0; i < 10; i++) {
				n += sprintf(&string[n], " %5d", (int) i);
			}
			yyparserdebugoutput(string);

			rows = 1;
			if (yytop >= 0) {
				rows += yytop / 10;
			}
			for (i = 0; i < rows; i++) {
				int j;
				n = sprintf(string, "\n %5d", (int) (10 * i));
				for (j = 0; j < 10; j++) {
					int index = 10 * i + j;
					if (index <= yytop) {
						n += sprintf(&string[n], " %5d", (int) yystackptr[index]);
					}
					else {
						n += sprintf(&string[n], "     -");
					}
				}
				yyparserdebugoutput(string);
			}
			yyparserdebugoutput("\n\n");
		}
	}
#endif

	return YYTRUE;
}

_YL_END

#endif
