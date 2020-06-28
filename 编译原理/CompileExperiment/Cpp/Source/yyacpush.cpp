/************************************************************
yyacpush.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdlib>
#include <cstring>
#else
#include <stdlib.h>
#include <string.h>
#endif

#include "yycpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

yybool yyparser::yypush(yystack_t state)
{
	yytop++;		// increment first
	if (yytop == yystack_size) {
		do {
			if (yystackgrow) {
				int size;
				if (yystack_size != 0) {
					size = yystack_size * 2;
					if (size / 2 != yystack_size) {		// overflow check
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

			// debugging
#ifdef YYDEBUG
			if (yygetglobaldebug() || yydebug) {
				char string[128];

				sprintf(string, "%p: stack overflow\n", (void*)this);
				yydebugoutput(string);
			}
#endif

			yystackoverflow();
			return yyfalse;
		}
		while (0);
	}
	yystackptr[yytop] = state;

	// debugging
#ifdef YYDEBUG
	if (yygetglobaldebug() || yydebug) {
		char string[128];

		sprintf(string, "%p: push state %d", (void*)this, (int)state);
		yydebugoutput(string);
		if (yytop > 0) {
			sprintf(string, " covering state %d", (int)yystackptr[yytop - 1]);
			yydebugoutput(string);
		}
		yydebugoutput("\n");

		// output stack contents
		if (yygetglobaldebugstack() || yydebugstack) {
			yydebugoutput("\nstack");
			int n = sprintf(string, "\n     +");
			int i;
			for (i = 0; i < 10; i++) {
				n += sprintf(&string[n], " %5d", (int) i);
			}
			yydebugoutput(string);

			int rows = 1;
			if (yytop >= 0) {
				rows += yytop / 10;
			}
			for (i = 0; i < rows; i++) {
				n = sprintf(string, "\n %5d", (int) (10 * i));
				for (int j = 0; j < 10; j++) {
					int index = 10 * i + j;
					if (index <= yytop) {
						n += sprintf(&string[n], " %5d", (int) yystackptr[index]);
					}
					else {
						n += sprintf(&string[n], "     -");
					}
				}
				yydebugoutput(string);
			}
			yydebugoutput("\n\n");
		}
	}
#endif

	return yytrue;
}

_YL_END

#endif
