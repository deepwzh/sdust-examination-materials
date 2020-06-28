/************************************************************
yywcdpop.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yywcpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void yywparser::yydestructpop(int num)
{
	yyassert(num >= 0);
	yyassert(yytop - num >= -1);

	if (yydestructorptr != NULL) {
		while (num > 0) {
			yywstack_t state = yypeek();
			int action = yydestructorptr[state];
			if (action != -1) {
				// user actions in here
				yystacktoval(yytop);
				yypop(1);
				yyaction(action);
			}
			else {
				yypop(1);
			}
			num--;
		}
	}
	else {
		yypop(num);
	}
}

_YL_END

#endif
