#ifndef YYPARS_H
#define YYPARS_H

/************************************************************
yypars.h
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

typedef short yystack_t;

/* yyparse return values */
#define YYEXIT_SUCCESS	0
#define YYEXIT_FAILURE	1

/* common tokens */
#define YYTK_ALL		(-1)		/* match all tokens */
#define YYTK_END		0			/* $end token */
#define YYTK_ERROR		256			/* error token */

typedef short yycstategoto_t;

#ifndef YYCNONTERMGOTO_T
#define YYCNONTERMGOTO_T
typedef struct yycnontermgoto {
	short yynonterm;				/* nonterminal */
	short yynext;					/* next state */
} yycnontermgoto_t;
#endif

#ifndef YYSTATEGOTO_T
#define YYSTATEGOTO_T
typedef struct yystategoto {
	short yybase;					/* base */
	short yydef;					/* default state */
} yystategoto_t;
#endif

#ifndef YYNONTERMGOTO_T
#define YYNONTERMGOTO_T
typedef struct yynontermgoto {
	short yycheck;					/* check */
	short yynext;					/* next state */
} yynontermgoto_t;
#endif

/* action types */
#define YYAT_SHIFT		0			/* shift action */
#define YYAT_REDUCE		1			/* reduce action */
#define YYAT_ERROR		2			/* error */
#define YYAT_ACCEPT		3			/* accept */
#define YYAT_DEFAULT	4			/* default state */

typedef short yycstateaction_t;

#ifndef YYCTOKENACTION_T
#define YYCTOKENACTION_T
typedef struct yyctokenaction {
	int yytoken;					/* lookahead token */
	unsigned char yytype;			/* action to perform */
	short yysr;						/* state to shift/production to reduce */
} yyctokenaction_t;
#endif

#ifndef YYSTATEACTION_T
#define YYSTATEACTION_T
typedef struct yystateaction {
	short yybase;					/* base */
	unsigned char yylookahead;		/* lookahead needed */
	unsigned char yytype;			/* action to perform */
	short yysr;						/* shift/reduce */
} yystateaction_t;
#endif

#ifndef YYTOKENACTION_T
#define YYTOKENACTION_T
typedef struct yytokenaction {
	short yycheck;					/* check */
	unsigned char yytype;			/* action type */
	short yysr;						/* shift/reduce */
} yytokenaction_t;
#endif

/* nonterminals */
#define YYNT_ALL		(-1)		/* match all nonterminals */

/* states */
#define YYST_ERROR		(-1)		/* goto error */

#ifndef YYREDUCTION_T
#define YYREDUCTION_T
typedef struct yyreduction {
	short yynonterm;				/* the rhs symbol */
	short yylength;					/* number of symbols on lhs */
	short yyaction;					/* the user action */
} yyreduction_t;
#endif

typedef short yydestructor_t;

#ifndef YYTOKENDEST_T
#define YYTOKENDEST_T
typedef struct yytokendest {
	short yycheck;					/* check */
	short yyaction;					/* action */
} yytokendest_t;
#endif

typedef short yytokendestbase_t;

#ifndef YYCTOKENDEST_T
#define YYCTOKENDEST_T
typedef struct yyctokendest {
	int yytoken;					/* token */
	short yyaction;					/* the user action */
} yyctokendest_t;
#endif

/* debugging */
#ifdef YYDEBUG
#ifndef YYSYMBOL_T
#define YYSYMBOL_T
typedef struct yysymbol {
	YYCONST char *yyname;			/* symbol name */
	int yytoken;					/* symbol token */
} yysymbol_t;
#endif
#endif

/* general functions */
#ifdef YYPROTOTYPE
int YYCDECL yycparse(void);
void YYCDECL yycwipe(void);
int YYCDECL yycwork(void);
void YYCDECL yydestructpop(int num);
int YYCDECL yyparse(void);
void YYCDECL yycleanupparser(void);
void YYCDECL yyinitparser(void);
YYBOOL YYCDECL yysetstacksize(int size);
int YYCDECL yysetup(void);
void YYCDECL yywipe(void);
int YYCDECL yywork(void);
#else
int YYCDECL yycparse();
void YYCDECL yycwipe();
int YYCDECL yycwork();
void YYCDECL yydestructpop();
int YYCDECL yyparse();
void YYCDECL yycleanupparser();
void YYCDECL yyinitparser();
YYBOOL YYCDECL yysetstacksize();
int YYCDECL yysetup();
void YYCDECL yywipe();
int YYCDECL yywork();
#endif

/* service functions */
#ifdef YYPROTOTYPE
int YYCDECL yygettoken(void);
void YYCDECL yydiscard(int token);
void YYCDECL yysyntaxerror(void);
void YYCDECL yystackoverflow(void);
void YYCDECL yyparsererror(YYCONST char YYFAR *text);
#else
int YYCDECL yygettoken();
void YYCDECL yydiscard();
void YYCDECL yysyntaxerror();
void YYCDECL yystackoverflow();
void YYCDECL yyparsererror();
#endif

/* action functions */
#ifdef YYPROTOTYPE
void YYCDECL yycdestructclearin(void);
void YYCDECL yydestructclearin(void);
void YYCDECL yysetin(int token);
YYBOOL YYCDECL yyunclearin(void);
#else
void YYCDECL yycdestructclearin();
void YYCDECL yydestructclearin();
void YYCDECL yysetin();
YYBOOL YYCDECL yyunclearin();
#endif
#define yyabort() yyexit(1)
#define yyaccept() yyexit(0)
#define yyclearin() (yylookahead = YYFALSE)
#define yyerrok() yysetskip(0)
#define yyexit(exitcode) (yyexitflg = YYTRUE, yyexitcode = (exitcode))
#define yyforceerror() yythrowerror(0)
#define yypopping() yypopflg
#define yyrecovering() (yyskip > 0)
#define yyretire(retirecode) (yyretireflg = YYTRUE, yyretirecode = (retirecode))
#define yythrowerror(pop) (yyerrorflg = YYTRUE, yyerrorpop = (pop))

/* compatibility */
#ifdef YY_COMPATIBLE
#undef yyclearin
#define yyclearin (yylookahead = YYFALSE)
#undef yyerrok
#define yyerrok yysetskip(0)
#endif
#define YYABORT yyexit(1)
#define YYACCEPT yyexit(0)
#define YYERROR yythrowerror(0)
#define YYRECOVERING yyrecovering()
#ifndef YYNDEBUG
#define yydebug yyparserdebug
#endif
#ifndef YYNERROR
#define yyerror yyparsererror
#endif

/* helper functions */
#ifdef YYPROTOTYPE
#ifdef YYDEBUG
void YYCDECL yypop(int num);
void YYCDECL yysetskip(int skip);
#endif
YYBOOL YYCDECL yypush(yystack_t state);
#else
#ifdef YYDEBUG
void YYCDECL yypop();
void YYCDECL yysetskip();
#endif
YYBOOL YYCDECL yypush();
#endif
#define yypeek() (yystackptr[yytop])
#ifndef YYDEBUG
#define yypop(num) (yytop -= (num))
#define yysetskip(skip) (yyskip = (skip))
#endif

/* variables */
extern YYBOOL YYNEAR YYDCDECL yylookahead;
extern YYBOOL YYNEAR YYDCDECL yystackgrow;
extern YYBOOL YYNEAR YYDCDECL yyexitflg;
extern YYBOOL YYNEAR YYDCDECL yyretireflg;
extern YYBOOL YYNEAR YYDCDECL yyerrorflg;
extern YYBOOL YYNEAR YYDCDECL yypopflg;
extern YYBOOL YYNEAR YYDCDECL yywipeflg;
extern int YYNEAR YYDCDECL yytop;				/* the current top of the stack */
extern int YYNEAR YYDCDECL yychar;
extern int YYNEAR YYDCDECL yyskip;
extern int YYNEAR YYDCDECL yyerrorcount;
extern YYCSTD FILE YYFAR *YYNEAR YYDCDECL yyparsererr;
extern int YYNEAR YYDCDECL yyexitcode;
extern int YYNEAR YYDCDECL yyretirecode;
extern int YYNEAR YYDCDECL yyerrorpop;

/* debugging functions */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
YYCONST char *YYCDECL yytokenstring(int token);
void YYCDECL yydgettoken(int token);
void YYCDECL yydshift(int token);
void YYCDECL yydreduce(int rule);
void YYCDECL yydsyntaxerror(void);
void YYCDECL yydaccept(void);
void YYCDECL yydabort(void);
void YYCDECL yyddiscard(int token);
void YYCDECL yydexit(int exitcode);
void YYCDECL yydthrowerror(int errorpop);
void YYCDECL yydretire(int retirecode);
void YYCDECL yydattemptrecovery(void);
void YYCDECL yyparserdebugoutput(YYCONST char YYFAR *string);
#else
YYCONST char *YYCDECL yytokenstring();
void YYCDECL yydgettoken();
void YYCDECL yydshift();
void YYCDECL yydreduce();
void YYCDECL yydsyntaxerror();
void YYCDECL yydaccept();
void YYCDECL yydabort();
void YYCDECL yyddiscard();
void YYCDECL yydexit();
void YYCDECL yydthrowerror();
void YYCDECL yydretire();
void YYCDECL yydattemptrecovery();
void YYCDECL yyparserdebugoutput();
#endif
#endif

/* debugging variables */
#ifdef YYDEBUG
extern YYBOOL YYNEAR YYDCDECL yyparserdebug;
extern YYBOOL YYNEAR YYDCDECL yyparserdebugstack;
extern YYBOOL YYNEAR YYDCDECL yyparserdebugflush;
extern YYCSTD FILE YYFAR *YYNEAR YYDCDECL yyparserdebugout;
extern YYCONST yysymbol_t YYNEARFAR YYDCDECL yysymbol[];
extern YYCONST char *YYCONST YYNEARFAR YYDCDECL yyrule[];
#endif

/* externally defined */
#ifdef YYPROTOTYPE
int YYCDECL yylex(void);
void YYCDECL yyparseraction(int action);
#else
int YYCDECL yylex();
void YYCDECL yyparseraction();
#endif

extern yystack_t YYFAR *YYNEAR YYDCDECL yystackptr;			/* (state) stack */
extern yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr;		/* static (state) stack */
extern int YYNEAR YYDCDECL yystack_size;					/* number of elements in stack */
extern int YYNEAR YYDCDECL yysstack_size;					/* initial number of elements in stack */
extern int YYNEAR YYDCDECL yystack_max;						/* maximum size of stack */

extern size_t YYNEAR YYDCDECL yyattribute_size;				/* size of attribute */

#ifdef YYPROTOTYPE
extern void YYFAR *YYNEAR YYDCDECL yyvalptr;				/* attribute for $$ */
extern void YYFAR *YYNEAR YYDCDECL yylvalptr;				/* current token attribute */
extern void YYFAR *YYNEAR YYDCDECL yyattributestackptr;		/* attribute stack */
extern void YYFAR *YYNEAR YYDCDECL yysattributestackptr;	/* static attribute stack */
#else
extern char YYFAR *YYNEAR YYDCDECL yyvalptr;				/* attribute for $$ */
extern char YYFAR *YYNEAR YYDCDECL yylvalptr;				/* current token attribute */
extern char YYFAR *YYNEAR YYDCDECL yyattributestackptr;		/* attribute stack */
extern char YYFAR *YYNEAR YYDCDECL yysattributestackptr;	/* static attribute stack */
#endif

/* compact parser */
extern YYCONST yycstateaction_t YYNEARFAR YYDCDECL yycstateaction[];
extern YYCONST yyctokenaction_t YYNEARFAR YYDCDECL yyctokenaction[];
extern YYCONST yycstategoto_t YYNEARFAR YYDCDECL yycstategoto[];
extern YYCONST yycnontermgoto_t YYNEARFAR YYDCDECL yycnontermgoto[];
extern YYCONST yyctokendest_t YYNEARFAR *YYNEAR YYDCDECL yyctokendestptr;

/* fast parser */
extern YYCONST yystateaction_t YYNEARFAR YYDCDECL yystateaction[];
extern YYCONST yytokenaction_t YYNEARFAR YYDCDECL yytokenaction[];
extern int YYNEAR YYDCDECL yytokenaction_size;
extern YYCONST yystategoto_t YYNEARFAR YYDCDECL yystategoto[];
extern YYCONST yynontermgoto_t YYNEARFAR YYDCDECL yynontermgoto[];
extern int YYNEAR YYDCDECL yynontermgoto_size;
extern YYCONST yytokendest_t YYNEARFAR *YYNEAR YYDCDECL yytokendestptr;
extern int YYNEAR YYDCDECL yytokendest_size;
extern YYCONST yytokendestbase_t YYNEARFAR *YYNEAR YYDCDECL yytokendestbaseptr;
extern int YYNEAR YYDCDECL yytokendestbase_size;

extern YYCONST yyreduction_t YYNEARFAR YYDCDECL yyreduction[];

extern YYCONST yydestructor_t YYNEARFAR *YYNEAR YYDCDECL yydestructorptr;

#ifdef __cplusplus
}
#endif

/* compatibility */
#define yyparsecleanup yycleanupparser
#define yyparseinit yyinitparser
#define yyparseerr yyparsererr
#ifdef YYDEBUG
#define yyparsedebugoutput yyparserdebugoutput
#define yyparsedebug yyparserdebug
#define yyparsedebugstack yyparserdebugstack
#define yyparsedebugflush yyparserdebugflush
#define yyparsedebugout yyparserdebugout
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
