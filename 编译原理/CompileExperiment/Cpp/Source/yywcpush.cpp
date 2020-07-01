/************************************************************
yywcpush.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

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

#include "yywcpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

yybool yywparser::yypush(yywstack_t state)
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
				wchar_t string[128];

				swprintf(string, L"%p: stack overflow\n", (void*)this);
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
		wchar_t string[128];

		swprintf(string, L"%p: push state %d", (void*)this, (int)state);
		yydebugoutput(string);
		if (yytop > 0) {
			swprintf(string, L" covering state %d", (int)yystackptr[yytop - 1]);
			yydebugoutput(string);
		}
		yydebugoutput(L"\n");

		// output stack contents
		if (yygetglobaldebugstack() || yydebugstack) {
			yydebugoutput(L"\nstack");
			int n = swprintf(string, L"\n     +");
			int i;
			for (i = 0; i < 10; i++) {
				n += swprintf(&string[n], L" %5d", (int)i);
			}
			yydebugoutput(string);

			int rows = 1;
			if (yytop >= 0) {
				rows += yytop / 10;
			}
			for (i = 0; i < rows; i++) {
				n = swprintf(string, L"\n %5d", (int)(10 * i));
				for (int j = 0; j < 10; j++) {
					int index = 10 * i + j;
					if (index <= yytop) {
						n += swprintf(&string[n], L" %5d", (int)yystackptr[index]);
					}
					else {
						n += swprintf(&string[n], L"     -");
					}
				}
				yydebugoutput(string);
			}
			yydebugoutput(L"\n\n");
		}
	}
#endif

	return yytrue;
}

_YL_END

#endif
