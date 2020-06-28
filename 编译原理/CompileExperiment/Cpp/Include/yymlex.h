#ifndef YYMLEX_H
#define YYMLEX_H

/************************************************************
yymlex.h
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

#ifndef YYMSTATE_T
#define YYMSTATE_T
typedef struct yymstate {
	short yymdef;		/* default state */
	short yymbase;		/* base */
	short yymmatch;		/* action associated with state */
} yymstate_t;
#endif

#ifndef YYMTRANSITION_T
#define YYMTRANSITION_T
typedef struct yymtransition {
	short yymnext;		/* next state on transition */
	short yymcheck;		/* check */
} yymtransition_t;
#endif

#ifndef YYMCTRANSITION_T
#define YYMCTRANSITION_T
typedef struct yymctransition {
	unsigned char yymfirst;	/* first character in range */
	unsigned char yymlast;	/* last character in range */
	short yymnext;			/* next state on transition */
} yymctransition_t;
#endif

typedef short yymatch_t;
typedef unsigned char yybackup_t;

typedef struct yymlexer {
	/* flags */
	YYBOOL yymmoreflg;				/* concatenate matched strings */
	YYBOOL yymrejectflg;			/* yyreject called from an action */
	YYBOOL yymreturnflg;			/* return from an action */
	YYBOOL yymtextgrow;				/* whether text buffer is allowed to grow */
	YYBOOL yymunputgrow;			/* whether unput buffer is allowed to grow */
	YYBOOL yymeol;					/* whether an end-of-line '\n' has been seen */
	YYBOOL yymoldeol;				/* previous end-of-line value */
	int yymstart;					/* current start state */

	/* streams */
	YYCSTD FILE YYFAR *yymin;		/* input text stream */
	YYCSTD FILE YYFAR *yymout;		/* output text stream */
	YYCSTD FILE YYFAR *yymerr;		/* error stream */

	int yymleng;					/* matched string length */
	int yymlineno;					/* current line number */
	int yymunputindex;				/* unput buffer position */

	char YYFAR *yymtext;			/* text buffer */
	char YYFAR *yymstext;			/* initial (static) text buffer */
	int yymtext_size;				/* text buffer size */
	int yymstext_size;				/* initial (static) text buffer size */
	int yymtext_max;				/* maximum text buffer size */

	int YYFAR *yymstatebuf;			/* state buffer */
	int YYFAR *yymsstatebuf;		/* initial (static) state buffer */

	/* unput buffer */
	int YYFAR *yymunputbufptr;		/* unput buffer */
	int YYFAR *yymsunputbufptr;		/* initial (static) unput buffer */
	int yymunput_size;				/* unput buffer size */
	int yymsunput_size;				/* initial (static) unput buffer size */
	int yymunput_max;				/* maximum unput buffer size */

	/* functions */
#ifdef YYPROTOTYPE
	int (YYCDECL *yymgetchar)(struct yymlexer YYFAR *yy);
	int (YYCDECL *yyminput)(struct yymlexer YYFAR *yy);
	void (YYCDECL *yymoutput)(struct yymlexer YYFAR *yy, int ch);
	void (YYCDECL *yymunput)(struct yymlexer YYFAR *yy, int ch);
	int (YYCDECL *yymwrap)(struct yymlexer YYFAR *yy);
	void (YYCDECL *yymtextoverflow)(struct yymlexer YYFAR *yy);
	void (YYCDECL *yymunputoverflow)(struct yymlexer YYFAR *yy);
	void (YYCDECL *yymerror)(struct yymlexer YYFAR *yy, YYCONST char YYFAR *text);
	int (YYCDECL *yymaction)(struct yymlexer YYFAR *yy, int action);
#else
	int (YYCDECL *yymgetchar)();
	int (YYCDECL *yyminput)();
	void (YYCDECL *yymoutput)();
	void (YYCDECL *yymunput)();
	int (YYCDECL *yymwrap)();
	void (YYCDECL *yymtextoverflow)();
	void (YYCDECL *yymunputoverflow)();
	void (YYCDECL *yymerror)();
	int (YYCDECL *yymaction)();
#endif

	/* tables */
	/* fast lexical analyser */
	YYCONST yymtransition_t YYNEARFAR *yymtransition;
	int yymtransitionmax;
	/* compact lexical analyser */
	YYCONST yymctransition_t YYNEARFAR *yymctransition;
	/* common */
	YYCONST yymatch_t YYNEARFAR *yymmatch;
	YYCONST yymstate_t YYNEARFAR *yymstate;
	YYCONST yybackup_t YYNEARFAR *yymbackup;

	struct yymparser YYFAR *yymparserptr;	/* parser */ 
	void YYFAR *yymdata;					/* user data */

	/* debugging */
#ifdef YYDEBUG
	YYBOOL yymdebug;
	YYBOOL yymdebugflush;
	YYCSTD FILE YYFAR *yymdebugout;
#endif
} yymlexer_t;

/* instance functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yymcreatelexer(yymlexer_t YYFAR *yy, YYCONST yymlexer_t YYFAR *src);
YYEXPFUNC(void) YYCDECL yymdestroylexer(yymlexer_t YYFAR *yy);
#else
YYEXPFUNC(YYBOOL) YYCDECL yymcreatelexer();
YYEXPFUNC(void) YYCDECL yymdestroylexer();
#endif

/* general functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yymclex(yymlexer_t YYFAR *yy);
YYEXPFUNC(int) YYCDECL yymlex(yymlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymcleanuplexer(yymlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yyminitlexer(yymlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymreset(yymlexer_t YYFAR *yy);
YYEXPFUNC(YYBOOL) YYCDECL yymsettextsize(yymlexer_t YYFAR *yy, int size);
YYEXPFUNC(YYBOOL) YYCDECL yymsetunputsize(yymlexer_t YYFAR *yy, int size);
#else
YYEXPFUNC(int) YYCDECL yymclex();
YYEXPFUNC(int) YYCDECL yymlex();
YYEXPFUNC(void) YYCDECL yymcleanuplexer();
YYEXPFUNC(void) YYCDECL yyminitlexer();
YYEXPFUNC(void) YYCDECL yymreset();
YYEXPFUNC(YYBOOL) YYCDECL yymsettextsize();
YYEXPFUNC(YYBOOL) YYCDECL yymsetunputsize();
#endif

/* service functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(int) YYCDECL yymgetchar(yymlexer_t YYFAR *yy);
YYEXPFUNC(int) YYCDECL yyminput(yymlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymoutput(yymlexer_t YYFAR *yy, int ch);
YYEXPFUNC(void) YYCDECL yymunput(yymlexer_t YYFAR *yy, int ch);
YYEXPFUNC(int) YYCDECL yymwrap(yymlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymtextoverflow(yymlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymunputoverflow(yymlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymlexererror(yymlexer_t YYFAR *yy, YYCONST char YYFAR *text);
#else
YYEXPFUNC(int) YYCDECL yymgetchar();
YYEXPFUNC(int) YYCDECL yyminput();
YYEXPFUNC(void) YYCDECL yymoutput();
YYEXPFUNC(void) YYCDECL yymunput();
YYEXPFUNC(int) YYCDECL yymwrap();
YYEXPFUNC(void) YYCDECL yymtextoverflow();
YYEXPFUNC(void) YYCDECL yymunputoverflow();
YYEXPFUNC(void) YYCDECL yymlexererror();
#endif

/* action functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymecho(yymlexer_t YYFAR *yy);
YYEXPFUNC(void) YYCDECL yymless(yymlexer_t YYFAR *yy, int length);
#else
YYEXPFUNC(void) YYCDECL yymecho();
YYEXPFUNC(void) YYCDECL yymless();
#endif
#define yymbegin(yy, state) ((yy)->yymstart = (state))
#define yymmore(yy) ((yy)->yymmoreflg = YYTRUE)
#define yymnewline(yy, newline) ((newline) ? (yy)->yymeol = YYTRUE : ((yy)->yymeol = YYFALSE))
#define yymreject(yy) ((yy)->yymrejectflg = YYTRUE)
#define yymunputcount(yy) (yy)->yymunputindex

/* helper functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yymback(YYCONST yymatch_t YYNEARFAR *p, int action);
#else
YYEXPFUNC(YYBOOL) YYCDECL yymback();
#endif

/* debugging functions */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdebugoutput(yymlexer_t YYFAR *yy, int ch);
YYEXPFUNC(void) YYCDECL yymdmatch(yymlexer_t YYFAR *yy, int expr);
YYEXPFUNC(void) YYCDECL yymlexerdebugoutput(yymlexer_t YYFAR *yy, YYCONST char YYFAR *string);
#else
YYEXPFUNC(void) YYCDECL yymdebugoutput();
YYEXPFUNC(void) YYCDECL yymdmatch();
YYEXPFUNC(void) YYCDECL yymlexerdebugoutput();
#endif
#endif

#define yymisfastlexer(yy) ((yy)->yymtransition != NULL)
#define yymiscompactlexer(yy) ((yy)->yymctransition != NULL)

/* compatibility */
#define yymlex_t yymlexer_t
#define yymcreatelex yymcreatelexer
#define yymdestroylex yymdestroylexer
#define yymlexcleanup yymcleanuplexer
#define yymlexinit yyminitlexer
#ifdef YYDEBUG
#define yymlexdebugoutput yymlexerdebugoutput
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
