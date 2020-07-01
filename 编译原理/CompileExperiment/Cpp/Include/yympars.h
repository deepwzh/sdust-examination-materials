#ifndef YYMPARS_H
#define YYMPARS_H

/************************************************************
yympars.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* globals */
#include <yyglobal.h>

/* defines */
#include <yytdefs.h>

/* user defines */
#if defined(YYTUDEFS) || defined(YYUDEFS)
#include <yytudefs.h>
#endif

/* standard include files */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#include <cstddef>
#else
#include <stdio.h>
#include <stddef.h>
#endif

#ifndef YYCSTD
#if defined(__cplusplus) && defined(YYCSTDCPPLIB)
#define YYCSTD std::
#else
#define YYCSTD
#endif
#endif

/* namespace */
#if defined(__cplusplus) && defined(YYNAMESPACE)
#ifndef _YL_NAME
#define _YL_NAME	yl
#endif
#ifndef _YL
#define _YL			yl::
#endif
#ifndef _YL_BEGIN
#define _YL_BEGIN	namespace yl {
#endif
#ifndef _YL_END
#define _YL_END		}
#endif
#else
#ifndef _YL_NAME
#define _YL_NAME
#endif
#ifndef _YL
#define _YL
#endif
#ifndef _YL_BEGIN
#define _YL_BEGIN
#endif
#ifndef _YL_END
#define _YL_END
#endif
#endif

_YL_BEGIN

#ifdef __cplusplus
extern "C" {
#endif

#define YY_AYACC

/* modifiers */
#ifndef YYEXPCLASS
#define YYEXPCLASS
#endif
#ifndef YYEXPDATA
#define YYEXPDATA(x) x
#endif
#ifndef YYEXPFUNC
#define YYEXPFUNC(x) x
#endif
#ifndef YYCDECL
#define YYCDECL
#endif
#ifndef YYDCDECL
#define YYDCDECL
#endif
#ifndef YYNEAR
#define YYNEAR
#endif
#ifndef YYFAR
#define YYFAR
#endif
#ifndef YYNEARFAR
#define YYNEARFAR
#endif
#ifndef YYBASED_CODE
#define YYBASED_CODE
#endif

/* function prototypes */
#ifndef YYPROTOTYPE
#if defined(__STDC__) || defined(__cplusplus)
#define YYPROTOTYPE
#endif
#endif

/* qualifiers */
#ifndef YYCONST
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#else
#define YYCONST
#endif
#endif

/* testing */
#ifdef YYNOPROTOTYPE
#undef YYPROTOTYPE
#endif
#ifdef YYNOCONST
#undef YYCONST
#define YYCONST
#endif

typedef short yystack_t;

/* yyparse return values */
#define YYEXIT_SUCCESS	0
#define YYEXIT_FAILURE	1

/* common tokens */
#define YYTK_ALL		(-1)		/* match all tokens */
#define YYTK_END		0			/* $end token */
#define YYTK_ERROR		256			/* error token */

typedef short yycstategoto_t;

#ifndef YYMCNONTERMGOTO_T
#define YYMCNONTERMGOTO_T
typedef struct yymcnontermgoto {
	short yymnonterm;				/* nonterminal */
	short yymnext;					/* next state */
} yymcnontermgoto_t;
#endif

#ifndef YYMSTATEGOTO_T
#define YYMSTATEGOTO_T
typedef struct yymstategoto {
	short yymbase;					/* base */
	short yymdef;					/* default state */
} yymstategoto_t;
#endif

#ifndef YYMNONTERMGOTO_T
#define YYMNONTERMGOTO_T
typedef struct yymnontermgoto {
	short yymcheck;					/* check */
	short yymnext;					/* next state */
} yymnontermgoto_t;
#endif

/* action types */
#define YYAT_SHIFT		0			/* shift action */
#define YYAT_REDUCE		1			/* reduce action */
#define YYAT_ERROR		2			/* error */
#define YYAT_ACCEPT		3			/* accept */
#define YYAT_DEFAULT	4			/* default state */

typedef short yycstateaction_t;

#ifndef YYMCTOKENACTION_T
#define YYMCTOKENACTION_T
typedef struct yymctokenaction {
	int yymtoken;					/* lookahead token */
	unsigned char yymtype;			/* action to perform */
	short yymsr;					/* state to shift/production to reduce */
} yymctokenaction_t;
#endif

#ifndef YYMSTATEACTION_T
#define YYMSTATEACTION_T
typedef struct yymstateaction {
	short yymbase;					/* base */
	unsigned char yymlookahead;		/* lookahead needed */
	unsigned char yymtype;			/* action to perform */
	short yymsr;					/* shift/reduce */
} yymstateaction_t;
#endif

#ifndef YYMTOKENACTION_T
#define YYMTOKENACTION_T
typedef struct yymtokenaction {
	short yymcheck;					/* check */
	unsigned char yymtype;			/* action type */
	short yymsr;					/* shift/reduce */
} yymtokenaction_t;
#endif

/* nonterminals */
#define YYST_ALL		(-1)		/* match all states */

/* states */
#define YYST_ERROR		(-1)		/* goto error */

#ifndef YYMREDUCTION_T
#define YYMREDUCTION_T
typedef struct yymreduction {
	short yymnonterm;				/* the rhs symbol */
	short yymlength;				/* number of symbols on lhs */
	short yymaction;				/* the user action */
} yymreduction_t;
#endif

typedef short yydestructor_t;

#ifndef YYMTOKENDEST_T
#define YYMTOKENDEST_T
typedef struct yymtokendest {
	short yymcheck;					/* check */
	short yymaction;				/* action */
} yymtokendest_t;
#endif

typedef short yytokendestbase_t;

#ifndef YYMCTOKENDEST_T
#define YYMCTOKENDEST_T
typedef struct yymctokendest {
	int yymtoken;					/* token */
	short yymaction;				/* the user action */
} yymctokendest_t;
#endif

/* debugging */
#ifdef YYDEBUG
#ifndef YYMSYMBOL_T
#define YYMSYMBOL_T
typedef struct yymsymbol {
	YYCONST char *yymname;			/* symbol name */
	int yymtoken;					/* symbol token */
} yymsymbol_t;
#endif
#endif

typedef struct yymparser {
	/* flags */
	YYBOOL yymlookahead;				/* whether current lookahead token is valid */
	YYBOOL yymstackgrow;				/* whether stack can grow */
	YYBOOL yymexitflg;					/* whether yymexit called */
	YYBOOL yymretireflg;				/* whether yymretire called */
	YYBOOL yymerrorflg;					/* whether yymthrowerror called */
	YYBOOL yympopflg;					/* popping symbols during error recovery */
	YYBOOL yymwipeflg;					/* whether to "wipe" stack on abort */

	int yymtop;							/* the current top of the stack */
	int yymchar;						/* current lookahead token */
	int yymskip;						/* error recovery token shift counter */
	int yymerrorcount;					/* how many syntax errors have occurred */
	int yymexitcode;					/* yymexit exit code */
	int yymretirecode;					/* yymretire exit code */
	int yymerrorpop;					/* how many error transitions to pop */
	YYCSTD FILE YYFAR *yymerr;			/* error output file */

	/* stack */
	yystack_t YYFAR *yymstackptr;		/* (state) stack */
	yystack_t YYFAR *yymsstackptr;		/* static (state) stack */
	int yymstack_size;					/* number of elements in stack */
	int yymsstack_size;					/* initial number of elements in stack */
	int yymstack_max;					/* maximum size of the stack */

	size_t yymattribute_size;			/* size of attribute */

#ifdef YYPROTOTYPE
	void YYFAR *yymvalptr;				/* attribute for $$ */
	void YYFAR *yymlvalptr;				/* current token attribute */
	void YYFAR *yymattributestackptr;	/* attribute stack */
	void YYFAR *yymsattributestackptr;	/* static attribute stack */
#else
	char YYFAR *yymvalptr;				/* attribute for $$ */
	char YYFAR *yymlvalptr;				/* current token attribute */
	char YYFAR *yymattributestackptr;	/* attribute stack */
	char YYFAR *yymsattributestackptr;	/* static attribute stack */
#endif

	/* service functions */
#ifdef YYPROTOTYPE
	int (YYCDECL *yymgettoken)(struct yymparser YYFAR *yy);
	void (YYCDECL *yymdiscard)(struct yymparser YYFAR *yy, int token);
	void (YYCDECL *yymsyntaxerror)(struct yymparser YYFAR *yy);
	void (YYCDECL *yymstackoverflow)(struct yymparser YYFAR *yy);
	void (YYCDECL *yymerror)(struct yymparser YYFAR *yy, YYCONST char YYFAR *text);
	void (YYCDECL *yymaction)(struct yymparser YYFAR *yy, int action);
#else
	int (YYCDECL *yymgettoken)();
	void (YYCDECL *yymdiscard)();
	void (YYCDECL *yymsyntaxerror)();
	void (YYCDECL *yymstackoverflow)();
	void (YYCDECL *yymerror)();
	void (YYCDECL *yymaction)();
#endif

	/* tables */
	/* fast parser */
	YYCONST yymstateaction_t YYNEARFAR *yymstateaction;
	YYCONST yymtokenaction_t YYNEARFAR *yymtokenaction;
	int yymtokenaction_size;
	YYCONST yymstategoto_t YYNEARFAR *yymstategoto;
	YYCONST yymnontermgoto_t YYNEARFAR *yymnontermgoto;
	int yymnontermgoto_size;
	YYCONST yymtokendest_t YYNEARFAR *yymtokendestptr;
	int yymtokendest_size;
	YYCONST yytokendestbase_t YYNEARFAR *yymtokendestbaseptr;
	int yymtokendestbase_size;
	/* compact parser */
	YYCONST yycstateaction_t YYNEARFAR *yymcstateaction;
	YYCONST yymctokenaction_t YYNEARFAR *yymctokenaction;
	YYCONST yycstategoto_t YYNEARFAR *yymcstategoto;
	YYCONST yymcnontermgoto_t YYNEARFAR *yymcnontermgoto;
	YYCONST yymctokendest_t YYNEARFAR *yymctokendestptr;
	/* common */
	YYCONST yymreduction_t YYNEARFAR *yymreduction;

	YYCONST yydestructor_t YYNEARFAR *yymdestructorptr;

	struct yymlexer YYFAR *yymlexerptr;		/* lexical analyser */
	void YYFAR *yymdata;					/* user data */

	/* debugging */
#ifdef YYDEBUG
	YYBOOL yymdebug;
	YYBOOL yymdebugstack;
	YYBOOL yymdebugflush;
	YYCSTD FILE YYFAR *yymdebugout;
	YYCONST yymsymbol_t YYNEARFAR *yymsymbol;
	YYCONST char *YYCONST YYNEARFAR *yymrule;
#endif
} yymparser_t;

/* instance functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yymcreateparser(yymparser_t YYFAR *yy, YYCONST yymparser_t YYFAR *src);
YYEXPFUNC(void) YYCDECL yymdestroyparser(yymparser_t YYFAR *yy);
#else
YYEXPFUNC(YYBOOL) YYCDECL yymcreateparser();
YYEXPFUNC(void) YYCDECL yymdestroyparser();
#endif

/* general functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yymcparse(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymcwipe(yymparser_t YYFAR *yy);
YYEXPFUNC(int) YYCDECL yymcwork(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymdestructpop(yymparser_t YYFAR *yy, int num);
YYEXPFUNC(int) YYCDECL yymparse(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymcleanupparser(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yyminitparser(yymparser_t YYFAR *yy);
YYEXPFUNC(YYBOOL) YYCDECL yymsetstacksize(yymparser_t YYFAR *yy, int size);
YYEXPFUNC(int) YYCDECL yymsetup(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymwipe(yymparser_t YYFAR *yy);
YYEXPFUNC(int) YYCDECL yymwork(yymparser_t YYFAR *yy);
#else
YYEXPFUNC(int) YYCDECL yymcparse();
YYEXPFUNC(void) YYCDECL yymcwipe();
YYEXPFUNC(int) YYCDECL yymcwork();
YYEXPFUNC(void) YYCDECL yymdestructpop();
YYEXPFUNC(int) YYCDECL yymparse();
YYEXPFUNC(void) YYCDECL yymcleanupparser();
YYEXPFUNC(void) YYCDECL yyminitparser();
YYEXPFUNC(YYBOOL) YYCDECL yymsetstacksize();
YYEXPFUNC(int) YYCDECL yymsetup();
YYEXPFUNC(void) YYCDECL yymwipe();
YYEXPFUNC(int) YYCDECL yymwork();
#endif

/* service functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yymgettoken(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymdiscard(yymparser_t YYFAR *yy, int token);
YYEXPFUNC(void) YYCDECL yymsyntaxerror(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymstackoverflow(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymparsererror(yymparser_t YYFAR *yy, YYCONST char YYFAR *text);
#else
YYEXPFUNC(int) YYCDECL yymgettoken();
YYEXPFUNC(void) YYCDECL yymdiscard();
YYEXPFUNC(void) YYCDECL yymsyntaxerror();
YYEXPFUNC(void) YYCDECL yymstackoverflow();
YYEXPFUNC(void) YYCDECL yymparsererror();
#endif

/* action functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymcdestructclearin(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymdestructclearin(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymsetin(yymparser_t YYFAR *yy, int token);
YYEXPFUNC(YYBOOL) YYCDECL yymunclearin(yymparser_t YYFAR *yy);
#else
YYEXPFUNC(void) YYCDECL yymcdestructclearin();
YYEXPFUNC(void) YYCDECL yymdestructclearin();
YYEXPFUNC(void) YYCDECL yymsetin();
YYEXPFUNC(YYBOOL) YYCDECL yymunclearin();
#endif
#define yymabort(yy) yymexit((yy), 1)
#define yymaccept(yy) yymexit((yy), 0)
#define yymclearin(yy) ((yy)->yymlookahead = YYFALSE)
#define yymerrok(yy) yymsetskip((yy), 0)
#define yymexit(yy, exitcode) ((yy)->yymexitflg = YYTRUE, (yy)->yymexitcode = (exitcode))
#define yymforceerror(yy) yymthrowerror((yy), 0)
#define yympopping(yy) (yy)->yympopflg
#define yymrecovering(yy) ((yy)->yymskip > 0)
#define yymretire(yy, retirecode) ((yy)->yymretireflg = YYTRUE, (yy)->yymretirecode = (retirecode))
#define yymthrowerror(yy, pop) ((yy)->yymerrorflg = YYTRUE, (yy)->yymerrorpop = (pop))

/* helper functions */
#ifdef YYPROTOTYPE
#ifdef YYDEBUG
YYEXPFUNC(void) YYCDECL yympop(yymparser_t YYFAR *yy, int num);
YYEXPFUNC(void) YYCDECL yymsetskip(yymparser_t YYFAR *yy, int skip);
#endif
YYEXPFUNC(YYBOOL) YYCDECL yympush(yymparser_t YYFAR *yy, yystack_t state);
#else
#ifdef YYDEBUG
YYEXPFUNC(void) YYCDECL yympop();
YYEXPFUNC(void) YYCDECL yymsetskip();
#endif
YYEXPFUNC(YYBOOL) YYCDECL yympush();
#endif
#define yympeek(yy) ((yy)->yymstackptr[(yy)->yymtop])
#ifndef YYDEBUG
#define yympop(yy, num) ((yy)->yymtop -= (num))
#define yymsetskip(yy, skip) ((yy)->yymskip = (skip))
#endif

/* debugging functions */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
YYEXPFUNC(YYCONST char *) YYCDECL yymtokenstring(yymparser_t YYFAR *yy, int token);
YYEXPFUNC(void) YYCDECL yymdgettoken(yymparser_t YYFAR *yy, int token);
YYEXPFUNC(void) YYCDECL yymdshift(yymparser_t YYFAR *yy, int token);
YYEXPFUNC(void) YYCDECL yymdreduce(yymparser_t YYFAR *yy, int rule);
YYEXPFUNC(void) YYCDECL yymdsyntaxerror(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymdaccept(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymdabort(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymddiscard(yymparser_t YYFAR *yy, int token);
YYEXPFUNC(void) YYCDECL yymdexit(yymparser_t YYFAR *yy, int exitcode);
YYEXPFUNC(void) YYCDECL yymdthrowerror(yymparser_t YYFAR *yy, int errorpop);
YYEXPFUNC(void) YYCDECL yymdretire(yymparser_t YYFAR *yy, int retirecode);
YYEXPFUNC(void) YYCDECL yymdattemptrecovery(yymparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymparserdebugoutput(yymparser_t YYFAR *yy, YYCONST char YYFAR *string);
#else
YYEXPFUNC(YYCONST char *) YYCDECL yymtokenstring();
YYEXPFUNC(void) YYCDECL yymdgettoken();
YYEXPFUNC(void) YYCDECL yymdshift();
YYEXPFUNC(void) YYCDECL yymdreduce();
YYEXPFUNC(void) YYCDECL yymdsyntaxerror();
YYEXPFUNC(void) YYCDECL yymdaccept();
YYEXPFUNC(void) YYCDECL yymdabort();
YYEXPFUNC(void) YYCDECL yymddiscard();
YYEXPFUNC(void) YYCDECL yymdexit();
YYEXPFUNC(void) YYCDECL yymdthrowerror();
YYEXPFUNC(void) YYCDECL yymdretire();
YYEXPFUNC(void) YYCDECL yymdattemptrecovery();
YYEXPFUNC(void) YYCDECL yymparserdebugoutput();
#endif
#endif

#define yymisfastparser(yy) ((yy)->yymstateaction != NULL)
#define yymiscompactparser(yy) ((yy)->yymcstateaction != NULL)

/* compatibility */
#define yymparse_t yymparser_t
#define yymcreateparse yymcreateparser
#define yymdestroyparse yymdestroyparser
#define yymparsecleanup yymcleanupparser
#define yymparseinit yyminitparser
#ifdef YYDEBUG
#define yymparsedebugoutput yymparserdebugoutput
#endif

#ifdef __cplusplus
}
#endif

_YL_END

/* user defines */
#if defined(YYBUDEFS) || defined(YYUDEFS)
#include <yybudefs.h>
#endif

/* defines */
#include <yybdefs.h>

#endif
