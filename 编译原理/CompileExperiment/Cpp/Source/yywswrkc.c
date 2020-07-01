/************************************************************
yywswrkc.c
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
int YYCDECL yywcwork(void)
#else
int YYCDECL yywcwork()
#endif
{
	int errorpop = 0;
	while (1) {
		unsigned char type;
		short sr;
		yywstack_t state = yywpeek();			/* get top state */

		int index = yywcstateaction[state];
		while (1) {
			if (yywctokenaction[index].yytoken == YYWTK_ALL) {
				if (yywctokenaction[index].yytype == YYAT_DEFAULT) {
					state = yywctokenaction[index].yysr;
					index = yywcstateaction[state];
					continue;
				}
				break;
			}

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
			if (yywctokenaction[index].yytoken == yywchar) {
				break;
			}
			index++;
		}
		type = yywctokenaction[index].yytype;
		sr = yywctokenaction[index].yysr;

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
					yywcwipe();	/* clean up */
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
					yywdthrowerror(errorpop);
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
				int index = yywcstategoto[state];
				while (1) {
					if (yywcnontermgoto[index].yynonterm == -1) {
						if (yywcnontermgoto[index].yynext != -1) {
							state = yywcnontermgoto[index].yynext;
							index = yywcstategoto[state];
							continue;
						}
						break;
					}
					if (yywcnontermgoto[index].yynonterm == nonterm) {
						break;
					}
					index++;
				}
				next = yywcnontermgoto[index].yynext;
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
						yywcwipe();	/* clean up */
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
		if (yywskip < 3 || yywerrorpop > 0) {
#ifdef YYDEBUG
			yywdattemptrecovery();
#endif
			yywpopflg = YYFALSE;		/* clear flag */
			while (yywtop >= 0) {
				state = yywpeek();			/* get top state */
				index = yywcstateaction[state];
				while (1) {
					if (yywctokenaction[index].yytoken == YYWTK_ALL) {
						if (yywctokenaction[index].yytype == YYAT_DEFAULT) {
							state = yywctokenaction[index].yysr;
							index = yywcstateaction[state];
							continue;
						}
						break;
					}
					if (yywctokenaction[index].yytoken == YYWTK_ERROR) {
						break;
					}
					index++;
				}
				type = yywctokenaction[index].yytype;
				sr = yywctokenaction[index].yysr;

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
								yywcwipe();	/* clean up */
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
						yywcwipe();	/* clean up */
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
					if (yywctokendestptr != NULL) {
						YYCONST yywctokendest_t YYNEARFAR *tokendestptr = yywctokendestptr;
						while (tokendestptr->yytoken != -1) {
							if (tokendestptr->yytoken == yywchar) {
								/* user actions in here */
								memcpy(yywvalptr, yywlvalptr, yywattribute_size);

								yywparseraction(tokendestptr->yyaction);

								memcpy(yywlvalptr, yywvalptr, yywattribute_size);
								break;
							}
							tokendestptr++;
						}
					}

					yywlookahead = YYFALSE;	/* skip erroneous character */
				}
				else {
#ifdef YYDEBUG
					yywdabort();
#endif
					if (yywwipeflg) {
						yywcwipe();	/* clean up */
					}
					return 1;
				}
			}
		}
	}
}

_YL_END

#endif
