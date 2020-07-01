/************************************************************
yyacstsz.cpp
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

#include "yyclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

// the Visual C++ v1.52 compiler generates an error in NT if this isn't present!
#ifdef _MSC_VER
#if defined(M_I86HM) && defined(NDEBUG)
#pragma function(memcpy)
#endif
#endif

yybool yylexer::yysettextsize(int size)
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
		char YYFAR* text;
		int YYFAR* statebuf;
		if (size <= yystext_size) {
			text = yystext;
			statebuf = yysstatebuf;
		}
		else {
			text = new YYFAR char[textsize];
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
			memcpy(text, yytext, yymin(textsize, oldtextsize));
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
