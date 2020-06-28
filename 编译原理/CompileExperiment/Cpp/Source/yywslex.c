/************************************************************
yywslex.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

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

#include "yywlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
yywint_t YYCDECL yywlex(void)
#else
yywint_t YYCDECL yywlex()
#endif
{
	while (1) {
		int oldleng;
		int state = 1 + yywstart;
		if (yyweol) {
			state++;
		}
	
		/* yymore */
		if (yywmoreflg) {
			yywmoreflg = YYFALSE;		/* clear flag */
		}
		else {
			yywleng = 0;
			yywoldeol = yyweol;
		}
		oldleng = yywleng;

		/* look for a string */
		do {
			yywint_t ch;		/* lookahead character */

			/* get input character */
			ch = yywinput();
			yyassert(ch >= 0 && ch <= 0xffff || ch == -1);
			if (ch == -1) {
				break;
			}
			
			/* check for possible overflow */
			if (yywleng == yywtext_size) {
				do {
					if (yywtextgrow) {
						int size;
						if (yywtext_size != 0) {
							size = yywtext_size * 2;
							if (size / 2 != yywtext_size) {		/* overflow check */
								size = yywtext_max;
							}
						}
						else {
							size = 100;
						}
						if (yywtext_max != 0) {
							if (size > yywtext_max) {
								size = yywtext_max;
							}
						}
						if (size > yywtext_size) {
							if (yywsettextsize(size)) {
								break;
							}
						}
					}
					yywtextoverflow();
					exit(EXIT_FAILURE);
				}
				while (0);
			}

			/* look for a transition */
			do {
				long index = yywstate[state].yybase + ch;
				if (index >= 0 && index < yywtransitionmax) {
					if (yywtransition[index].yycheck == state) {
						state = yywtransition[index].yynext;
						break;	/* found a transition */
					}
				}
				state = yywstate[state].yydef;
				if (state < 0) {
					if (ch >= 0 && ch <= 0xffff) {
						state = -state;
					}
					else {
						state = 0;
					}
					break;		/* default transition */
				}
			}
			while (state != 0);

			{
				int leng = yywleng;		/* slightly more efficient */
				yywtext[leng] = (wchar_t) ch;
				yywstatebuf[leng] = state;
				leng++;
				yywleng = leng;
			}
		}
		while (state != 0 && (yywstate[state].yydef != 0 || yywstate[state].yybase != 0));

		/* now find a match */
		if (yywleng > oldleng) {
			int rejectmatch = 0;
			while (1) {
				int match = yywstate[yywstatebuf[yywleng - 1]].yymatch;
				if (rejectmatch != 0) {
					if (match < 0) {
						int index = -match;
						do {
							match = yywmatch[index++];
						}
						while (match > 0 && match <= rejectmatch);
					}
					else {
						match = 0;
					}
					rejectmatch = 0;
				}
				else {
					if (match < 0) {
						match = yywmatch[-match];
					}
				}
				if (match > 0) {
					int rejectleng;
					yywint_t token;
					/* check for backup */
					if (yywbackup[match]) {
						while (yywleng > oldleng) {
							int index = yywstate[yywstatebuf[yywleng - 1]].yymatch;
							if (index < 0) {
								if (yywback(&yywmatch[-index], -match)) {
									break;	/* found an expression */
								}
							}
							yywleng--;
							yywunput((wchar_t) yywtext[yywleng]);
						}
					}
					yywtext[yywleng] = L'\0';
#ifdef YYDEBUG
					yywdmatch(match);
#endif
					yywrejectflg = YYFALSE;		/* clear flag */
					rejectleng = yywleng;

					if (yywleng > 0) {
						yyweol = (YYBOOL) (yywtext[yywleng - 1] == L'\n');
					}
					else {
						yyweol = yywoldeol;
					}

					/* perform user action */
					token = yywlexeraction(match);

					if (yywreturnflg) {
						return token;
					}
					if (!yywrejectflg) {
						break;
					}
					if (rejectleng == yywleng) {
						rejectmatch = match;
					}
				}
				else if (yywleng > oldleng + 1) {
					yywleng--;
					yywunput((wchar_t) yywtext[yywleng]);
				}
				else {
					yyweol = (YYBOOL) (yywtext[0] == L'\n');
					yywoutput(yywtext[0]);	/* non-matched character */
					break;
				}
			}
		}
		else {
			int index;
			int match;
			yyassert(yywleng == oldleng);

			/* handles <<EOF>> rules */
			index = 0;
			match = yywstate[state].yymatch;
			if (match < 0) {
				index = -match;
				match = yywmatch[index++];
			}
			while (match > 0) {
				yywint_t token;
				yywtext[yywleng] = L'\0';
#ifdef YYDEBUG
				yywdmatch(match);
#endif
				yywrejectflg = YYFALSE;		/* clear flag */

				/* perform user action */
				token = yywlexeraction(match);

				if (yywreturnflg) {
					return token;
				}
				if (!yywrejectflg) {
					break;
				}

				if (index == 0) {
					break;
				}
				match = yywmatch[index++];
			}

			if (yywwrap()) {
				yywoldeol = YYTRUE;
				yyweol = YYTRUE;
				yywstart = 0;
				return 0;			/* eof reached */
			}
		}
	}
}

_YL_END

#endif
