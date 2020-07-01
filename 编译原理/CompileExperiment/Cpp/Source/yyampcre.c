/************************************************************
yyampcre.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include "yympars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yymcreateparser(yymparser_t YYFAR *yy, YYCONST yymparser_t YYFAR *src)
#else
YYEXPFUNC(YYBOOL) YYCDECL yymcreateparser(yy, src)
yymparser_t YYFAR *yy;
YYCONST yymparser_t YYFAR *src;
#endif
{
	yyassert(yy != NULL);
	yyassert(src != NULL);

	*yy = *src;

	/* stack */
	if (yy->yymsstack_size != 0) {
		size_t stackcharsize;
		size_t attributestackcharsize;

		stackcharsize = yy->yymsstack_size * sizeof(yystack_t);
		if ((int) (stackcharsize / sizeof(yystack_t)) != yy->yymsstack_size) {
			return YYFALSE;		/* integer overflow */
		}
		attributestackcharsize = yy->yymsstack_size * yy->yymattribute_size;
		if ((int) (attributestackcharsize / yy->yymattribute_size) != yy->yymsstack_size) {
			return YYFALSE;		/* integer overflow */
		}
		
		yy->yymsstackptr = (yystack_t YYFAR *) malloc(stackcharsize);
		if (yy->yymsstackptr == NULL) {
			return YYFALSE;
		}
		yy->yymsattributestackptr = malloc(attributestackcharsize);
		if (yy->yymsattributestackptr == NULL) {
			free(yy->yymsstackptr);
			return YYFALSE;
		}
	}
	else {
		yy->yymsstackptr = NULL;
		yy->yymsattributestackptr = NULL;
	}
	yy->yymstack_size = yy->yymsstack_size;
	yy->yymstackptr = yy->yymsstackptr;
	yy->yymattributestackptr = yy->yymsattributestackptr;

	/* yylval */
	yy->yymlvalptr = malloc(yy->yymattribute_size);
	if (yy->yymlvalptr == NULL) {
		free(yy->yymsstackptr);
		free(yy->yymsattributestackptr);
		return YYFALSE;
	}

	/* yyval ($$) */
	yy->yymvalptr = malloc(yy->yymattribute_size);
	if (yy->yymvalptr == NULL) {
		free(yy->yymsstackptr);
		free(yy->yymsattributestackptr);
		free(yy->yymlvalptr);
		return YYFALSE;
	}

	return YYTRUE;
}

_YL_END
