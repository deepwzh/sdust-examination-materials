/************************************************************
yyacdci.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#include "yycpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

void yyfparser::yydestructclearin()
{
	if (yylookahead) {
		// clean up any token attributes
		if (yytokendestbaseptr != NULL) {
			for (int i = 0; i < yytokendestbase_size; i++) {
				int index = yytokendestbaseptr[i] + yychar;
				if (index >= 0 && index < yytokendest_size) {
					if (yytokendestptr[index].yycheck == i) {
						// user actions in here
						int action = yytokendestptr[index].yyaction;
						yyassert(action != -1);
						yylvaltoval();

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
