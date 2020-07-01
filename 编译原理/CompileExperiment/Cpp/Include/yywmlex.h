#ifndef YYWMLEX_H
#define YYWMLEX_H

/************************************************************
yywmlex.h
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
#else
#include <stdio.h>
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

#define YY_ALEX

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

/* yylex return values */
#define YYEOF 0			/* end of file */

#ifndef YYWMSTATE_T
#define YYWMSTATE_T
typedef struct yywmstate {
	short yymdef;		/* default state */
	long yymbase;		/* base */
	short yymmatch;		/* action associated with state */
} yywmstate_t;
#endif

#ifndef YYWMTRANSITION_T
#define YYWMTRANSITION_T
typedef struct yywmtransition {
	short yymnext;		/* next state on transition */
	short yymcheck;		/* check */
} yywmtransition_t;
#endif

#ifndef YYWMCTRANSITION_T
#define YYWMCTRANSITION_T
typedef struct yywmctransition {
	wchar_t yymfirst;		/* first character in range */
	wchar_t yymlast;		/* last character in range */
	short yymnext;			/* next state on transition */
} yywmctransition_t;
#endif

#ifndef YYWINT_T
#define YYWINT_T
#ifdef YYWIN32
typedef int yywint_t;
#else
typedef long yywint_t;
#endif
#endif

typedef short yywmatch_t;
typedef unsigned char yywbackup_t;

typedef struct yywmlexer {
	/* flags */
	YYBOOL yymmoreflg;					/* concatenate matched strings */
	YYBOOL yymrejectflg;				/* yyreject called from an action */
	YYBOOL yymreturnflg;				/* return from an action */
	YYBOOL yymtextgrow;					/* whether text buffer is allowed to grow */
	YYBOOL yymunputgrow;				/* whether unput buffer is allowed to grow */
	YYBOOL yymeol;						/* whether an end-of-line '\n' has been seen */
	YYBOOL yymoldeol;					/* previous end-of-line value */
	int yymstart;						/* current start state */

	/* streams */
	YYCSTD FILE YYFAR *yymin;			/* input text stream */
	YYCSTD FILE YYFAR *yymout;			/* output text stream */
	YYCSTD FILE YYFAR *yymerr;			/* error stream */

	int yymleng;						/* matched string length */
	int yymlineno;						/* current line number */
	int yymunputindex;					/* unput buffer position */

	wchar_t YYFAR *yymtext;				/* text buffer */
	wchar_t YYFAR *yymstext;			/* initial (static) text buffer */
	int yymtext_size;					/* text buffer size */
	int yymstext_size;					/* initial (static) text buffer size */
	int yymtext_max;					/* maximum text buffer size */

	int YYFAR *yymstatebuf;				/* state buffer */
	int YYFAR *yymsstatebuf;			/* initial (static) state buffer */

	/* unput buffer */
	yywint_t YYFAR *yymunputbufptr;		/* unput buffer */
	yywint_t YYFAR *yymsunputbufptr;	/* initial (static) unput buffer */
	int yymunput_size;					/* unput buffer size */
	int yymsunput_size;					/* initial (static) unput buffer size */
	int yymunput_max;					/* maximum unput buffer size */

	/* functions */
#ifdef YYPROTOTYPE
	yywint_t (YYCDECL *yymgetchar)(struct yywmlexer YYFAR *yy);
	yywint_t (YYCDECL *yyminput)(struct yywmlexer YYFAR *yy);
	void (YYCDECL *yymoutput)(struct yywmlexer YYFAR *yy, yywint_t ch);
	void (YYCDECL *yymunput)(struct yywmlexer YYFAR *yy, yywint_t ch);
	int (YYCDECL *yymwrap)(struct yywmlexer YYFAR *yy);
	void (YYCDECL *yymtextoverflow)(struct yywmlexer YYFAR *yy);
	void (YYCDECL *yymunputoverflow)(struct yywmlexer YYFAR *yy);
	void (YYCDECL *yymerror)(struct yywmlexer YYFAR *yy, YYCONST wchar_t YYFAR *text);
	yywint_t (YYCDECL *yymaction)(struct yywmlexer YYFAR *yy, int action);
#else
	yywint_t (YYCDECL *yymgetchar)();
	yywint_t (YYCDECL *yyminput)();
	void (YYCDECL *yymoutput)();
	void (YYCDECL *yymunput)();
	int (YYCDECL *yymwrap)();
	void (YYCDECL *yymtextoverflow)();
	void (YYCDECL *yymunputoverflow)();
	void (YYCDECL *yymerror)();
	yywint_t (YYCDECL *yymaction)();
#endif

	/* tables */
	/* fast lexical analyser */
	YYCONST yywmtransition_t YYNEARFAR *yymtransition;
	long yymtransitionmax;
	/* compact lexical analyser */
	YYCONST yywmctransition_t YYNEARFAR *yymctransition;
	/* common */
	YYCONST yywmatch_t YYNEARFAR *yymmatch;
	YYCONST yywmstate_t YYNEARFAR *yymstate;
	YYCONST yywbackup_t YYNEARFAR *yymbackup;

	struct yywmparser YYFAR *yymparserptr;	/* parser */
	void YYFAR *yymdata;					/* user data */

	/* debugging */
#ifdef YYDEBUG
	YYBOOL yymdebug;
	YYBOOL yymdebugflush;
	YYCSTD FILE YYFAR *yymdebugout;
#endif
} yywmlexer_t;

/* instance functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yywmcreatelexer(yywmlexer_t YYFAR *yy, YYCONST yywmlexer_t YYFAR *src);
YYEXPFUNC(void) YYCDECL yywmdestroylexer(yywmlexer_t YYFAR *yy);
#else
YYEXPFUNC(YYBOOL) YYCDECL yywmcreatelexer();
YYEXPFUNC(void) YYCDECL yywmdestroylexer();
#endif

/* general functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(yywint_t) YYCDECL yywmclex(yywmlexer_t YYFAR *yy);
YYEXPFUNC(yywint_t) YYCDECL yywmlex(yywmlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmcleanuplexer(yywmlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywminitlexer(yywmlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmreset(yywmlexer_t YYFAR *yy);
YYEXPFUNC(YYBOOL) YYCDECL yywmsettextsize(yywmlexer_t YYFAR *yy, int size);
YYEXPFUNC(YYBOOL) YYCDECL yywmsetunputsize(yywmlexer_t YYFAR *yy, int size);
#else
YYEXPFUNC(yywint_t) YYCDECL yywmclex();
YYEXPFUNC(yywint_t) YYCDECL yywmlex();
YYEXPFUNC(void) YYCDECL yywmcleanuplexer();
YYEXPFUNC(void) YYCDECL yywminitlexer();
YYEXPFUNC(void) YYCDECL yywmreset();
YYEXPFUNC(YYBOOL) YYCDECL yywmsettextsize();
YYEXPFUNC(YYBOOL) YYCDECL yywmsetunputsize();
#endif

/* service functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(yywint_t) YYCDECL yywmgetchar(yywmlexer_t YYFAR *yy);
YYEXPFUNC(yywint_t) YYCDECL yywminput(yywmlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmoutput(yywmlexer_t YYFAR *yy, yywint_t ch);
YYEXPFUNC(void) YYCDECL yywmunput(yywmlexer_t YYFAR *yy, yywint_t ch);
YYEXPFUNC(int) YYCDECL yywmwrap(yywmlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmtextoverflow(yywmlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmunputoverflow(yywmlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmlexererror(yywmlexer_t YYFAR *yy, YYCONST wchar_t YYFAR *text);
#else
YYEXPFUNC(yywint_t) YYCDECL yywmgetchar();
YYEXPFUNC(yywint_t) YYCDECL yywminput();
YYEXPFUNC(void) YYCDECL yywmoutput();
YYEXPFUNC(void) YYCDECL yywmunput();
YYEXPFUNC(int) YYCDECL yywmwrap();
YYEXPFUNC(void) YYCDECL yywmtextoverflow();
YYEXPFUNC(void) YYCDECL yywmunputoverflow();
YYEXPFUNC(void) YYCDECL yywmlexererror();
#endif

/* action functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmecho(yywmlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yywmless(yywmlexer_t YYFAR *yy, int length);
#else
YYEXPFUNC(void) YYCDECL yywmecho();
YYEXPFUNC(void) YYCDECL yywmless();
#endif
#define yywmbegin(yy, state) ((yy)->yymstart = (state))
#define yywmmore(yy) ((yy)->yymmoreflg = YYTRUE)
#define yywmnewline(yy, newline) ((newline) ? (yy)->yymeol = YYTRUE : ((yy)->yymeol = YYFALSE))
#define yywmreject(yy) ((yy)->yymrejectflg = YYTRUE)
#define yywmunputcount(yy) (yy)->yymunputindex

/* helper functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yywmback(YYCONST yywmatch_t YYNEARFAR *p, int action);
#else
YYEXPFUNC(YYBOOL) YYCDECL yywmback();
#endif

/* debugging functions */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdebugoutput(yywmlexer_t YYFAR *yy, yywint_t ch);
YYEXPFUNC(void) YYCDECL yywmdmatch(yywmlexer_t YYFAR *yy, int expr);
YYEXPFUNC(void) YYCDECL yywmlexerdebugoutput(yywmlexer_t YYFAR *yy, YYCONST wchar_t YYFAR *string);
#else
YYEXPFUNC(void) YYCDECL yywmdebugoutput();
YYEXPFUNC(void) YYCDECL yywmdmatch();
YYEXPFUNC(void) YYCDECL yywmlexerdebugoutput();
#endif
#endif

#define yywmisfastlexer(yy) ((yy)->yymtransition != NULL)
#define yywmiscompactlexer(yy) ((yy)->yymctransition != NULL)

/* compatibility */
#define yywmlex_t yywmlexer_t
#define yywmcreatelex yywmcreatelexer
#define yywmdestroylex yywmdestroylexer
#define yywmlexcleanup yywmcleanuplexer
#define yywmlexinit yywminitlexer
#ifdef YYDEBUG
#define yywmlexdebugoutput yywmlexerdebugoutput
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
