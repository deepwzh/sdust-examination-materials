/************************************************************
yyaslexc.c
This file can be freely modified for the generation of
custom code.

[MBCS]

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

#include "yylex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
int YYCDECL yyclex(void)
#else
int YYCDECL yyclex()
#endif
{
	while (1) {
		int oldleng;
		int state = 1 + yystart;
		if (yyeol) {
			state++;
		}
	
		/* yymore */
		if (yymoreflg) {
			yymoreflg = YYFALSE;		/* clear flag */
		}
		else {
			yyleng = 0;
			yyoldeol = yyeol;
		}
		oldleng = yyleng;

		/* look for a string */
		do {
			int index;
			int ch;		/* lookahead character */

			/* get input character */
			ch = yyinput();
			yyassert(ch >= 0 && ch <= UCHAR_MAX || ch == EOF);
			if (ch == EOF) {
				break;
			}

			/* check for possible overflow */
			if (yyleng == yytext_size) {
				do {
					if (yytextgrow) {
						int size;
						if (yytext_size != 0) {
							size = yytext_size * 2;
							if (size / 2 != yytext_size) {		/* overflow check */
								size = yytext_max;
							}
						}
						else {
							size = 100;
						}
						if (yytext_max != 0) {
							if (size > yytext_max) {
								size = yytext_max;
							}
						}
						if (size > yytext_size) {
							if (yysettextsize(size)) {
								break;
							}
						}
					}
					yytextoverflow();
					exit(EXIT_FAILURE);
				}
				while (0);
			}

			/* look for a transition */
			index = yystate[state].yybase;
			while (1) {
				if (yyctransition[index].yynext == -1) {
					state = yystate[state].yydef;
					if (state <= 0) {
						if (state < 0) {
							if (ch >= 0 && ch <= 0xff) {
								state = -state;
							}
							else {
								state = 0;
							}
						}
						break;
					}
					index = yystate[state].yybase;
				}
				if (ch >= yyctransition[index].yyfirst &&
					ch <= yyctransition[index].yylast) {
					state = yyctransition[index].yynext;
					break;
				}
				index++;
			}

			{
				int leng = yyleng;		/* slightly more efficient */
				yytext[leng] = (char) ch;
				yystatebuf[leng] = state;
				leng++;
				yyleng = leng;
			}
		}
		while (state != 0 && (yystate[state].yydef != 0 || yystate[state].yybase != 0));

		/* now find a match */
		if (yyleng > oldleng) {
			int rejectmatch = 0;
			while (1) {
				int match = yystate[yystatebuf[yyleng - 1]].yymatch;
				if (rejectmatch != 0) {
					if (match < 0) {
						int index = -match;
						do {
							match = yymatch[index++];
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
						match = yymatch[-match];
					}
				}
				if (match > 0) {
					int rejectleng;
					int token;
					/* check for backup */
					if (yybackup[match]) {
						while (yyleng > oldleng) {
							int index = yystate[yystatebuf[yyleng - 1]].yymatch;
							if (index < 0) {
								if (yyback(&yymatch[-index], -match)) {
									break;	/* found an expression */
								}
							}
							yyleng--;
							yyunput((unsigned char) yytext[yyleng]);
						}
					}
					yytext[yyleng] = '\0';
#ifdef YYDEBUG
					yydmatch(match);
#endif
					yyrejectflg = YYFALSE;		/* clear flag */
					rejectleng = yyleng;

					if (yyleng > 0) {
						yyeol = (YYBOOL) (yytext[yyleng - 1] == '\n');
					}
					else {
						yyeol = yyoldeol;
					}

					/* perform user action */
					token = yylexeraction(match);

					if (yyreturnflg) {
						return token;
					}
					if (!yyrejectflg) {
						break;
					}
					if (rejectleng == yyleng) {
						rejectmatch = match;
					}
				}
				else if (yyleng > oldleng + 1) {
					yyleng--;
					yyunput((unsigned char) yytext[yyleng]);
				}
				else {
					yyeol = (YYBOOL) (yytext[0] == '\n');
					yyoutput(yytext[0]);	/* non-matched character */
					break;
				}
			}
		}
		else {
			int index;
			int match;
			yyassert(yyleng == oldleng);

			/* handles <<EOF>> rules */
			index = 0;
			match = yystate[state].yymatch;
			if (match < 0) {
				index = -match;
				match = yymatch[index++];
			}
			while (match > 0) {
				int token;
				yytext[yyleng] = '\0';
#ifdef YYDEBUG
				yydmatch(match);
#endif
				yyrejectflg = YYFALSE;		/* clear flag */

				/* perform user action */
				token = yylexeraction(match);

				if (yyreturnflg) {
					return token;
				}
				if (!yyrejectflg) {
					break;
				}

				if (index == 0) {
					break;
				}
				match = yymatch[index++];
			}

			if (yywrap()) {
				yyoldeol = YYTRUE;
				yyeol = YYTRUE;
				yystart = 0;
				return 0;			/* eof reached */
			}
		}
	}
}

_YL_END

#endif
