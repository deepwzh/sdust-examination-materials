/************************************************************
yywswork.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#else
#include <string.h>
#endif

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
int YYCDECL yywwork(void)
#else
int YYCDECL yywwork()
#endif
{
	int errorpop = 0;
	while (1) {
		unsigned char type;
		short sr;
		yywstack_t state = yywpeek();			/* get top state */
		while (1) {
			if (yywstateaction[state].yylookahead) {
				long index;
				if (!yywlookahead) {
					yywchar = yywgettoken();
					if (yywchar < 0) {
						yywchar = 0;
					}
					yywlookahead = YYTRUE;
#ifdef YYDEBUG
					yywdgettoken(yywchar);
#endif
				}
				index = yywstateaction[state].yybase + yywchar;
				if (index >= 0 && index < yywtokenaction_size) {
					if (yywtokenaction[index].yycheck == state) {
						type = yywtokenaction[index].yytype;
						sr = yywtokenaction[index].yysr;
						break;		/* escape from loop */
					}
				}
			}

			type = yywstateaction[state].yytype;
			sr = yywstateaction[state].yysr;
			if (type != YYAT_DEFAULT) {
				break;		/* escape from loop */
			}
			state = sr;
		}

		/* action */
		switch (type) {
		case YYAT_SHIFT:
#ifdef YYDEBUG
			yywdshift(yywchar);
#endif
			if (yywskip > 0) {
				yywsetskip(yywskip - 1);
			}
			if (!yywpush(sr)) {
#ifdef YYDEBUG
				yywdabort();
#endif
				if (yywwipeflg) {
					yywwipe();	/* clean up */
				}
				return 1;
			}
			memcpy(&((char YYFAR *) yywattributestackptr)[yywtop * yywattribute_size],
				yywlvalptr, yywattribute_size);
			yywlookahead = YYFALSE;
			continue;		/* go to top of while loop */
		case YYAT_REDUCE:
#ifdef YYDEBUG
			yywdreduce(sr);
#endif
			yywretireflg = YYFALSE;
			if (yywreduction[sr].yyaction != -1) {
				/* user actions in here */
				if (yywreduction[sr].yylength > 0) {
					memcpy(yywvalptr, &((char YYFAR *) yywattributestackptr)
						[(yywtop + 1 - yywreduction[sr].yylength) * yywattribute_size],
						yywattribute_size);
				}

				yywerrorflg = YYFALSE;
				yywexitflg = YYFALSE;
				yywparseraction(yywreduction[sr].yyaction);

				/* check for special user requected actions */
				if (yywexitflg) {
#ifdef YYDEBUG
					yywdexit(yywexitcode);
#endif
					return yywexitcode;
				}
				if (yywerrorflg) {
					errorpop = yywerrorpop;
#ifdef YYDEBUG
					yywdthrowerror(yywerrorpop);
#endif
					yywerrorcount++;
					break;		/* go to error handler */
				}
			}

			yywpop(yywreduction[sr].yylength);
			{
				yywstack_t state = yywpeek();		/* get top state */
				short next;

				int nonterm = yywreduction[sr].yynonterm;
				while (1) {
					int index = yywstategoto[state].yybase + nonterm;
					if (index >= 0 && index < yywnontermgoto_size) {
						if (yywnontermgoto[index].yycheck == state) {
							next = yywnontermgoto[index].yynext;
							break;
						}
					}

					next = yywstategoto[state].yydef;
					if (next == -1) {
						break;
					}
					state = next;
				}
				yyassert(next != -1);

				if (!yywpush(next)) {
#ifdef YYDEBUG
					yywdabort();
#endif
					// clean up
					if (yywdestructorptr != NULL) {
						int action = yywdestructorptr[next];
						if (action != -1) {
							yywparseraction(action);
						}
					}
					if (yywwipeflg) {
						yywwipe();	/* clean up */
					}
					return 1;
				}
			}
			if (yywreduction[sr].yyaction != -1) {
				memcpy(&((char YYFAR *) yywattributestackptr)[yywtop * yywattribute_size],
					yywvalptr, yywattribute_size);
			}
			if (yywretireflg) {
#ifdef YYDEBUG
				yywdretire(yywretirecode);
#endif
				return yywretirecode;
			}
			continue;		/* go to top of while loop */
		case YYAT_ERROR:
#ifdef YYDEBUG
			yywdsyntaxerror();
#endif
			if (yywskip == 0) {
				yywerrorcount++;
				yywsyntaxerror();
			}
			break;		/* go to error handler */
		default:
			yyassert(type == YYAT_ACCEPT);
#ifdef YYDEBUG
			yywdaccept();
#endif
			return 0;
		}

		/* error handler */
		if (yywskip < 3 || errorpop > 0) {
#ifdef YYDEBUG
			yywdattemptrecovery();
#endif
			yywpopflg = YYFALSE;		/* clear flag */
			while (1) {
				state = yywpeek();			/* get top state */
				while (1) {
					if (yywstateaction[state].yylookahead) {
						long index = yywstateaction[state].yybase + YYWTK_ERROR;
						if (index >= 0 && index < yywtokenaction_size) {
							if (yywtokenaction[index].yycheck == state) {
								type = yywtokenaction[index].yytype;
								sr = yywtokenaction[index].yysr;
								break;		/* escape from loop */
							}
						}
					}

					type = yywstateaction[state].yytype;
					sr = yywstateaction[state].yysr;
					if (type != YYAT_DEFAULT) {
						break;		/* escape from loop */
					}
					state = sr;
				}

				if (type == YYAT_SHIFT) {
					if (errorpop <= 0) {
#ifdef YYDEBUG
						yywdshift(YYWTK_ERROR);
#endif
						if (!yywpush(sr)) {
#ifdef YYDEBUG
							yywdabort();
#endif
							if (yywwipeflg) {
								yywwipe();	/* clean up */
							}
							return 1;
						}
						yywsetskip(3);		/* skip 3 erroneous characters */
						break;
					}
					errorpop--;
				}

				yywpopflg = YYTRUE;

				/* clean up any symbol attributes */
				if (yywdestructorptr != NULL) {
					int action;
					state = yywpeek();
					action = yywdestructorptr[state];
					if (action != -1) {
						/* user actions in here */
						memcpy(yywvalptr, &((char YYFAR *) yywattributestackptr)
							[yywtop * yywattribute_size], yywattribute_size);
						yywpop(1);
						yywparseraction(action);
					}
					else {
						yywpop(1);
					}
				}
				else {
					yywpop(1);
				}

				if (yywtop < 0) {
#ifdef YYDEBUG
					yywdabort();
#endif
					if (yywwipeflg) {
						yywwipe();	/* clean up */
					}
					return 1;
				}
			}
		}
		else {
			if (yywlookahead) {
				if (yywchar != 0) {
#ifdef YYDEBUG
					yywddiscard(yywchar);
#endif
					yywdiscard(yywchar);

					/* clean up any token attributes */
					if (yywtokendestbaseptr != NULL) {
						int i;
						for (i = 0; i < yywtokendestbase_size; i++) {
							long index = yywtokendestbaseptr[i] + yywchar;
							if (index >= 0 && index < yywtokendest_size) {
								if (yywtokendestptr[index].yycheck == i) {
									/* user actions in here */
									int action = yywtokendestptr[index].yyaction;
									yyassert(action != -1);
									memcpy(yywvalptr, yywlvalptr, yywattribute_size);

									yywparseraction(action);

									memcpy(yywlvalptr, yywvalptr, yywattribute_size);
								}
							}
						}
					}

					yywlookahead = YYFALSE;	/* skip erroneous character */
				}
				else {
#ifdef YYDEBUG
					yywdabort();
#endif
					if (yywwipeflg) {
						yywwipe();	/* clean up */
					}
					return 1;
				}
			}
		}
	}
}

_YL_END

#endif
