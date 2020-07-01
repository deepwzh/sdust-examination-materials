/************************************************************
yywcdci.cpp
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

void yywfparser::yydestructclearin()
{
	if (yylookahead) {
		// clean up any token attributes
		if (yytokendestbaseptr != NULL) {
			for (int i = 0; i < yytokendestbase_size; i++) {
				long index = yytokendestbaseptr[i] + yychar;
				if (index >= 0 && index < yytokendest_size) {
					if (yytokendestptr[index].yycheck == i) {
						// user actions in here
						yylvaltoval();

						int action = yytokendestptr[index].yyaction;
						yyassert(action != -1);
						yyaction(action);

						yyvaltolval();
					}
				}
			}
		}
		yylookahead = yyfalse;
	}
}

_YL_END

#endif
