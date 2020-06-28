/************************************************************
yyacwrkc.cpp
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

int yycparser::yywork()
{
	int errorpop = 0;
	while (1) {
		yystack_t state = yypeek();			// get top state

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
				yylookahead = yytrue;
#ifdef YYDEBUG
				yydgettoken(yychar);
#endif
			}
			if (yyctokenaction[index].yytoken == yychar) {
				break;
			}
			index++;
		}
		unsigned char type = yyctokenaction[index].yytype;
		short sr = yyctokenaction[index].yysr;

		// action
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
					yywipe();	// clean up
				}
				return 1;
			}
			yylvaltostack(yytop);
			yylookahead = yyfalse;
			continue;		// go to top of while loop
		case YYAT_REDUCE:
#ifdef YYDEBUG
			yydreduce(sr);
#endif
			yyretireflg = yyfalse;
			if (yyreduction[sr].yyaction != -1) {
				// user actions in here
				if (yyreduction[sr].yylength > 0) {
					yystacktoval(yytop + 1 - yyreduction[sr].yylength);
				}

				yyerrorflg = yyfalse;
				yyexitflg = yyfalse;
				yyaction(yyreduction[sr].yyaction);

				// check for special user requected actions
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
					break;		// go to error handler
				}
			}

			yypop(yyreduction[sr].yylength);
			{
				yystack_t state = yypeek();       // get top state

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
				short next = yycnontermgoto[index].yynext;
				yyassert(next != -1);

				if (!yypush(next)) {
#ifdef YYDEBUG
					yydabort();
#endif
					// clean up
					if (yydestructorptr != NULL) {
						int action = yydestructorptr[next];
						if (action != -1) {
							yyaction(action);
						}
					}
					if (yywipeflg) {
						yywipe();	// clean up
					}
					return 1;
				}
			}
			if (yyreduction[sr].yyaction != -1) {
				yyvaltostack(yytop);
			}
			if (yyretireflg) {
#ifdef YYDEBUG
				yydretire(yyretirecode);
#endif
				return yyretirecode;
			}
			continue;		// go to top of while loop
		case YYAT_ERROR:
#ifdef YYDEBUG
			yydsyntaxerror();
#endif
			if (yyskip == 0) {
				yyerrorcount++;
				yysyntaxerror();
			}
			break;		// go to error handler
		default:
			yyassert(type == YYAT_ACCEPT);
#ifdef YYDEBUG
			yydaccept();
#endif
			return 0;
		}

		// error handler
		if (yyskip < 3 || yyerrorpop > 0) {
#ifdef YYDEBUG
			yydattemptrecovery();
#endif
			yypopflg = yyfalse;		// clear flag
			while (yytop >= 0) {
				state = yypeek();			// get top state
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
							// clean up
							if (yydestructorptr != NULL) {
								int action = yydestructorptr[sr];
								if (action != -1) {
									yyaction(action);
								}
							}
							if (yywipeflg) {
								yywipe();	// clean up
							}
							return 1;
						}
						yysetskip(3);		// skip 3 erroneous characters
						break;
					}
					errorpop--;
				}

				yypopflg = yytrue;

				// clean up any symbol attributes
				if (yydestructorptr != NULL) {
					state = yypeek();
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
				}
				else {
					yypop(1);
				}

				if (yytop < 0) {
#ifdef YYDEBUG
					yydabort();
#endif
					if (yywipeflg) {
						yywipe();	// clean up
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

					// clean up any token attributes
					if (yyctokendestptr != NULL) {
						const yyctokendest_t YYNEARFAR* tokendestptr = yyctokendestptr;
						while (tokendestptr->yytoken != -1) {
							if (tokendestptr->yytoken == yychar) {
								// user actions in here
								yylvaltoval();

								yyaction(tokendestptr->yyaction);

								yyvaltolval();
								break;
							}
							tokendestptr++;
						}
					}

					yylookahead = yyfalse;	// skip erroneous character
				}
				else {
#ifdef YYDEBUG
					yydabort();
#endif
					if (yywipeflg) {
						yywipe();	// clean up
					}
					return 1;
				}
			}
		}
	}
}

_YL_END

#endif
