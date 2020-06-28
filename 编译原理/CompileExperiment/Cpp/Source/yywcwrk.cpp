/************************************************************
yywcwrk.cpp
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

int yywfparser::yywork()
{
	int errorpop = 0;
	while (1) {
		unsigned char type;
		short sr;
		yywstack_t state = yypeek();			// get top state
		while (1) {
			if (yystateaction[state].yylookahead) {
				long index;
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
				index = yystateaction[state].yybase + yychar;
				if (index >= 0 && index < yytokenaction_size) {
					if (yytokenaction[index].yycheck == state) {
						type = yytokenaction[index].yytype;
						sr = yytokenaction[index].yysr;
						break;		// escape from loop
					}
				}
			}

			type = yystateaction[state].yytype;
			sr = yystateaction[state].yysr;
			if (type != YYAT_DEFAULT) {
				break;		// escape from loop
			}
			state = sr;
		}

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
				yywstack_t state = yypeek();       // get top state
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
		if (yyskip < 3 || errorpop > 0) {
#ifdef YYDEBUG
			yydattemptrecovery();
#endif
			yypopflg = yyfalse;		// clear flag
			while (1) {
				state = yypeek();			// get top state
				while (1) {
					if (yystateaction[state].yylookahead) {
						long index = yystateaction[state].yybase + YYWTK_ERROR;
						if (index >= 0 && index < yytokenaction_size) {
							if (yytokenaction[index].yycheck == state) {
								type = yytokenaction[index].yytype;
								sr = yytokenaction[index].yysr;
								break;		// escape from loop
							}
						}
					}

					type = yystateaction[state].yytype;
					sr = yystateaction[state].yysr;
					if (type != YYAT_DEFAULT) {
						break;		// escape from loop
					}
					state = sr;
				}

				if (type == YYAT_SHIFT) {
					if (errorpop <= 0) {
#ifdef YYDEBUG
						yydshift(YYWTK_ERROR);
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
