/************************************************************
yyacpcre.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yycpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

yybool yyparser::yycreate(yylexer YYFAR* lexerptr)
{
	yylexerptr = lexerptr;

	// stack
	yystack_t YYFAR* sstackptr;
	void YYFAR* sattributestackptr;
	if (yysstack_size != 0) {
		sstackptr = new YYFAR yystack_t[yysstack_size];
		if (sstackptr == NULL) {
			return yyfalse;
		}
		sattributestackptr = yynewattribute(yysstack_size);
		if (sattributestackptr == NULL) {
			delete[] sstackptr;
			return yyfalse;
		}
	}
	else {
		sstackptr = NULL;
		sattributestackptr = NULL;
	}

	// yylval
	void YYFAR* lvalptr = yynewattribute(1);
	if (lvalptr == NULL) {
		delete[] sstackptr;
		yydeleteattribute(sattributestackptr);
		return yyfalse;
	}

	// yyval ($$)
	void YYFAR* valptr = yynewattribute(1);
	if (valptr == NULL) {
		delete[] sstackptr;
		yydeleteattribute(sattributestackptr);
		yydeleteattribute(lvalptr);
		return yyfalse;
	}

	// assign
	yysstackptr = sstackptr;
	yysattributestackptr = sattributestackptr;
	yylvalptr = lvalptr;
	yyvalptr = valptr;

	yystackptr = yysstackptr;
	yyattributestackptr = yysattributestackptr;
	yystack_size = yysstack_size;

	return yytrue;
}

_YL_END

#endif
