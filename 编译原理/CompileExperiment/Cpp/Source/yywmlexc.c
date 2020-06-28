/************************************************************
yywmlexc.c
This file can be freely modified for the generation of
custom code.

[Unicode]

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

#include "yywmlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(yywint_t) YYCDECL yywmclex(yywmlexer_t YYFAR *yy)
#else
YYEXPFUNC(yywint_t) YYCDECL yywmclex(yy)
yywmlexer_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	yyassert(yywmiscompactlexer(yy));	/* make sure it's a compact lexical analyser */
	
	while (1) {
		int oldleng;
		int state = 1 + yy->yymstart;
		if (yy->yymeol) {
			state++;
		}
	
		/* yymore */
		if (yy->yymmoreflg) {
			yy->yymmoreflg = YYFALSE;		/* clear flag */
		}
		else {
			yy->yymleng = 0;
			yy->yymoldeol = yy->yymeol;
		}
		oldleng = yy->yymleng;

		/* look for a string */
		do {
			long index;
			yywint_t ch;		/* lookahead character */
			
			/* get input character */
			ch = (*yy->yyminput)(yy);
			yyassert(ch >= 0 && ch <= 0xffff || ch == -1);
			if (ch == -1) {
				break;
			}
			
			/* check for possible overflow */
			if (yy->yymleng == yy->yymtext_size) {
				do {
					if (yy->yymtextgrow) {
						int size;
						if (yy->yymtext_size != 0) {
							size = yy->yymtext_size * 2;
							if (size / 2 != yy->yymtext_size) {		/* overflow check */
								size = yy->yymtext_max;
							}
						}
						else {
							size = 100;
						}
						if (yy->yymtext_max != 0) {
							if (size > yy->yymtext_max) {
								size = yy->yymtext_max;
							}
						}
						if (size > yy->yymtext_size) {
							if (yywmsettextsize(yy, size)) {
								break;
							}
						}
					}
					(*yy->yymtextoverflow)(yy);
					exit(EXIT_FAILURE);
				}
				while (0);
			}

			/* handles eof condition automatically */
			index = yy->yymstate[state].yymbase;
			while (1) {
				if (yy->yymctransition[index].yymnext == -1) {
					state = yy->yymstate[state].yymdef;
					if (state <= 0) {
						if (state < 0) {
							if (ch >= 0 && ch <= 0xffff) {
								state = -state;
							}
							else {
								state = 0;
							}
						}
						break;
					}
					index = yy->yymstate[state].yymbase;
				}
				if (ch >= yy->yymctransition[index].yymfirst &&
					ch <= yy->yymctransition[index].yymlast) {
					state = yy->yymctransition[index].yymnext;
					break;
				}
				index++;
			}

			{
				int leng = yy->yymleng;		/* slightly more efficient */
				yy->yymtext[leng] = (wchar_t) ch;
				yy->yymstatebuf[leng] = state;
				leng++;
				yy->yymleng = leng;
			}
		}
		while (state != 0 && (yy->yymstate[state].yymdef != 0 || yy->yymstate[state].yymbase != 0));

		/* now find a match */
		if (yy->yymleng > oldleng) {
			int rejectmatch = 0;
			while (1) {
				int match = yy->yymstate[yy->yymstatebuf[yy->yymleng - 1]].yymmatch;
				if (rejectmatch != 0) {
					if (match < 0) {
						int index = -match;
						do {
							match = yy->yymmatch[index++];
						}
						while (match > 0 && match <= rejectmatch);
					}
					else {
						if (match == rejectmatch) {
							match = 0;
						}
					}
					rejectmatch = 0;
				}
				else {
					if (match < 0) {
						match = yy->yymmatch[-match];
					}
				}
				if (match > 0) {
					int rejectleng;
					int token;
					/* check for backup */
					if (yy->yymbackup[match]) {
						while (yy->yymleng > oldleng) {
							int index = yy->yymstate[yy->yymstatebuf[yy->yymleng - 1]].yymmatch;
							if (index < 0) {
								if (yywmback(&yy->yymmatch[-index], -match)) {
									break;	/* found an expression */
								}
							}
							yy->yymleng--;
							(*yy->yymunput)(yy, (wchar_t) yy->yymtext[yy->yymleng]);
						}
					}
					yy->yymtext[yy->yymleng] = L'\0';
#ifdef YYDEBUG
					yywmdmatch(yy, match);
#endif
					yy->yymrejectflg = YYFALSE;
					rejectleng = yy->yymleng;

					if (yy->yymleng > 0) {
						yy->yymeol = (YYBOOL) (yy->yymtext[yy->yymleng - 1] == L'\n');
					}
					else {
						yy->yymeol = yy->yymoldeol;
					}

					/* perform user action */
					token = (*yy->yymaction)(yy, match);

					if (yy->yymreturnflg) {
						return token;
					}
					if (!yy->yymrejectflg) {
						break;
					}
					if (rejectleng == yy->yymleng) {
						rejectmatch = match;
					}
				}
				else if (yy->yymleng > oldleng + 1) {
					yy->yymleng--;
					(*yy->yymunput)(yy, (wchar_t) yy->yymtext[yy->yymleng]);
				}
				else {
					yy->yymeol = (YYBOOL) (yy->yymtext[0] == L'\n');
					(*yy->yymoutput)(yy, yy->yymtext[0]);	/* non-matched character */
					break;
				}
			}
		}
		else {
			int index;
			int match;
			yyassert(yy->yymleng == oldleng);

			/* handles <<EOF>> rules */
			index = 0;
			match = yy->yymstate[state].yymmatch;
			if (match < 0) {
				index = -match;
				match = yy->yymmatch[index++];
			}
			while (match > 0) {
				int token;
				yy->yymtext[yy->yymleng] = L'\0';
#ifdef YYDEBUG
				yywmdmatch(yy, match);
#endif
				yy->yymrejectflg = YYFALSE;		/* clear flag */

				/* perform user action */
				token = (*yy->yymaction)(yy, match);

				if (yy->yymreturnflg) {
					return token;
				}
				if (!yy->yymrejectflg) {
					break;
				}

				if (index == 0) {
					break;
				}
				match = yy->yymmatch[index++];
			}

			if ((*yy->yymwrap)(yy)) {
				yy->yymoldeol = YYTRUE;
				yy->yymeol = YYTRUE;
				yy->yymstart = 0;
				return 0;			/* eof reached */
			}
		}
	}
}

_YL_END
