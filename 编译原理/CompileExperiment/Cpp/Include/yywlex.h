#ifndef YYWLEX_H
#define YYWLEX_H

/************************************************************
yywlex.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* globals */
#include <yyglobal.h>

/* single model c parsers and lexers cannot go in a dll */
#if !defined(YYBUILDDLL) && !defined(YYDLL)

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

#ifndef YYWSTATE_T
#define YYWSTATE_T
typedef struct yywstate {
	short yydef;		/* default state */
	long yybase;		/* base */
	short yymatch;		/* action associated with state */
} yywstate_t;
#endif

#ifndef YYWTRANSITION_T
#define YYWTRANSITION_T
typedef struct yywtransition {
	short yynext;		/* next state on transition */
	short yycheck;		/* check */
} yywtransition_t;
#endif

#ifndef YYWCTRANSITION_T
#define YYWCTRANSITION_T
typedef struct yywctransition {
	wchar_t yyfirst;		/* first character in range */
	wchar_t yylast;			/* last character in range */
	short yynext;			/* next state on transition */
} yywctransition_t;
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

/* general functions */
#ifdef YYPROTOTYPE
yywint_t YYCDECL yywclex(void);
yywint_t YYCDECL yywlex(void);
void YYCDECL yywcleanuplexer(void);
void YYCDECL yywinitlexer(void);
void YYCDECL yywreset(void);
YYBOOL YYCDECL yywsettextsize(int size);
YYBOOL YYCDECL yywsetunputsize(int size);
#else
yywint_t YYCDECL yywclex();
yywint_t YYCDECL yywlex();
void YYCDECL yywcleanuplexer();
void YYCDECL yywinitlexer();
void YYCDECL yywreset();
YYBOOL YYCDECL yywsettextsize();
YYBOOL YYCDECL yywsetunputsize();
#endif

/* service functions */
#ifdef YYPROTOTYPE
yywint_t YYCDECL yywgetchar(void);
yywint_t YYCDECL yywinput(void);
void YYCDECL yywoutput(yywint_t ch);
void YYCDECL yywunput(yywint_t ch);
int YYCDECL yywwrap(void);
void YYCDECL yywtextoverflow(void);
void YYCDECL yywunputoverflow(void);
void YYCDECL yywlexererror(YYCONST wchar_t YYFAR *text);
#else
yywint_t YYCDECL yywgetchar();
yywint_t YYCDECL yywinput();
void YYCDECL yywoutput();
void YYCDECL yywunput();
int YYCDECL yywwrap();
void YYCDECL yywtextoverflow();
void YYCDECL yywunputoverflow();
void YYCDECL yywlexererror();
#endif

/* action functions */
#ifdef YYPROTOTYPE
void YYCDECL yywecho(void);
void YYCDECL yywless(int length);
#else
void YYCDECL yywecho();
void YYCDECL yywless();
#endif
#define yywbegin(state) (yywstart = (state))
#define yywmore() (yywmoreflg = YYTRUE)
#define yywnewline(newline) ((newline) ? yyweol = YYTRUE : (yyweol = YYFALSE))
#define yywreject() (yywrejectflg = YYTRUE)
#define yywunputcount() yywunputindex

/* helper functions */
#ifdef YYPROTOTYPE
YYBOOL YYCDECL yywback(YYCONST yywmatch_t YYNEARFAR *p, int action);
#else
YYBOOL YYCDECL yywback();
#endif

/* variables */
extern YYBOOL YYNEAR YYDCDECL yywmoreflg;
extern YYBOOL YYNEAR YYDCDECL yywrejectflg;
extern YYBOOL YYNEAR YYDCDECL yywreturnflg;
extern YYBOOL YYNEAR YYDCDECL yywtextgrow;
extern YYBOOL YYNEAR YYDCDECL yywunputgrow;
extern YYBOOL YYNEAR YYDCDECL yyweol;
extern YYBOOL YYNEAR YYDCDECL yywoldeol;
extern int YYNEAR YYDCDECL yywstart;

extern YYCSTD FILE YYFAR *YYNEAR YYDCDECL yywin;
extern YYCSTD FILE YYFAR *YYNEAR YYDCDECL yywout;
extern YYCSTD FILE YYFAR *YYNEAR YYDCDECL yywlexererr;

extern int YYNEAR YYDCDECL yywleng;
extern int YYNEAR YYDCDECL yywlineno;
extern int YYNEAR YYDCDECL yywunputindex;

/* debugging functions */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
void YYCDECL yywdebugoutput(yywint_t ch);
void YYCDECL yywdmatch(int expr);
void YYCDECL yywlexerdebugoutput(YYCONST wchar_t YYFAR *string);
#else
void YYCDECL yywdebugoutput();
void YYCDECL yywdmatch();
void YYCDECL yywlexerdebugoutput();
#endif
#endif

/* debugging variables */
#ifdef YYDEBUG
extern YYBOOL YYNEAR YYDCDECL yywlexerdebug;
extern YYBOOL YYNEAR YYDCDECL yywlexerdebugflush;
extern YYCSTD FILE YYFAR *YYNEAR YYDCDECL yywlexerdebugout;
#endif

/* externally defined */
#ifdef YYPROTOTYPE
yywint_t YYCDECL yywlexeraction(int action);
#else
yywint_t YYCDECL yywlexeraction();
#endif

extern wchar_t YYFAR *YYNEAR YYDCDECL yywtext;
extern wchar_t YYFAR *YYNEAR YYDCDECL yywstext;
extern int YYNEAR YYDCDECL yywtext_size;
extern int YYNEAR YYDCDECL yywstext_size;
extern int YYNEAR YYDCDECL yywtext_max;

extern int YYFAR *YYNEAR YYDCDECL yywstatebuf;
extern int YYFAR *YYNEAR YYDCDECL yywsstatebuf;

/* unput buffer */
extern yywint_t YYFAR *YYNEAR YYDCDECL yywunputbufptr;
extern yywint_t YYFAR *YYNEAR YYDCDECL yywsunputbufptr;
extern int YYNEAR YYDCDECL yywunput_size;
extern int YYNEAR YYDCDECL yywsunput_size;
extern int YYNEAR YYDCDECL yywunput_max;

/* fast lexical analyser */
extern YYCONST yywtransition_t YYNEARFAR YYDCDECL yywtransition[];
extern long YYNEAR YYDCDECL yywtransitionmax;

/* compact lexical analyser */
extern YYCONST yywctransition_t YYNEARFAR YYDCDECL yywctransition[];

extern YYCONST yywmatch_t YYNEARFAR YYDCDECL yywmatch[];
extern YYCONST yywstate_t YYNEARFAR YYDCDECL yywstate[];
extern YYCONST yywbackup_t YYNEARFAR YYDCDECL yywbackup[];

/* compatibility */
#define yywlexcleanup yywcleanuplexer
#define yywlexinit yywinitlexer
#define yywlexerr yywlexererr
#ifdef YYDEBUG
#define yywlexdebugoutput yywlexerdebugoutput
#define yywlexdebug yywlexerdebug
#define yywlexdebugflush yywlexerdebugflush;
#define yywlexdebugout yywlexerdebugout;
#endif
#define yywlexaction yywlexeraction

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
