/************************************************************
yyamwrk.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#else
#include <string.h>
#endif

#include "yympars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yymwork(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(int) YYCDECL yymwork(yy)
yymparser_t YYFAR *yy;
#endif
{
	int errorpop = 0;
	yyassert(yy != NULL);
	yyassert(yymisfastparser(yy));	/* make sure it's a fast parser */

	while (1) {
		unsigned char type;
		short sr;
		yystack_t state = yympeek(yy);			/* get top state */

		while (1) {
			if (yy->yymstateaction[state].yymlookahead) {
				int index;
				if (!yy->yymlookahead) {
					yy->yymlookahead = YYTRUE;
					yy->yymchar = (*yy->yymgettoken)(yy);
					if (yy->yymchar < 0) {
						yy->yymchar = 0;
					}
#ifdef YYDEBUG
					yymdgettoken(yy, yy->yymchar);
#endif
				}
				index = yy->yymstateaction[state].yymbase + yy->yymchar;
				if (index >= 0 && index < yy->yymtokenaction_size) {
					if (yy->yymtokenaction[index].yymcheck == state) {
						type = yy->yymtokenaction[index].yymtype;
						sr = yy->yymtokenaction[index].yymsr;
						break;		/* escape from loop */
					}
				}
			}

			type = yy->yymstateaction[state].yymtype;
			sr = yy->yymstateaction[state].yymsr;
			if (type != YYAT_DEFAULT) {
				break;		/* escape from loop */
			}
			state = sr;
		}

		/* action */
		switch (type) {
		case YYAT_SHIFT:
#ifdef YYDEBUG
			yymdshift(yy, yy->yymchar);
#endif
			if (yy->yymskip > 0) {
				yymsetskip(yy, yy->yymskip - 1);
			}
			if (!yympush(yy, sr)) {
#ifdef YYDEBUG
				yymdabort(yy);
#endif
				if (yy->yymwipeflg) {
					yymwipe(yy);	/* clean up */
				}
				return 1;
			}
			memcpy(&((char YYFAR *) yy->yymattributestackptr)[yy->yymtop *
				yy->yymattribute_size], yy->yymlvalptr, yy->yymattribute_size);
			yy->yymlookahead = YYFALSE;
			continue;		/* go to top of while loop */
		case YYAT_REDUCE:
#ifdef YYDEBUG
			yymdreduce(yy, sr);
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
					yymdexit(yy, yy->yymexitcode);
#endif
					return yy->yymexitcode;
				}
				if (yy->yymerrorflg) {
					errorpop = yy->yymerrorpop;
#ifdef YYDEBUG
					yymdthrowerror(yy, yy->yymerrorpop);
#endif
					yy->yymerrorcount++;
					break;		/* go to error handler */
				}
			}

			yympop(yy, yy->yymreduction[sr].yymlength);
			{
				yystack_t state = yympeek(yy);	/* get top state */
				short next;

				int nonterm = yy->yymreduction[sr].yymnonterm;
				while (1) {
					int index = yy->yymstategoto[state].yymbase + nonterm;
					if (index >= 0 && index < yy->yymnontermgoto_size) {
						if (yy->yymnontermgoto[index].yymcheck == state) {
							next = yy->yymnontermgoto[index].yymnext;
							break;
						}
					}

					next = yy->yymstategoto[state].yymdef;
					if (next == -1) {
						break;
					}
					state = next;
				}
				yyassert(next != -1);
    
				if (!yympush(yy, next)) {
#ifdef YYDEBUG
					yymdabort(yy);
#endif
					// clean up
					if (yy->yymdestructorptr != NULL) {
						int action = yy->yymdestructorptr[next];
						if (action != -1) {
							(*yy->yymaction)(yy, action);
						}
					}
					if (yy->yymwipeflg) {
						yymwipe(yy);	/* clean up */
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
				yymdretire(yy, yy->yymretirecode);
#endif
				return yy->yymretirecode;
			}
			continue;		/* go to top of while loop */
		case YYAT_ERROR:
#ifdef YYDEBUG
				yymdsyntaxerror(yy);
#endif
			if (yy->yymskip == 0) {
				yy->yymerrorcount++;
				(*yy->yymsyntaxerror)(yy);
			}
			break;		/* go to error handler */
		default:
			yyassert(type == YYAT_ACCEPT);
#ifdef YYDEBUG
			yymdaccept(yy);
#endif
			return 0;
		}

		/* error handler */
		if (yy->yymskip < 3 || errorpop > 0) {
#ifdef YYDEBUG
			yymdattemptrecovery(yy);
#endif
			yy->yympopflg = YYFALSE;		/* clear flag */
			while (1) {
				state = yympeek(yy);			/* get top state */
				while (1) {
					int index = yy->yymstateaction[state].yymbase + YYTK_ERROR;
					if (index >= 0 && index < yy->yymtokenaction_size) {
						if (yy->yymtokenaction[index].yymcheck == state) {
							type = yy->yymtokenaction[index].yymtype;
							sr = yy->yymtokenaction[index].yymsr;
							break;		/* escape from loop */
						}
					}

					type = yy->yymstateaction[state].yymtype;
					sr = yy->yymstateaction[state].yymsr;
					if (type != YYAT_DEFAULT) {
						break;		/* escape from loop */
					}
					state = sr;
				}

				if (type == YYAT_SHIFT) {
					if (errorpop <= 0) {
#ifdef YYDEBUG
						yymdshift(yy, YYTK_ERROR);
#endif
						if (!yympush(yy, sr)) {
#ifdef YYDEBUG
							yymdabort(yy);
#endif
							if (yy->yymwipeflg) {
								yymwipe(yy);	/* clean up */
							}
							return 1;
						}
						yymsetskip(yy, 3);		/* skip 3 erroneous characters */
						break;
					}
					errorpop--;
				}

				yy->yympopflg = YYTRUE;

				/* clean up any symbol attributes */
				if (yy->yymdestructorptr != NULL) {
					int action;
					state = yympeek(yy);
					action = yy->yymdestructorptr[state];
					if (action != -1) {
						/* user actions in here */
						memcpy(yy->yymvalptr, &((char YYFAR *) yy->yymattributestackptr)
							[yy->yymtop * yy->yymattribute_size],
							yy->yymattribute_size);
						yympop(yy, 1);
						(*yy->yymaction)(yy, action);
					}
					else {
						yympop(yy, 1);
					}
				}
				else {
					yympop(yy, 1);
				}

				if (yy->yymtop < 0) {
#ifdef YYDEBUG
					yymdabort(yy);
#endif
					if (yy->yymwipeflg) {
						yymwipe(yy);	/* clean up */
					}
					return 1;
				}
			}
		}
		else {
			if (yy->yymlookahead) {
				if (yy->yymchar != 0) {
#ifdef YYDEBUG
					yymddiscard(yy, yy->yymchar);
#endif
					(*yy->yymdiscard)(yy, yy->yymchar);

					/* clean up any token attributes */
					if (yy->yymtokendestbaseptr != NULL) {
						int i;
						for (i = 0; i < yy->yymtokendestbase_size; i++) {
							int index = yy->yymtokendestbaseptr[i] + yy->yymchar;
							if (index >= 0 && index < yy->yymtokendest_size) {
								if (yy->yymtokendestptr[index].yymcheck == i) {
									/* user actions in here */
									int action = yy->yymtokendestptr[index].yymaction;
									yyassert(action != -1);
									memcpy(yy->yymvalptr, yy->yymlvalptr, yy->yymattribute_size);

									(*yy->yymaction)(yy, action);

									memcpy(yy->yymlvalptr, yy->yymvalptr, yy->yymattribute_size);
								}
							}
						}
					}

					yy->yymlookahead = YYFALSE;	/* skip erroneous character */
				}
				else {
#ifdef YYDEBUG
					yymdabort(yy);
#endif
					if (yy->yymwipeflg) {
						yymwipe(yy);	/* clean up */
					}
					return 1;
				}
			}
		}
	}
}

_YL_END
