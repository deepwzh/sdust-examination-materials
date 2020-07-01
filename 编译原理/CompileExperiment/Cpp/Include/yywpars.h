#ifndef YYWPARS_H
#define YYWPARS_H

/************************************************************
yywpars.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#if !defined(YYBUILDDLL) && !defined(YYDLL)

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

#ifndef YYWCNONTERMGOTO_T
#define YYWCNONTERMGOTO_T
typedef struct yywcnontermgoto {
	short yynonterm;				/* nonterminal */
	short yynext;					/* next state */
} yywcnontermgoto_t;
#endif

#ifndef YYWSTATEGOTO_T
#define YYWSTATEGOTO_T
typedef struct yywstategoto {
	short yybase;					/* base */
	short yydef;					/* default state */
} yywstategoto_t;
#endif

#ifndef YYWNONTERMGOTO_T
#define YYWNONTERMGOTO_T
typedef struct yywnontermgoto {
	short yycheck;					/* check */
	short yynext;					/* next state */
} yywnontermgoto_t;
#endif

/* action types */
#define YYAT_SHIFT		0			/* shift action */
#define YYAT_REDUCE		1			/* reduce action */
#define YYAT_ERROR		2			/* error */
#define YYAT_ACCEPT		3			/* accept */
#define YYAT_DEFAULT	4			/* default state */

typedef short yywcstateaction_t;

#ifndef YYWCTOKENACTION_T
#define YYWCTOKENACTION_T
typedef struct yywctokenaction {
	yywint_t yytoken;				/* lookahead token */
	unsigned char yytype;			/* action to perform */
	short yysr;						/* state to shift/production to reduce */
} yywctokenaction_t;
#endif

#ifndef YYWSTATEACTION_T
#define YYWSTATEACTION_T
typedef struct yywstateaction {
	long yybase;					/* base */
	unsigned char yylookahead;		/* lookahead needed */
	unsigned char yytype;			/* action to perform */
	short yysr;						/* shift/reduce */
} yywstateaction_t;
#endif

#ifndef YYWTOKENACTION_T
#define YYWTOKENACTION_T
typedef struct yywtokenaction {
	short yycheck;					/* check */
	unsigned char yytype;			/* action type */
	short yysr;						/* shift/reduce */
} yywtokenaction_t;
#endif

/* nonterminals */
#define YYNT_ALL		(-1)		/* match all nonterminals */

/* states */
#define YYST_ERROR		(-1)		/* goto error */

#ifndef YYWREDUCTION_T
#define YYWREDUCTION_T
typedef struct yywreduction {
	short yynonterm;				/* the rhs symbol */
	short yylength;					/* number of symbols on lhs */
	short yyaction;					/* the user action */
} yywreduction_t;
#endif

typedef short yywdestructor_t;

#ifndef YYWTOKENDEST_T
#define YYWTOKENDEST_T
typedef struct yywtokendest {
	short yycheck;					/* check */
	short yyaction;					/* action */
} yywtokendest_t;
#endif

typedef long yywtokendestbase_t;

#ifndef YYWCTOKENDEST_T
#define YYWCTOKENDEST_T
typedef struct yywctokendest {
	yywint_t yytoken;				/* token */
	short yyaction;					/* the user action */
} yywctokendest_t;
#endif

/* debugging */
#ifdef YYDEBUG
#ifndef YYWSYMBOL_T
#define YYWSYMBOL_T
typedef struct yywsymbol {
	YYCONST wchar_t *yyname;		/* symbol name */
	yywint_t yytoken;				/* symbol token */
} yywsymbol_t;
#endif
#endif

/* general functions */
#ifdef YYPROTOTYPE
int YYCDECL yywcparse(void);
void YYCDECL yywcwipe(void);
int YYCDECL yywcwork(void);
void YYCDECL yywdestructpop(int num);
int YYCDECL yywparse(void);
void YYCDECL yywcleanupparser(void);
void YYCDECL yywinitparser(void);
YYBOOL YYCDECL yywsetstacksize(int size);
int YYCDECL yywsetup(void);
void YYCDECL yywwipe(void);
int YYCDECL yywwork(void);
#else
int YYCDECL yywcparse();
void YYCDECL yywcwipe();
int YYCDECL yywcwork();
void YYCDECL yywdestructpop();
int YYCDECL yywparse();
void YYCDECL yywcleanupparser();
void YYCDECL yywinitparser();
YYBOOL YYCDECL yywsetstacksize();
int YYCDECL yywsetup();
void YYCDECL yywwipe();
int YYCDECL yywwork();
#endif

/* service functions */
#ifdef YYPROTOTYPE
yywint_t YYCDECL yywgettoken(void);
void YYCDECL yywdiscard(yywint_t token);
void YYCDECL yywsyntaxerror(void);
void YYCDECL yywstackoverflow(void);
void YYCDECL yywparsererror(YYCONST wchar_t YYFAR *text);
#else
yywint_t YYCDECL yywgettoken();
void YYCDECL yywdiscard();
void YYCDECL yywsyntaxerror();
void YYCDECL yywstackoverflow();
void YYCDECL yywparsererror();
#endif

/* action functions */
#ifdef YYPROTOTYPE
void YYCDECL yywcdestructclearin(void);
void YYCDECL yywdestructclearin(void);
void YYCDECL yywsetin(yywint_t token);
YYBOOL YYCDECL yywunclearin(void);
#else
void YYCDECL yywcdestructclearin();
void YYCDECL yywdestructclearin();
void YYCDECL yywsetin();
YYBOOL YYCDECL yywunclearin();
#endif
#define yywabort() yywexit(1)
#define yywaccept() yywexit(0)
#define yywclearin() (yywlookahead = YYFALSE)
#define yywerrok() yywsetskip(0)
#define yywexit(exitcode) (yywexitflg = YYTRUE, yywexitcode = (exitcode))
#define yywforceerror() yywthrowerror(0)
#define yywpopping() yywpopflg
#define yywrecovering() (yywskip > 0)
#define yywretire(retirecode) (yywretireflg = YYTRUE, yywretirecode = (retirecode))
#define yywthrowerror(pop) (yywerrorflg = YYTRUE, yywerrorpop = (pop))

/* helper functions */
#ifdef YYPROTOTYPE
#ifdef YYDEBUG
void YYCDECL yywpop(int num);
void YYCDECL yywsetskip(int skip);
#endif
YYBOOL YYCDECL yywpush(yywstack_t state);
#else
#ifdef YYDEBUG
void YYCDECL yywpop();
void YYCDECL yywsetskip();
#endif
YYBOOL YYCDECL yywpush();
#endif
#define yywpeek() (yywstackptr[yywtop])
#ifndef YYDEBUG
#define yywpop(num) (yywtop -= (num))
#define yywsetskip(skip) (yywskip = (skip))
#endif

/* variables */
extern YYBOOL YYNEAR YYDCDECL yywlookahead;
extern YYBOOL YYNEAR YYDCDECL yywstackgrow;
extern YYBOOL YYNEAR YYDCDECL yywexitflg;
extern YYBOOL YYNEAR YYDCDECL yywretireflg;
extern YYBOOL YYNEAR YYDCDECL yywerrorflg;
extern YYBOOL YYNEAR YYDCDECL yywpopflg;
extern YYBOOL YYNEAR YYDCDECL yywwipeflg;
extern int YYNEAR YYDCDECL yywtop;				/* the current top of the stack */
extern yywint_t YYNEAR YYDCDECL yywchar;
extern int YYNEAR YYDCDECL yywskip;
extern int YYNEAR YYDCDECL yywerrorcount;
extern YYCSTD FILE YYFAR *YYNEAR YYDCDECL yywparsererr;
extern int YYNEAR YYDCDECL yywexitcode;
extern int YYNEAR YYDCDECL yywretirecode;
extern int YYNEAR YYDCDECL yywerrorpop;

/* debugging functions */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
YYCONST wchar_t *YYCDECL yywtokenstring(yywint_t token);
void YYCDECL yywdgettoken(yywint_t token);
void YYCDECL yywdshift(yywint_t token);
void YYCDECL yywdreduce(int rule);
void YYCDECL yywdsyntaxerror(void);
void YYCDECL yywdaccept(void);
void YYCDECL yywdabort(void);
void YYCDECL yywddiscard(yywint_t token);
void YYCDECL yywdexit(int exitcode);
void YYCDECL yywdthrowerror(int errorpop);
void YYCDECL yywdretire(int retirecode);
void YYCDECL yywdattemptrecovery(void);
void YYCDECL yywparserdebugoutput(YYCONST wchar_t YYFAR *string);
#else
YYCONST wchar_t *YYCDECL yywtokenstring();
void YYCDECL yywdgettoken();
void YYCDECL yywdshift();
void YYCDECL yywdreduce();
void YYCDECL yywdsyntaxerror();
void YYCDECL yywdaccept();
void YYCDECL yywdabort();
void YYCDECL yywddiscard();
void YYCDECL yywdexit();
void YYCDECL yywdthrowerror();
void YYCDECL yywdretire();
void YYCDECL yywdattemptrecovery();
void YYCDECL yywparserdebugoutput();
#endif
#endif

/* debugging variables */
#ifdef YYDEBUG
extern YYBOOL YYNEAR YYDCDECL yywparserdebug;
extern YYBOOL YYNEAR YYDCDECL yywparserdebugstack;
extern YYBOOL YYNEAR YYDCDECL yywparserdebugflush;
extern YYCSTD FILE YYFAR *YYNEAR YYDCDECL yywparserdebugout;
extern YYCONST yywsymbol_t YYNEARFAR YYDCDECL yywsymbol[];
extern YYCONST wchar_t *YYCONST YYNEARFAR YYDCDECL yywrule[];
#endif

/* externally defined */
#ifdef YYPROTOTYPE
yywint_t YYCDECL yywlex(void);
void YYCDECL yywparseraction(int action);
#else
yywint_t YYCDECL yywlex();
void YYCDECL yywparseraction();
#endif

extern yywstack_t YYFAR *YYNEAR YYDCDECL yywstackptr;		/* (state) stack */
extern yywstack_t YYFAR *YYNEAR YYDCDECL yywsstackptr;		/* static (state) stack */
extern int YYNEAR YYDCDECL yywstack_size;					/* number of elements in stack */
extern int YYNEAR YYDCDECL yywsstack_size;					/* initial number of elements in stack */
extern int YYNEAR YYDCDECL yywstack_max;					/* maximum size of the stack */

extern size_t YYNEAR YYDCDECL yywattribute_size;			/* size of attribute */

#ifdef YYPROTOTYPE
extern void YYFAR *YYNEAR YYDCDECL yywvalptr;				/* attribute for $$ */
extern void YYFAR *YYNEAR YYDCDECL yywlvalptr;				/* current token attribute */
extern void YYFAR *YYNEAR YYDCDECL yywattributestackptr;	/* attribute stack */
extern void YYFAR *YYNEAR YYDCDECL yywsattributestackptr;	/* static attribute stack */
#else
extern char YYFAR *YYNEAR YYDCDECL yywvalptr;				/* attribute for $$ */
extern char YYFAR *YYNEAR YYDCDECL yywlvalptr;				/* current token attribute */
extern char YYFAR *YYNEAR YYDCDECL yywattributestackptr;	/* attribute stack */
extern char YYFAR *YYNEAR YYDCDECL yywsattributestackptr;	/* static attribute stack */
#endif

/* compact parser */
extern YYCONST yywcstateaction_t YYNEARFAR YYDCDECL yywcstateaction[];
extern YYCONST yywctokenaction_t YYNEARFAR YYDCDECL yywctokenaction[];
extern YYCONST yywcstategoto_t YYNEARFAR YYDCDECL yywcstategoto[];
extern YYCONST yywcnontermgoto_t YYNEARFAR YYDCDECL yywcnontermgoto[];
extern YYCONST yywctokendest_t YYNEARFAR *YYNEAR YYDCDECL yywctokendestptr;

/* fast parser */
extern YYCONST yywstateaction_t YYNEARFAR YYDCDECL yywstateaction[];
extern YYCONST yywtokenaction_t YYNEARFAR YYDCDECL yywtokenaction[];
extern int YYNEAR YYDCDECL yywtokenaction_size;
extern YYCONST yywstategoto_t YYNEARFAR YYDCDECL yywstategoto[];
extern YYCONST yywnontermgoto_t YYNEARFAR YYDCDECL yywnontermgoto[];
extern int YYNEAR YYDCDECL yywnontermgoto_size;
extern YYCONST yywtokendest_t YYNEARFAR *YYNEAR YYDCDECL yywtokendestptr;
extern int YYNEAR YYDCDECL yywtokendest_size;
extern YYCONST yywtokendestbase_t YYNEARFAR *YYNEAR YYDCDECL yywtokendestbaseptr;
extern int YYNEAR YYDCDECL yywtokendestbase_size;

extern YYCONST yywreduction_t YYNEARFAR YYDCDECL yywreduction[];

extern YYCONST yywdestructor_t YYNEARFAR *YYNEAR YYDCDECL yywdestructorptr;

/* compatibility */
#define yywparsecleanup yywcleanupparser
#define yywparseinit yywinitparser
#define yywparseerr yywparsererr
#ifdef YYDEBUG
#define yywparsedebugoutput yywparserdebugoutput
#define yywparsedebug yywparserdebug
#define yywparsedebugstack yywparserdebugstack
#define yywparsedebugflush yywparserdebugflush
#define yywparsedebugout yywparserdebugout
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

#endif
