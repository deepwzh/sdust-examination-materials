/************************************************************
yyampush.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#include <cstring>
#else
#include <stdlib.h>
#include <string.h>
#endif

#include "yympars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yympush(yymparser_t YYFAR *yy, yystack_t state)
#else
YYEXPFUNC(YYBOOL) YYCDECL yympush(yy, state)
yymparser_t YYFAR *yy;
yystack_t state;
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
					if (yymsetstacksize(yy, size)) {
						break;
					}
				}
			}
			yy->yymtop--;

			/* debugging */
#ifdef YYDEBUG
			if (yygetglobaldebug() || yy->yymdebug) {
				char string[128];

				sprintf(string, "%p: stack overflow\n", (void *) yy);
				yymparserdebugoutput(yy, string);
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
		char string[128];

		sprintf(string, "%p: push state %d", (void *) yy, (int) state);
		yymparserdebugoutput(yy, string);
		if (yy->yymtop > 0) {
			sprintf(string, " covering state %d",
				(int) yy->yymstackptr[yy->yymtop - 1]);
			yymparserdebugoutput(yy, string);
		}
		yymparserdebugoutput(yy, "\n");

		/* output stack contents */
		if (yygetglobaldebugstack() || yy->yymdebugstack) {
			int rows;
			int i;
			int n;

			yymparserdebugoutput(yy, "\nstack");
			n = sprintf(string, "\n     +");
			for (i = 0; i < 10; i++) {
				n += sprintf(&string[n], " %5d", (int) i);
			}
			yymparserdebugoutput(yy, string);

			rows = 1;
			if (yy->yymtop >= 0) {
				rows += yy->yymtop / 10;
			}
			for (i = 0; i < rows; i++) {
				int j;
				n = sprintf(string, "\n %5d", (int) (10 * i));
				for (j = 0; j < 10; j++) {
					int index = 10 * i + j;
					if (index <= yy->yymtop) {
						n += sprintf(&string[n], " %5d", (int) yy->yymstackptr[index]);
					}
					else {
						n += sprintf(&string[n], "     -");
					}
				}
				yymparserdebugoutput(yy, string);
			}
			yymparserdebugoutput(yy, "\n\n");
		}
	}
#endif

	return YYTRUE;
}

_YL_END
