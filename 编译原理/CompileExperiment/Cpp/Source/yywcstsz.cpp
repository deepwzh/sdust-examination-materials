/************************************************************
yywcstsz.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yywclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

yybool yywlexer::yysettextsize(int size)
{
	yyassert(size >= 0);
	if (yytext_size != size) {
		if (size < yyleng) {
			return yyfalse;
		}

		if (yytext_max != 0) {
			if (size > yytext_max) {
				return yyfalse;
			}
		}

		int textsize = size + 1;	// include the '\0'
		if (textsize <= size) {
			return yyfalse;		// integer overflow
		}

		// allocate
		wchar_t YYFAR* text;
		int YYFAR* statebuf;
		if (size <= yystext_size) {
			text = yystext;
			statebuf = yysstatebuf;
		}
		else {
			text = new YYFAR wchar_t[textsize];
			if (text == NULL) {
				return yyfalse;
			}
			statebuf = new YYFAR int[size];
			if (statebuf == NULL) {
				delete[] text;			// clean up
				return yyfalse;
			}
		}

		// copy
		if (text != yytext) {
			int oldtextsize = yytext_size + 1;
			int count = yymin(textsize, oldtextsize);
			for (int i = 0; i < count; i++) {
				text[i] = yytext[i];
			}
		}
		if (statebuf != yystatebuf) {
			int count = yymin(size, yytext_size);
			for (int i = 0; i < count; i++) {
				statebuf[i] = yystatebuf[i];
			}
		}

		// free
		if (yytext != yystext) {
			delete[] yytext;
		}
		if (yystatebuf != yysstatebuf) {
			delete[] yystatebuf;
		}

		// assign
		yytext = text;
		yystatebuf = statebuf;
		yytext_size = size;
	}
	return yytrue;
}

_YL_END

#endif
