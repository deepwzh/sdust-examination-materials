#ifndef YYWMPARS_H
#define YYWMPARS_H

/************************************************************
yywmpars.h
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

#ifndef YYWINT_T
#define YYWINT_T
#ifdef YYWIN32
typedef int yywint_t;
#else
typedef long yywint_t;
#endif
#endif

typedef short yywstack_t;

/* yyparse return values */
#define YYEXIT_SUCCESS	0
#define YYEXIT_FAILURE	1

/* common tokens */
#define YYWTK_ALL		(-1)		/* match all tokens */
#define YYWTK_END		0			/* $end token */
#define YYWTK_ERROR		65536		/* (wide) error token */

typedef short yywcstategoto_t;

#ifndef YYWMCNONTERMGOTO_T
#define YYWMCNONTERMGOTO_T
typedef struct yywmcnontermgoto {
	short yymnonterm;				/* nonterminal */
	short yymnext;					/* next state */
} yywmcnontermgoto_t;
#endif

#ifndef YYWMSTATEGOTO_T
#define YYWMSTATEGOTO_T
typedef struct yywmstategoto {
	short yymbase;					/* base */
	short yymdef;					/* default state */
} yywmstategoto_t;
#endif

#ifndef YYWMNONTERMGOTO_T
#define YYWMNONTERMGOTO_T
typedef struct yywmnontermgoto {
	short yymcheck;					/* check */
	short yymnext;					/* next state */
} yywmnontermgoto_t;
#endif

/* action types */
#define YYAT_SHIFT		0			/* shift action */
#define YYAT_REDUCE		1			/* reduce action */
#define YYAT_ERROR		2			/* error */
#define YYAT_ACCEPT		3			/* accept */
#define YYAT_DEFAULT	4			/* default state */

typedef short yywcstateaction_t;

#ifndef YYWMCTOKENACTION_T
#define YYWMCTOKENACTION_T
typedef struct yywmctokenaction {
	yywint_t yymtoken;				/* lookahead token */
	unsigned char yymtype;			/* action to perform */
	short yymsr;					/* state to shift/production to reduce */
} yywmctokenaction_t;
#endif

#ifndef YYWMSTATEACTION_T
#define YYWMSTATEACTION_T
typedef struct yywmstateaction {
	long yymbase;					/* base */
	unsigned char yymlookahead;		/* lookahead needed */
	unsigned char yymtype;			/* action to perform */
	short yymsr;					/* shift/reduce */
} yywmstateaction_t;
#endif

#ifndef YYWMTOKENACTION_T
#define YYWMTOKENACTION_T
typedef struct yywmtokenaction {
	short yymcheck;					/* check */
	unsigned char yymtype;			/* action type */
	short yymsr;					/* shift/reduce */
} yywmtokenaction_t;
#endif

/* nonterminals */
#define YYST_ALL		(-1)		/* match all states */

/* states */
#define YYST_ERROR		(-1)		/* goto error */

#ifndef YYWMREDUCTION_T
#define YYWMREDUCTION_T
typedef struct yywmreduction {
	short yymnonterm;				/* the rhs symbol */
	short yymlength;				/* number of symbols on lhs */
	short yymaction;				/* the user action */
} yywmreduction_t;
#endif

typedef short yywdestructor_t;

#ifndef YYWMTOKENDEST_T
#define YYWMTOKENDEST_T
typedef struct yywmtokendest {
	short yymcheck;					/* check */
	short yymaction;				/* action */
} yywmtokendest_t;
#endif

typedef long yywtokendestbase_t;

#ifndef YYWMCTOKENDEST_T
#define YYWMCTOKENDEST_T
typedef struct yywmctokendest {
	yywint_t yymtoken;				/* token */
	short yymaction;				/* the user action */
} yywmctokendest_t;
#endif

/* debugging */
#ifdef YYDEBUG
#ifndef YYWMSYMBOL_T
#define YYWMSYMBOL_T
typedef struct yywmsymbol {
	YYCONST wchar_t *yymname;		/* symbol name */
	yywint_t yymtoken;				/* symbol token */
} yywmsymbol_t;
#endif
#endif

typedef struct yywmparser {
	/* flags */
	YYBOOL yymlookahead;				/* whether current lookahead token is valid */
	YYBOOL yymstackgrow;				/* whether stack can grow */
	YYBOOL yymexitflg;					/* whether yymexit called */
	YYBOOL yymretireflg;				/* whether yymretire called */
	YYBOOL yymerrorflg;					/* whether yymthrowerror called */
	YYBOOL yympopflg;					/* popping symbols during error recovery */
	YYBOOL yymwipeflg;					/* whether to "wipe" stack on abort */

	int yymtop;							/* the current top of the stack */
	yywint_t yymchar;					/* current lookahead token */
	int yymskip;						/* error recovery token shift counter */
	int yymerrorcount;					/* how many syntax errors have occurred */
	int yymexitcode;					/* yymexit exit code */
	int yymretirecode;					/* yymretire exit code */
	int yymerrorpop;					/* how many error transitions to pop */
	YYCSTD FILE YYFAR *yymerr;			/* error output file */

	/* stack */
	yywstack_t YYFAR *yymstackptr;		/* (state) stack */
	yywstack_t YYFAR *yymsstackptr;		/* static (state) stack */
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
	yywint_t (YYCDECL *yymgettoken)(struct yywmparser YYFAR *yy);
	void (YYCDECL *yymdiscard)(struct yywmparser YYFAR *yy, yywint_t token);
	void (YYCDECL *yymsyntaxerror)(struct yywmparser YYFAR *yy);
	void (YYCDECL *yymstackoverflow)(struct yywmparser YYFAR *yy);
	void (YYCDECL *yymerror)(struct yywmparser YYFAR *yy, YYCONST wchar_t YYFAR *text);
	void (YYCDECL *yymaction)(struct yywmparser YYFAR *yy, int action);
#else
	yywint_t (YYCDECL *yymgettoken)();
	void (YYCDECL *yymdiscard)();
	void (YYCDECL *yymsyntaxerror)();
	void (YYCDECL *yymstackoverflow)();
	void (YYCDECL *yymerror)();
	void (YYCDECL *yymaction)();
#endif

	/* tables */
	/* fast parser */
	YYCONST yywmstateaction_t YYNEARFAR *yymstateaction;
	YYCONST yywmtokenaction_t YYNEARFAR *yymtokenaction;
	long yymtokenaction_size;
	YYCONST yywmstategoto_t YYNEARFAR *yymstategoto;
	YYCONST yywmnontermgoto_t YYNEARFAR *yymnontermgoto;
	int yymnontermgoto_size;
	YYCONST yywmtokendest_t YYNEARFAR *yymtokendestptr;
	long yymtokendest_size;
	YYCONST yywtokendestbase_t YYNEARFAR *yymtokendestbaseptr;
	int yymtokendestbase_size;
	/* compact parser */
	YYCONST yywcstateaction_t YYNEARFAR *yymcstateaction;
	YYCONST yywmctokenaction_t YYNEARFAR *yymctokenaction;
	YYCONST yywcstategoto_t YYNEARFAR *yymcstategoto;
	YYCONST yywmcnontermgoto_t YYNEARFAR *yymcnontermgoto;
	YYCONST yywmctokendest_t YYNEARFAR *yymctokendestptr;
	/* common */
	YYCONST yywmreduction_t YYNEARFAR *yymreduction;

	YYCONST yywdestructor_t YYNEARFAR *yymdestructorptr;

	struct yywmlexer YYFAR *yymlexerptr;	/* lexical analyser */
	void YYFAR *yymdata;					/* user data */

	/* debugging */
#ifdef YYDEBUG
	YYBOOL yymdebug;
	YYBOOL yymdebugstack;
	YYBOOL yymdebugflush;
	YYCSTD FILE YYFAR *yymdebugout;
	YYCONST yywmsymbol_t YYNEARFAR *yymsymbol;
	YYCONST wchar_t *YYCONST YYNEARFAR *yymrule;
#endif
} yywmparser_t;

/* instance functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yywmcreateparser(yywmparser_t YYFAR *yy, YYCONST yywmparser_t YYFAR *src);
YYEXPFUNC(void) YYCDECL yywmdestroyparser(yywmparser_t YYFAR *yy);
#else
YYEXPFUNC(YYBOOL) YYCDECL yywmcreateparser();
YYEXPFUNC(void) YYCDECL yywmdestroyparser();
#endif

/* general functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yywmcparse(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmcwipe(yywmparser_t YYFAR *yy);
YYEXPFUNC(int) YYCDECL yywmcwork(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmdestructpop(yywmparser_t YYFAR *yy, int num);
YYEXPFUNC(int) YYCDECL yywmparse(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmcleanupparser(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywminitparser(yywmparser_t YYFAR *yy);
YYEXPFUNC(YYBOOL) YYCDECL yywmsetstacksize(yywmparser_t YYFAR *yy, int size);
YYEXPFUNC(int) YYCDECL yywmsetup(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmwipe(yywmparser_t YYFAR *yy);
YYEXPFUNC(int) YYCDECL yywmwork(yywmparser_t YYFAR *yy);
#else
YYEXPFUNC(int) YYCDECL yywmcparse();
YYEXPFUNC(void) YYCDECL yywmcwipe();
YYEXPFUNC(int) YYCDECL yywmcwork();
YYEXPFUNC(void) YYCDECL yywmdestructpop();
YYEXPFUNC(int) YYCDECL yywmparse();
YYEXPFUNC(void) YYCDECL yywmcleanupparser();
YYEXPFUNC(void) YYCDECL yywminitparser();
YYEXPFUNC(YYBOOL) YYCDECL yywmsetstacksize();
YYEXPFUNC(int) YYCDECL yywmsetup();
YYEXPFUNC(void) YYCDECL yywmwipe();
YYEXPFUNC(int) YYCDECL yywmwork();
#endif

/* service functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(yywint_t) YYCDECL yywmgettoken(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmdiscard(yywmparser_t YYFAR *yy, yywint_t token);
YYEXPFUNC(void) YYCDECL yywmsyntaxerror(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmstackoverflow(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmparsererror(yywmparser_t YYFAR *yy, YYCONST wchar_t YYFAR *text);
#else
YYEXPFUNC(yywint_t) YYCDECL yywmgettoken();
YYEXPFUNC(void) YYCDECL yywmdiscard();
YYEXPFUNC(void) YYCDECL yywmsyntaxerror();
YYEXPFUNC(void) YYCDECL yywmstackoverflow();
YYEXPFUNC(void) YYCDECL yywmparsererror();
#endif

/* action functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmcdestructclearin(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmdestructclearin(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmsetin(yywmparser_t YYFAR *yy, yywint_t token);
YYEXPFUNC(YYBOOL) YYCDECL yywmunclearin(yywmparser_t YYFAR *yy);
#else
YYEXPFUNC(void) YYCDECL yywmcdestructclearin();
YYEXPFUNC(void) YYCDECL yywmdestructclearin();
YYEXPFUNC(void) YYCDECL yywmsetin();
YYEXPFUNC(YYBOOL) YYCDECL yywmunclearin();
#endif
#define yywmabort(yy) yywmexit((yy), 1)
#define yywmaccept(yy) yywmexit((yy), 0)
#define yywmclearin(yy) ((yy)->yymlookahead = YYFALSE)
#define yywmerrok(yy) yywmsetskip((yy), 0)
#define yywmexit(yy, exitcode) ((yy)->yymexitflg = YYTRUE, (yy)->yymexitcode = (exitcode))
#define yywmforceerror(yy) yywmthrowerror((yy), 0)
#define yywmpopping(yy) (yy)->yympopflg
#define yywmrecovering(yy) ((yy)->yymskip > 0)
#define yywmretire(yy, retirecode) ((yy)->yymretireflg = YYTRUE, (yy)->yymretirecode = (retirecode))
#define yywmthrowerror(yy, pop) ((yy)->yymerrorflg = YYTRUE, (yy)->yymerrorpop = (pop))

/* helper functions */
#ifdef YYPROTOTYPE
#ifdef YYDEBUG
YYEXPFUNC(void) YYCDECL yywmpop(yywmparser_t YYFAR *yy, int num);
YYEXPFUNC(void) YYCDECL yywmsetskip(yywmparser_t YYFAR *yy, int skip);
#endif
YYEXPFUNC(YYBOOL) YYCDECL yywmpush(yywmparser_t YYFAR *yy, yywstack_t state);
#else
#ifdef YYDEBUG
YYEXPFUNC(void) YYCDECL yywmpop();
YYEXPFUNC(void) YYCDECL yywmsetskip();
#endif
YYEXPFUNC(YYBOOL) YYCDECL yywmpush();
#endif
#define yywmpeek(yy) ((yy)->yymstackptr[(yy)->yymtop])
#ifndef YYDEBUG
#define yywmpop(yy, num) ((yy)->yymtop -= (num))
#define yywmsetskip(yy, skip) ((yy)->yymskip = (skip))
#endif

/* debugging functions */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
YYEXPFUNC(YYCONST wchar_t *) YYCDECL yywmtokenstring(yywmparser_t YYFAR *yy, yywint_t token);
YYEXPFUNC(void) YYCDECL yywmdgettoken(yywmparser_t YYFAR *yy, yywint_t token);
YYEXPFUNC(void) YYCDECL yywmdshift(yywmparser_t YYFAR *yy, yywint_t token);
YYEXPFUNC(void) YYCDECL yywmdreduce(yywmparser_t YYFAR *yy, int rule);
YYEXPFUNC(void) YYCDECL yywmdsyntaxerror(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmdaccept(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmdabort(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmddiscard(yywmparser_t YYFAR *yy, yywint_t token);
YYEXPFUNC(void) YYCDECL yywmdexit(yywmparser_t YYFAR *yy, int exitcode);
YYEXPFUNC(void) YYCDECL yywmdthrowerror(yywmparser_t YYFAR *yy, int errorpop);
YYEXPFUNC(void) YYCDECL yywmdretire(yywmparser_t YYFAR *yy, int retirecode);
YYEXPFUNC(void) YYCDECL yywmdattemptrecovery(yywmparser_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmparserdebugoutput(yywmparser_t YYFAR *yy, YYCONST wchar_t YYFAR *string);
#else
YYEXPFUNC(YYCONST wchar_t *) YYCDECL yywmtokenstring();
YYEXPFUNC(void) YYCDECL yywmdgettoken();
YYEXPFUNC(void) YYCDECL yywmdshift();
YYEXPFUNC(void) YYCDECL yywmdreduce();
YYEXPFUNC(void) YYCDECL yywmdsyntaxerror();
YYEXPFUNC(void) YYCDECL yywmdaccept();
YYEXPFUNC(void) YYCDECL yywmdabort();
YYEXPFUNC(void) YYCDECL yywmddiscard();
YYEXPFUNC(void) YYCDECL yywmdexit();
YYEXPFUNC(void) YYCDECL yywmdthrowerror();
YYEXPFUNC(void) YYCDECL yywmdretire();
YYEXPFUNC(void) YYCDECL yywmdattemptrecovery();
YYEXPFUNC(void) YYCDECL yywmparserdebugoutput();
#endif
#endif

#define yywmisfastparser(yy) ((yy)->yymstateaction != NULL)
#define yywmiscompactparser(yy) ((yy)->yymcstateaction != NULL)

/* compatibility */
#define yywmparse_t yywmparser_t
#define yywmcreateparse yywmcreateparser
#define yywmdestroyparse yywmdestroyparser
#define yywmparsecleanup yywmcleanupparser
#define yywmparseinit yywminitparser
#ifdef YYDEBUG
#define yywmparsedebugoutput yywmparserdebugoutput
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
