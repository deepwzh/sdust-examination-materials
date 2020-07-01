/************************************************************
yywmwrkc.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#else
#include <string.h>
#endif

#include "yywmpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yywmcwork(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(int) YYCDECL yywmcwork(yy)
yywmparser_t YYFAR *yy;
#endif
{
	int errorpop = 0;
	yyassert(yy != NULL);
	yyassert(yywmiscompactparser(yy));	/* make sure it's a compact parser */

	while (1) {
		unsigned char type;
		short sr;
		yywstack_t state = yywmpeek(yy);			/* get top state */

		int index = yy->yymcstateaction[state];
		while (1) {
			if (yy->yymctokenaction[index].yymtoken == YYWTK_ALL) {
				if (yy->yymctokenaction[index].yymtype == YYAT_DEFAULT) {
					state = yy->yymctokenaction[index].yymsr;
					index = yy->yymcstateaction[state];
					continue;
				}
				break;
			}

			if (!yy->yymlookahead) {
				yy->yymlookahead = YYTRUE;
				yy->yymchar = (*yy->yymgettoken)(yy);
				if (yy->yymchar < 0) {
					yy->yymchar = 0;
				}
#ifdef YYDEBUG
				yywmdgettoken(yy, yy->yymchar);
#endif
			}
			if (yy->yymctokenaction[index].yymtoken == yy->yymchar) {
				break;
			}
			index++;
		}
		type = yy->yymctokenaction[index].yymtype;
		sr = yy->yymctokenaction[index].yymsr;

		/* action */
		switch (type) {
		case YYAT_SHIFT:
#ifdef YYDEBUG
			yywmdshift(yy, yy->yymchar);
#endif
			if (yy->yymskip > 0) {
				yywmsetskip(yy, yy->yymskip - 1);
			}
			if (!yywmpush(yy, sr)) {
#ifdef YYDEBUG
				yywmdabort(yy);
#endif
				if (yy->yymwipeflg) {
					yywmcwipe(yy);	/* clean up */
				}
				return 1;
			}
			memcpy(&((char YYFAR *) yy->yymattributestackptr)[yy->yymtop *
				yy->yymattribute_size], yy->yymlvalptr, yy->yymattribute_size);
			yy->yymlookahead = YYFALSE;
			continue;		/* go to top of while loop */
		case YYAT_REDUCE:
#ifdef YYDEBUG
			yywmdreduce(yy, sr);
#endif
			yy->yymretireflg = YYFALSE;
			if (yy->yymreduction[sr].yymaction != -1) {
				/* user actions in here */
				if (yy->yymreduction[sr].yymlength > 0) {
					memcpy(yy->yymvalptr, &((char YYFAR *) yy->yymattributestackptr)
						[(yy->yymtop + 1 - yy->yymreduction[sr].yymlength) *
						yy->yymattribute_size], yy->yymattribute_size);
				}
        
				yy->yymerrorflg = YYFALSE;
				yy->yymexitflg = YYFALSE;
				(*yy->yymaction)(yy, yy->yymreduction[sr].yymaction);

				/* check for special user requected actions */
				if (yy->yymexitflg) {
#ifdef YYDEBUG
					yywmexit(yy, yy->yymexitcode);
#endif
					return yy->yymexitcode;
				}
				if (yy->yymerrorflg) {
					errorpop = yy->yymerrorpop;
#ifdef YYDEBUG
					yywmdthrowerror(yy, yy->yymerrorpop);
#endif
					yy->yymerrorcount++;
					break;		/* go to error handler */
				}
			}

			yywmpop(yy, yy->yymreduction[sr].yymlength);
			{
				yywstack_t state = yywmpeek(yy);	/* get top state */
				short next;

				int nonterm = yy->yymreduction[sr].yymnonterm;
				int index = yy->yymcstategoto[state];
				while (1) {
					if (yy->yymcnontermgoto[index].yymnonterm == -1) {
						if (yy->yymcnontermgoto[index].yymnext != -1) {
							state = yy->yymcnontermgoto[index].yymnext;
							index = yy->yymcstategoto[state];
							continue;
						}
						break;
					}
					if (yy->yymcnontermgoto[index].yymnonterm == nonterm) {
						break;
					}
					index++;
				}
				next = yy->yymcnontermgoto[index].yymnext;
				yyassert(next != -1);

				if (!yywmpush(yy, next)) {
#ifdef YYDEBUG
					yywmdabort(yy);
#endif
					// clean up
					if (yy->yymdestructorptr != NULL) {
						int action = yy->yymdestructorptr[next];
						if (action != -1) {
							(*yy->yymaction)(yy, action);
						}
					}
					if (yy->yymwipeflg) {
						yywmcwipe(yy);	/* clean up */
					}
					return 1;
				}
			}
			if (yy->yymreduction[sr].yymaction != -1) {
				memcpy(&((char YYFAR *) yy->yymattributestackptr)
					[yy->yymtop * yy->yymattribute_size],
					yy->yymvalptr, yy->yymattribute_size);
			}
			if (yy->yymretireflg) {
#ifdef YYDEBUG
				yywmdretire(yy, yy->yymretirecode);
#endif
				return yy->yymretirecode;
			}
			continue;		/* go to top of while loop */
		case YYAT_ERROR:
#ifdef YYDEBUG
			yywmdsyntaxerror(yy);
#endif
			if (yy->yymskip == 0) {
				yy->yymerrorcount++;
				(*yy->yymsyntaxerror)(yy);
			}
			break;		/* go to error handler */
		default:
			yyassert(type == YYAT_ACCEPT);
#ifdef YYDEBUG
			yywmdaccept(yy);
#endif
			return 0;
		}

		/* error handler */
		if (yy->yymskip < 3 || errorpop > 0) {
#ifdef YYDEBUG
			yywmdattemptrecovery(yy);
#endif
			yy->yympopflg = YYFALSE;		/* clear flag */
			while (1) {
				state = yywmpeek(yy);			/* get top state */
				index = yy->yymcstateaction[state];
				while (1) {
					if (yy->yymctokenaction[index].yymtoken == YYWTK_ALL) {
						if (yy->yymctokenaction[index].yymtype == YYAT_DEFAULT) {
							state = yy->yymctokenaction[index].yymsr;
							index = yy->yymcstateaction[state];
							continue;
						}
						break;
					}
					if (yy->yymctokenaction[index].yymtoken == YYWTK_ERROR) {
						break;
					}
					index++;
				}
				type = yy->yymctokenaction[index].yymtype;
				sr = yy->yymctokenaction[index].yymsr;

				if (type == YYAT_SHIFT) {
					if (errorpop <= 0) {
#ifdef YYDEBUG
						yywmdshift(yy, YYWTK_ERROR);
#endif
						if (!yywmpush(yy, sr)) {
#ifdef YYDEBUG
							yywmdabort(yy);
#endif
							if (yy->yymwipeflg) {
								yywmcwipe(yy);	/* clean up */
							}
							return 1;
						}
						yywmsetskip(yy, 3);		/* skip 3 erroneous characters */
						break;
					}
					errorpop--;
				}

				yy->yympopflg = YYTRUE;

				/* clean up any symbol attributes */
				if (yy->yymdestructorptr != NULL) {
					int action;
					state = yywmpeek(yy);
					action = yy->yymdestructorptr[state];
					if (action != -1) {
						/* user actions in here */
						memcpy(yy->yymvalptr, &((char YYFAR *) yy->yymattributestackptr)
							[yy->yymtop * yy->yymattribute_size],
							yy->yymattribute_size);
						yywmpop(yy, 1);
						(*yy->yymaction)(yy, action);
					}
					else {
						yywmpop(yy, 1);
					}
				}
				else {
					yywmpop(yy, 1);
				}

				if (yy->yymtop < 0) {
#ifdef YYDEBUG
					yywmdabort(yy);
#endif
					if (yy->yymwipeflg) {
						yywmcwipe(yy);	/* clean up */
					}
					return 1;
				}
			}
		}
		else {
			if (yy->yymlookahead) {
				if (yy->yymchar != 0) {
#ifdef YYDEBUG
					yywmddiscard(yy, yy->yymchar);
#endif
					(*yy->yymdiscard)(yy, yy->yymchar);

					/* clean up any token attributes */
					if (yy->yymctokendestptr != NULL) {
						YYCONST yywmctokendest_t YYNEARFAR *tokendestptr = yy->yymctokendestptr;
						while (tokendestptr->yymtoken != -1) {
							if (tokendestptr->yymtoken == yy->yymchar) {
								/* user actions in here */
								memcpy(yy->yymvalptr, yy->yymlvalptr, yy->yymattribute_size);

								(*yy->yymaction)(yy, tokendestptr->yymaction);

								memcpy(yy->yymlvalptr, yy->yymvalptr, yy->yymattribute_size);
								break;
							}
							tokendestptr++;
						}
					}

					yy->yymlookahead = YYFALSE;	/* skip erroneous character */
				}
				else {
#ifdef YYDEBUG
					yywmdabort(yy);
#endif
					if (yy->yymwipeflg) {
						yywmcwipe(yy);	/* clean up */
					}
					return 1;
				}
			}
		}
	}
}

_YL_END
