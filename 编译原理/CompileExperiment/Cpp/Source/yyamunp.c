/************************************************************
yyamunp.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

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

#include "yymlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymunput(yymlexer_t YYFAR *yy, int ch)
#else
YYEXPFUNC(void) YYCDECL yymunput(yy, ch)
yymlexer_t YYFAR *yy;
int ch;
#endif
{
	yyassert(yy != NULL);
	yyassert(ch >= 0 && ch <= UCHAR_MAX || ch == EOF);
	yyassert(yy->yymunputindex >= 0 && yy->yymunputindex <= yy->yymunput_size);
	
	/* check unput buffer size */
	if (yy->yymunputindex == yy->yymunput_size) {
		do {
			if (yy->yymunputgrow) {
				int size;
				if (yy->yymunput_size != 0) {
					size = yy->yymunput_size * 2;
					if (size / 2 != yy->yymunput_size) {		/* overflow check */
						size = yy->yymunput_max;
					}
				}
				else {
					size = 100;
				}
				if (yy->yymunput_max != 0) {
					if (size > yy->yymunput_max) {
						size = yy->yymunput_max;
					}
				}
				if (size > yy->yymunput_size) {
					if (yymsetunputsize(yy, size)) {
						break;
					}
				}
			}
			(*yy->yymunputoverflow)(yy);
			exit(EXIT_FAILURE);
		}
		while (0);
	}

	yy->yymunputbufptr[yy->yymunputindex++] = ch;

	/* check line number */
	if (ch == '\n') {
		yy->yymlineno--;
	}

	/* debugging */
#ifdef YYDEBUG
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];

		sprintf(string, "%p: unput: \'", (void *) yy);
		yymlexerdebugoutput(yy, string);
		yymdebugoutput(yy, ch);
		if (ch >= 0) {
			sprintf(string, "\' (0x%02x)\n", (int) ch);
		}
		else {
			sprintf(string, "\' (%d)\n", (int) ch);
		}
		yymlexerdebugoutput(yy, string);
	}
#endif
}

_YL_END
