/************************************************************
yyaswrkc.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#else
#include <string.h>
#endif

#include "yypars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
int YYCDECL yycwork(void)
#else
int YYCDECL yycwork()
#endif
{
	int errorpop = 0;
	while (1) {
		unsigned char type;
		short sr;
		yystack_t state = yypeek();			/* get top state */

		int index = yycstateaction[state];
		while (1) {
			if (yyctokenaction[index].yytoken == YYTK_ALL) {
				if (yyctokenaction[index].yytype == YYAT_DEFAULT) {
					state = yyctokenaction[index].yysr;
					index = yycstateaction[state];
					continue;
				}
				break;
			}

			if (!yylookahead) {
				yychar = yygettoken();
				if (yychar < 0) {
					yychar = 0;
				}
				yylookahead = YYTRUE;
#ifdef YYDEBUG
				yydgettoken(yychar);
#endif
			}
			if (yyctokenaction[index].yytoken == yychar) {
				break;
			}
			index++;
		}
		type = yyctokenaction[index].yytype;
		sr = yyctokenaction[index].yysr;

		/* action */
		switch (type) {
		case YYAT_SHIFT:
#ifdef YYDEBUG
			yydshift(yychar);
#endif
			if (yyskip > 0) {
				yysetskip(yyskip - 1);
			}
			if (!yypush(sr)) {
#ifdef YYDEBUG
				yydabort();
#endif
				if (yywipeflg) {
					yycwipe();	/* clean up */
				}
				return 1;
			}
			memcpy(&((char YYFAR *) yyattributestackptr)[yytop * yyattribute_size],
				yylvalptr, yyattribute_size);
			yylookahead = YYFALSE;
			continue;		/* go to top of while loop */
		case YYAT_REDUCE:
#ifdef YYDEBUG
			yydreduce(sr);
#endif
			yyretireflg = YYFALSE;
			if (yyreduction[sr].yyaction != -1) {
				/* user actions in here */
				if (yyreduction[sr].yylength > 0) {
					memcpy(yyvalptr, &((char YYFAR *) yyattributestackptr)
						[(yytop + 1 - yyreduction[sr].yylength) * yyattribute_size],
						yyattribute_size);
				}

				yyerrorflg = YYFALSE;
				yyexitflg = YYFALSE;
				yyparseraction(yyreduction[sr].yyaction);

				/* check for special user requected actions */
				if (yyexitflg) {
#ifdef YYDEBUG
					yydexit(yyexitcode);
#endif
					return yyexitcode;
				}
				if (yyerrorflg) {
					errorpop = yyerrorpop;
#ifdef YYDEBUG
					yydthrowerror(errorpop);
#endif
					yyerrorcount++;
					break;		/* go to error handler */
				}
			}

			yypop(yyreduction[sr].yylength);
			{
				yystack_t state = yypeek();       /* get top state */
				short next;

				int nonterm = yyreduction[sr].yynonterm;
				int index = yycstategoto[state];
				while (1) {
					if (yycnontermgoto[index].yynonterm == -1) {
						if (yycnontermgoto[index].yynext != -1) {
							state = yycnontermgoto[index].yynext;
							index = yycstategoto[state];
							continue;
						}
						break;
					}
					if (yycnontermgoto[index].yynonterm == nonterm) {
						break;
					}
					index++;
				}
				next = yycnontermgoto[index].yynext;
				yyassert(next != -1);

				if (!yypush(next)) {
#ifdef YYDEBUG
					yydabort();
#endif
					// clean up
					if (yydestructorptr != NULL) {
						int action = yydestructorptr[next];
						if (action != -1) {
							yyparseraction(action);
						}
					}
					if (yywipeflg) {
						yycwipe();	/* clean up */
					}
					return 1;
				}
			}
			if (yyreduction[sr].yyaction != -1) {
				memcpy(&((char YYFAR *) yyattributestackptr)[yytop * yyattribute_size],
					yyvalptr, yyattribute_size);
			}
			if (yyretireflg) {
#ifdef YYDEBUG
				yydretire(yyretirecode);
#endif
				return yyretirecode;
			}
			continue;		/* go to top of while loop */
		case YYAT_ERROR:
#ifdef YYDEBUG
			yydsyntaxerror();
#endif
			if (yyskip == 0) {
				yyerrorcount++;
				yysyntaxerror();
			}
			break;		/* go to error handler */
		default:
			yyassert(type == YYAT_ACCEPT);
#ifdef YYDEBUG
			yydaccept();
#endif
			return 0;
		}

		/* error handler */
		if (yyskip < 3 || yyerrorpop > 0) {
#ifdef YYDEBUG
			yydattemptrecovery();
#endif
			yypopflg = YYFALSE;		/* clear flag */
			while (yytop >= 0) {
				state = yypeek();			/* get top state */
				index = yycstateaction[state];
				while (1) {
					if (yyctokenaction[index].yytoken == YYTK_ALL) {
						if (yyctokenaction[index].yytype == YYAT_DEFAULT) {
							state = yyctokenaction[index].yysr;
							index = yycstateaction[state];
							continue;
						}
						break;
					}
					if (yyctokenaction[index].yytoken == YYTK_ERROR) {
						break;
					}
					index++;
				}
				type = yyctokenaction[index].yytype;
				sr = yyctokenaction[index].yysr;

				if (type == YYAT_SHIFT) {
					if (errorpop <= 0) {
#ifdef YYDEBUG
						yydshift(YYTK_ERROR);
#endif
						if (!yypush(sr)) {
#ifdef YYDEBUG
							yydabort();
#endif
							if (yywipeflg) {
								yycwipe();	/* clean up */
							}
							return 1;
						}
						yysetskip(3);		/* skip 3 erroneous characters */
						break;
					}
					errorpop--;
				}

				yypopflg = YYTRUE;

				/* clean up any symbol attributes */
				if (yydestructorptr != NULL) {
					int action;
					state = yypeek();
					action = yydestructorptr[state];
					if (action != -1) {
						/* user actions in here */
						memcpy(yyvalptr, &((char YYFAR *) yyattributestackptr)
							[yytop * yyattribute_size], yyattribute_size);
						yypop(1);
						yyparseraction(action);
					}
					else {
						yypop(1);
					}
				}
				else {
					yypop(1);
				}

				if (yytop < 0) {
#ifdef YYDEBUG
					yydabort();
#endif
					if (yywipeflg) {
						yycwipe();	/* clean up */
					}
					return 1;
				}
			}
		}
		else {
			if (yylookahead) {
				if (yychar != 0) {
#ifdef YYDEBUG
					yyddiscard(yychar);
#endif
					yydiscard(yychar);

					/* clean up any token attributes */
					if (yyctokendestptr != NULL) {
						YYCONST yyctokendest_t YYNEARFAR *tokendestptr = yyctokendestptr;
						while (tokendestptr->yytoken != -1) {
							if (tokendestptr->yytoken == yychar) {
								/* user actions in here */
								memcpy(yyvalptr, yylvalptr, yyattribute_size);

								yyparseraction(tokendestptr->yyaction);

								memcpy(yylvalptr, yyvalptr, yyattribute_size);
								break;
							}
							tokendestptr++;
						}
					}

					yylookahead = YYFALSE;	/* skip erroneous character */
				}
				else {
#ifdef YYDEBUG
					yydabort();
#endif
					if (yywipeflg) {
						yycwipe();	/* clean up */
					}
					return 1;
				}
			}
		}
	}
}

_YL_END

#endif
