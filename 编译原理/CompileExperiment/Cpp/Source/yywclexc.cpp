/************************************************************
yywclexc.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
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

#include "yywclex.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

_YL_BEGIN

yywint_t yywclexer::yylex()
{
	while (1) {
		int state = 1 + yystart;
		if (yyeol) {
			state++;
		}
	
		// yymore
		if (yymoreflg) {
			yymoreflg = yyfalse;		// clear flag
		}
		else {
			yyleng = 0;
			yyoldeol = yyeol;
		}
		int oldleng = yyleng;

		// look for a string
		do {
			// get input character (lookahead character)
			yywint_t ch = yyinput();
			yyassert(ch >= 0 && ch <= 0xffff || ch == -1);
			if (ch == -1) {
				break;
			}
			
			// check for possible overflow
			if (yyleng == yytext_size) {
				do {
					if (yytextgrow) {
						int size;
						if (yytext_size != 0) {
							size = yytext_size * 2;
							if (size / 2 != yytext_size) {		// overflow check
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

			// look for a transition
			long index = yystate[state].yybase;
			while (1) {
				if (yyctransition[index].yynext == -1) {
					state = yystate[state].yydef;
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
					index = yystate[state].yybase;
				}
				if (ch >= yyctransition[index].yyfirst &&
					ch <= yyctransition[index].yylast) {
					state = yyctransition[index].yynext;
					break;
				}
				index++;
			}

			int leng = yyleng;		// slightly more efficient code
			yytext[leng] = (wchar_t)ch;
			yystatebuf[leng] = state;
			leng++;
			yyleng = leng;
		}
		while (state != 0 && (yystate[state].yydef != 0 || yystate[state].yybase != 0));

		// now find a match
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
					// check for backup
					if (yybackup[match]) {
						while (yyleng > oldleng) {
							int index = yystate[yystatebuf[yyleng - 1]].yymatch;
							if (index < 0) {
								if (yyback(&yymatch[-index], -match)) {
									break;	// found an expression
								}
							}
							yyleng--;
							yyunput((wchar_t)yytext[yyleng]);
						}
					}
					yytext[yyleng] = L'\0';
#ifdef YYDEBUG
					yydmatch(match);
#endif
					yyrejectflg = yyfalse;		// clear flag
					int rejectleng = yyleng;

					if (yyleng > 0) {
						yyeol = (yybool)(yytext[yyleng - 1] == L'\n');
					}
					else {
						yyeol = yyoldeol;
					}

					// perform user action
					yywint_t token = yyaction(match);

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
					yyunput((wchar_t)yytext[yyleng]);
				}
				else {
					yyeol = (yybool)(yytext[0] == L'\n');
					yyoutput(yytext[0]);	// non-matched character
					break;
				}
			}
		}
		else {
			yyassert(yyleng == oldleng);

			// handles <<EOF>> rules
			int index = 0;
			int match = yystate[state].yymatch;
			if (match < 0) {
				index = -match;
				match = yymatch[index++];
			}
			while (match > 0) {
				yytext[yyleng] = L'\0';
#ifdef YYDEBUG
				yydmatch(match);
#endif
				yyrejectflg = yyfalse;		// clear flag

				// perform user action
				yywint_t token = yyaction(match);

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
				yyoldeol = yytrue;
				yyeol = yytrue;
				yystart = 0;
				return 0;			// eof reached
			}
		}
	}
}

_YL_END

#endif
