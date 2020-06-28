/************************************************************
yyaswrk.c
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
int YYCDECL yywork(void)
#else
int YYCDECL yywork()
#endif
{
	int errorpop = 0;
	while (1) {
		unsigned char type;
		short sr;
		yystack_t state = yypeek();			/* get top state */
		while (1) {
			if (yystateaction[state].yylookahead) {
				int index;
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
				index = yystateaction[state].yybase + yychar;
				if (index >= 0 && index < yytokenaction_size) {
					if (yytokenaction[index].yycheck == state) {
						type = yytokenaction[index].yytype;
						sr = yytokenaction[index].yysr;
						break;		/* escape from loop */
					}
				}
			}

			type = yystateaction[state].yytype;
			sr = yystateaction[state].yysr;
			if (type != YYAT_DEFAULT) {
				break;		/* escape from loop */
			}
			state = sr;
		}

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
					yywipe();	/* clean up */
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
					yydthrowerror(yyerrorpop);
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
				while (1) {
					int index = yystategoto[state].yybase + nonterm;
					if (index >= 0 && index < yynontermgoto_size) {
						if (yynontermgoto[index].yycheck == state) {
							next = yynontermgoto[index].yynext;
							break;
						}
					}

					next = yystategoto[state].yydef;
					if (next == -1) {
						break;
					}
					state = next;
				}
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
						yywipe();	/* clean up */
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
		if (yyskip < 3 || errorpop > 0) {
#ifdef YYDEBUG
			yydattemptrecovery();
#endif
			yypopflg = YYFALSE;		/* clear flag */
			while (1) {
				state = yypeek();			/* get top state */
				while (1) {
					if (yystateaction[state].yylookahead) {
						int index = yystateaction[state].yybase + YYTK_ERROR;
						if (index >= 0 && index < yytokenaction_size) {
							if (yytokenaction[index].yycheck == state) {
								type = yytokenaction[index].yytype;
								sr = yytokenaction[index].yysr;
								break;		/* escape from loop */
							}
						}
					}

					type = yystateaction[state].yytype;
					sr = yystateaction[state].yysr;
					if (type != YYAT_DEFAULT) {
						break;		/* escape from loop */
					}
					state = sr;
				}

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
								yywipe();	/* clean up */
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
						yywipe();	/* clean up */
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
					if (yytokendestbaseptr != NULL) {
						int i;
						for (i = 0; i < yytokendestbase_size; i++) {
							int index = yytokendestbaseptr[i] + yychar;
							if (index >= 0 && index < yytokendest_size) {
								if (yytokendestptr[index].yycheck == i) {
									/* user actions in here */
									int action = yytokendestptr[index].yyaction;
									yyassert(action != -1);
									memcpy(yyvalptr, yylvalptr, yyattribute_size);

									yyparseraction(action);

									memcpy(yylvalptr, yyvalptr, yyattribute_size);
								}
							}
						}
					}

					yylookahead = YYFALSE;	/* skip erroneous character */
				}
				else {
#ifdef YYDEBUG
					yydabort();
#endif
					if (yywipeflg) {
						yywipe();	/* clean up */
					}
					return 1;
				}
			}
		}
	}
}

_YL_END

#endif
