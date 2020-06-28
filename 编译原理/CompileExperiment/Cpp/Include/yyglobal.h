#ifndef YYGLOBAL_H
#define YYGLOBAL_H

/************************************************************
yyglobal.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* defines */
#include <yytdefs.h>

/* user defines */
#if defined(YYTUDEFS) || defined(YYUDEFS)
#include <yytudefs.h>
#endif

/* standard include files */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cassert>
#else
#include <assert.h>
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

/* c boolean type */
#ifndef YYBOOL
#define YYBOOL int
#endif
#ifndef YYTRUE
#define YYTRUE 1
#endif
#ifndef YYFALSE
#define YYFALSE 0
#endif

/* c++ boolean type */
#ifndef yybool
#define yybool int
#endif
#ifndef yytrue
#define yytrue 1
#endif
#ifndef yyfalse
#define yyfalse 0
#endif

/* initialisation functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yyinit(void);
YYEXPFUNC(void) YYCDECL yydelete(void);
#else
YYEXPFUNC(void) YYCDECL yyinit();
YYEXPFUNC(void) YYCDECL yydelete();
#endif

/* mutex functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yyinitmutex(void);
YYEXPFUNC(void) YYCDECL yydeletemutex(void);
#else
YYEXPFUNC(void) YYCDECL yyinitmutex();
YYEXPFUNC(void) YYCDECL yydeletemutex();
#endif

/* debugging variables */
#if defined(YYDEBUG) && !defined(YYMT)
extern YYEXPDATA(YYBOOL) YYNEAR YYDCDECL yyglobaldebug;
extern YYEXPDATA(YYBOOL) YYNEAR YYDCDECL yyglobaldebugstack;
extern YYEXPDATA(YYBOOL) YYNEAR YYDCDECL yyglobaldebugflush;
#endif

/* debugging functions */
#ifdef YYDEBUG
#ifdef YYMT
#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yygetglobaldebug(void);
YYEXPFUNC(void) YYCDECL yysetglobaldebug(YYBOOL globaldebug);
YYEXPFUNC(YYBOOL) YYCDECL yygetglobaldebugstack(void);
YYEXPFUNC(void) YYCDECL yysetglobaldebugstack(YYBOOL globaldebugstack);
YYEXPFUNC(YYBOOL) YYCDECL yygetglobaldebugflush(void);
YYEXPFUNC(void) YYCDECL yysetglobaldebugflush(YYBOOL globaldebugflush);
#else
YYEXPFUNC(YYBOOL) YYCDECL yygetglobaldebug();
YYEXPFUNC(void) YYCDECL yysetglobaldebug();
YYEXPFUNC(YYBOOL) YYCDECL yygetglobaldebugstack();
YYEXPFUNC(void) YYCDECL yysetglobaldebugstack();
YYEXPFUNC(YYBOOL) YYCDECL yygetglobaldebugflush();
YYEXPFUNC(void) YYCDECL yysetglobaldebugflush();
#endif
#else
#ifdef __cplusplus
inline YYBOOL YYCDECL yygetglobaldebug() { return yyglobaldebug; }
inline void YYCDECL yysetglobaldebug(YYBOOL globaldebug) { yyglobaldebug = globaldebug; }
inline YYBOOL YYCDECL yygetglobaldebugstack() { return yyglobaldebugstack; }
inline void YYCDECL yysetglobaldebugstack(YYBOOL globaldebugstack) { yyglobaldebugstack = globaldebugstack; }
inline YYBOOL YYCDECL yygetglobaldebugflush() { return yyglobaldebugflush; }
inline void YYCDECL yysetglobaldebugflush(YYBOOL globaldebugflush) { yyglobaldebugflush = globaldebugflush; }
#else
#define yygetglobaldebug() (yyglobaldebug)
#define yysetglobaldebug(globaldebug) (yyglobaldebug = (globaldebug))
#define yygetglobaldebugstack() (yyglobaldebugstack)
#define yysetglobaldebugstack(globaldebugstack) (yyglobaldebugstack = (globaldebugstack))
#define yygetglobaldebugflush() (yyglobaldebugflush)
#define yysetglobaldebugflush(globaldebugflush) (yyglobaldebugflush = (globaldebugflush))
#endif
#endif
#endif

/* helper functions */
#ifndef yyassert
#define yyassert(expr) assert(expr)
#endif
#ifndef yymin
#define yymin(x, y) ((x) <= (y) ? (x) : (y))
#endif

#ifdef __cplusplus
};
#endif

_YL_END

/* user defines */
#if defined(YYBUDEFS) || defined(YYUDEFS)
#include <yybudefs.h>
#endif

/* defines */
#include <yybdefs.h>

#endif
