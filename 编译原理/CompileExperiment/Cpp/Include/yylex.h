#ifndef YYLEX_H
#define YYLEX_H

/************************************************************
yylex.h
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

#ifndef YYSTATE_T
#define YYSTATE_T
typedef struct yystate {
	short yydef;		/* default state */
	short yybase;		/* base */
	short yymatch;		/* action associated with state */
} yystate_t;
#endif

#ifndef YYTRANSITION_T
#define YYTRANSITION_T
typedef struct yytransition {
	short yynext;		/* next state on transition */
	short yycheck;		/* check */
} yytransition_t;
#endif

#ifndef YYCTRANSITION_T
#define YYCTRANSITION_T
typedef struct yyctransition {
	unsigned char yyfirst;	/* first character in range */
	unsigned char yylast;	/* last character in range */
	short yynext;			/* next state on transition */
} yyctransition_t;
#endif

typedef short yymatch_t;
typedef unsigned char yybackup_t;

/* general functions */
#ifdef YYPROTOTYPE
int YYCDECL yyclex(void);
int YYCDECL yylex(void);
void YYCDECL yycleanuplexer(void);
void YYCDECL yyinitlexer(void);
void YYCDECL yyreset(void);
YYBOOL YYCDECL yysettextsize(int size);
YYBOOL YYCDECL yysetunputsize(int size);
#else
int YYCDECL yyclex();
int YYCDECL yylex();
void YYCDECL yycleanuplexer();
void YYCDECL yyinitlexer();
void YYCDECL yyreset();
YYBOOL YYCDECL yysettextsize();
YYBOOL YYCDECL yysetunputsize();
#endif

/* service functions */
#ifdef YYPROTOTYPE
int YYCDECL yygetchar(void);
int YYCDECL yyinput(void);
void YYCDECL yyoutput(int ch);
void YYCDECL yyunput(int ch);
int YYCDECL yywrap(void);
void YYCDECL yytextoverflow(void);
void YYCDECL yyunputoverflow(void);
void YYCDECL yylexererror(YYCONST char YYFAR *text);
#else
int YYCDECL yygetchar();
int YYCDECL yyinput();
void YYCDECL yyoutput();
void YYCDECL yyunput();
int YYCDECL yywrap();
void YYCDECL yytextoverflow();
void YYCDECL yyunputoverflow();
void YYCDECL yylexererror();
#endif

/* action functions */
#ifdef YYPROTOTYPE
void YYCDECL yyecho(void);
void YYCDECL yyless(int length);
#else
void YYCDECL yyecho();
void YYCDECL yyless();
#endif
#define yybegin(state) (yystart = (state))
#define yymore() (yymoreflg = YYTRUE)
#define yynewline(newline) ((newline) ? yyeol = YYTRUE : (yyeol = YYFALSE))
#define yyreject() (yyrejectflg = YYTRUE)
#define yyunputcount() yyunputindex

/* compatibility */
#define BEGIN yystart = 
#define ECHO yyecho()
#define REJECT yyreject()
#define YYSTATE yystart
#define YY_START yystart

/* helper functions */
#ifdef YYPROTOTYPE
YYBOOL YYCDECL yyback(YYCONST yymatch_t YYNEARFAR *p, int action);
#else
YYBOOL YYCDECL yyback();
#endif

/* variables */
extern YYBOOL YYNEAR YYDCDECL yymoreflg;
extern YYBOOL YYNEAR YYDCDECL yyrejectflg;
extern YYBOOL YYNEAR YYDCDECL yyreturnflg;
extern YYBOOL YYNEAR YYDCDECL yytextgrow;
extern YYBOOL YYNEAR YYDCDECL yyunputgrow;
extern YYBOOL YYNEAR YYDCDECL yyeol;
extern YYBOOL YYNEAR YYDCDECL yyoldeol;
extern int YYNEAR YYDCDECL yystart;

extern YYCSTD FILE YYFAR *YYNEAR YYDCDECL yyin;
extern YYCSTD FILE YYFAR *YYNEAR YYDCDECL yyout;
extern YYCSTD FILE YYFAR *YYNEAR YYDCDECL yylexererr;

extern int YYNEAR YYDCDECL yyleng;
extern int YYNEAR YYDCDECL yylineno;
extern int YYNEAR YYDCDECL yyunputindex;

/* debugging functions */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
void YYCDECL yydebugoutput(int ch);
void YYCDECL yydmatch(int expr);
void YYCDECL yylexerdebugoutput(YYCONST char *string);
#else
void YYCDECL yydebugoutput();
void YYCDECL yydmatch();
void YYCDECL yylexerdebugoutput();
#endif
#endif

/* debugging variables */
#ifdef YYDEBUG
extern YYBOOL YYNEAR YYDCDECL yylexerdebug;
extern YYBOOL YYNEAR YYDCDECL yylexerdebugflush;
extern YYCSTD FILE YYFAR *YYNEAR YYDCDECL yylexerdebugout;
#endif

/* externally defined */
#ifdef YYPROTOTYPE
int YYCDECL yylexeraction(int action);
#else
int YYCDECL yylexeraction();
#endif

extern char YYFAR *YYNEAR YYDCDECL yytext;
extern char YYFAR *YYNEAR YYDCDECL yystext;
extern int YYNEAR YYDCDECL yytext_size;
extern int YYNEAR YYDCDECL yystext_size;
extern int YYNEAR YYDCDECL yytext_max;

extern int YYFAR *YYNEAR YYDCDECL yystatebuf;
extern int YYFAR *YYNEAR YYDCDECL yysstatebuf;

/* unput buffer */
extern int YYFAR *YYNEAR YYDCDECL yyunputbufptr;
extern int YYFAR *YYNEAR YYDCDECL yysunputbufptr;
extern int YYNEAR YYDCDECL yyunput_size;
extern int YYNEAR YYDCDECL yysunput_size;
extern int YYNEAR YYDCDECL yyunput_max;

/* fast lexical analyser */
extern YYCONST yytransition_t YYNEARFAR YYDCDECL yytransition[];
extern int YYNEAR YYDCDECL yytransitionmax;

/* compact lexical analyser */
extern YYCONST yyctransition_t YYNEARFAR YYDCDECL yyctransition[];

extern YYCONST yymatch_t YYNEARFAR YYDCDECL yymatch[];
extern YYCONST yystate_t YYNEARFAR YYDCDECL yystate[];
extern YYCONST yybackup_t YYNEARFAR YYDCDECL yybackup[];

/* compatibility */
#define yylexcleanup yycleanuplexer
#define yylexinit yyinitlexer
#define yylexerr yylexererr
#ifdef YYDEBUG
#define yylexdebugoutput yylexerdebugoutput
#define yylexdebug yylexerdebug
#define yylexdebugflush yylexerdebugflush;
#define yylexdebugout yylexerdebugout;
#endif
#define yylexaction yylexeraction

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
