/************************************************************
yydebug.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yyglobal.h"

#ifdef YYWIN32
#include <windows.h>
#endif

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

/* variables */
#ifdef YYDEBUG
#ifdef YYMT
static YYBOOL YYNEAR YYDCDECL yyglobaldebug = YYFALSE;
static YYBOOL YYNEAR YYDCDECL yyglobaldebugstack = YYFALSE;	/* parsers only */
static YYBOOL YYNEAR YYDCDECL yyglobaldebugflush = YYFALSE;

static CRITICAL_SECTION YYNEAR YYDCDECL yyglobaldebugcriticalsection;
static CRITICAL_SECTION YYNEAR YYDCDECL yyglobaldebugstackcriticalsection;
static CRITICAL_SECTION YYNEAR YYDCDECL yyglobaldebugflushcriticalsection;
static YYBOOL YYNEAR YYDCDECL yyinitmutexflg = YYFALSE;
#else
YYEXPDATA(YYBOOL) YYNEAR YYDCDECL yyglobaldebug = YYFALSE;
YYEXPDATA(YYBOOL) YYNEAR YYDCDECL yyglobaldebugstack = YYFALSE;	/* parsers only */
YYEXPDATA(YYBOOL) YYNEAR YYDCDECL yyglobaldebugflush = YYFALSE;
#endif
#endif

/* mutex functions */
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yyinitmutex(void)
#else
YYEXPFUNC(void) YYCDECL yyinitmutex()
#endif
{
#if defined(YYDEBUG) && defined(YYMT)
	if (!yyinitmutexflg) {
		yyinitmutexflg = YYTRUE;
		InitializeCriticalSection(&yyglobaldebugcriticalsection);
		InitializeCriticalSection(&yyglobaldebugstackcriticalsection);
		InitializeCriticalSection(&yyglobaldebugflushcriticalsection);
	}
#endif
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yydeletemutex(void)
#else
YYEXPFUNC(void) YYCDECL yydeletemutex()
#endif
{
#if defined(YYDEBUG) && defined(YYMT)
	if (yyinitmutexflg) {
		yyinitmutexflg = YYFALSE;
		DeleteCriticalSection(&yyglobaldebugcriticalsection);
		DeleteCriticalSection(&yyglobaldebugstackcriticalsection);
		DeleteCriticalSection(&yyglobaldebugflushcriticalsection);
	}
#endif
}

/* multithreaded debugging functions */
#if defined(YYDEBUG) && defined(YYMT)
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yysetglobaldebug(YYBOOL globaldebug)
#else
YYEXPFUNC(void) YYCDECL yysetglobaldebug(globaldebug)
YYBOOL globaldebug;
#endif
{
	if (yyinitmutexflg) {
		EnterCriticalSection(&yyglobaldebugcriticalsection);
		yyglobaldebug = globaldebug;
		LeaveCriticalSection(&yyglobaldebugcriticalsection);
	}
	else {
		yyglobaldebug = globaldebug;
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yygetglobaldebug(void)
#else
YYEXPFUNC(YYBOOL) YYCDECL yygetglobaldebug()
#endif
{
	YYBOOL globaldebug;
	if (yyinitmutexflg) {
		EnterCriticalSection(&yyglobaldebugcriticalsection);
		globaldebug = yyglobaldebug;
		LeaveCriticalSection(&yyglobaldebugcriticalsection);
	}
	else {
		globaldebug = yyglobaldebug;
	}
	return globaldebug;
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yysetglobaldebugstack(YYBOOL globaldebugstack)
#else
YYEXPFUNC(void) YYCDECL yysetglobaldebugstack(globaldebugstack)
YYBOOL globaldebugstack;
#endif
{
	if (yyinitmutexflg) {
		EnterCriticalSection(&yyglobaldebugstackcriticalsection);
		yyglobaldebugstack = globaldebugstack;
		LeaveCriticalSection(&yyglobaldebugstackcriticalsection);
	}
	else {
		yyglobaldebugstack = globaldebugstack;
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yygetglobaldebugstack(void)
#else
YYEXPFUNC(YYBOOL) YYCDECL yygetglobaldebugstack()
#endif
{
	YYBOOL globaldebugstack;
	if (yyinitmutexflg) {
		EnterCriticalSection(&yyglobaldebugflushcriticalsection);
		globaldebugstack = yyglobaldebugstack;
		LeaveCriticalSection(&yyglobaldebugflushcriticalsection);
	}
	else {
		globaldebugstack = yyglobaldebugstack;
	}
	return globaldebugstack;
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yysetglobaldebugflush(YYBOOL globaldebugflush)
#else
YYEXPFUNC(void) YYCDECL yysetglobaldebugflush(globaldebugflush)
YYBOOL globaldebugflush;
#endif
{
	if (yyinitmutexflg) {
		EnterCriticalSection(&yyglobaldebugflushcriticalsection);
		yyglobaldebugflush = globaldebugflush;
		LeaveCriticalSection(&yyglobaldebugflushcriticalsection);
	}
	else {
		yyglobaldebugflush = globaldebugflush;
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(YYBOOL) YYCDECL yygetglobaldebugflush(void)
#else
YYEXPFUNC(YYBOOL) YYCDECL yygetglobaldebugflush()
#endif
{
	YYBOOL globaldebugflush;
	if (yyinitmutexflg) {
		EnterCriticalSection(&yyglobaldebugflushcriticalsection);
		globaldebugflush = yyglobaldebugflush;
		LeaveCriticalSection(&yyglobaldebugflushcriticalsection);
	}
	else {
		globaldebugflush = yyglobaldebugflush;
	}
	return globaldebugflush;
}
#endif

_YL_END
