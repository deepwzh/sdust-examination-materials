/************************************************************
yytdefs.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#ifdef __cplusplus
extern "C" {
#endif

/* Microsoft defines */
#ifdef _MSC_VER

/* version 6.0 compatibility */
#if (_MSC_VER <= 600)
#define __cdecl     _cdecl
#define __far       _far
#define __near      _near
#define __segname   _segname
#endif

/* structure alignment */
#ifdef _WIN32
/*
 * Currently, all MS C compilers for Win32 platforms default to 8 byte
 * alignment.
 */
#pragma pack(push,8)
#else
#pragma pack(2)
#endif

/* win32 */
#ifdef _WIN32
#ifndef YYWIN32
#define YYWIN32
#endif
#endif

/* stream initialisation */
#ifdef _DLL
#ifndef YYNINITSTREAM
#define YYNINITSTREAM
#endif
#endif

/* dll modifiers */
#if defined(YYBUILDDLL)
#ifndef YYEXPCLASS
#define YYEXPCLASS		__declspec(dllexport)
#endif
#ifndef YYEXPDATA
#define YYEXPDATA(x)	__declspec(dllexport) x
#endif
#ifndef YYEXPFUNC
#define YYEXPFUNC(x)	__declspec(dllexport) x
#endif
#elif defined(YYDLL)
#ifndef YYEXPCLASS
#define YYEXPCLASS		__declspec(dllimport)
#endif
#ifndef YYEXPDATA
#define YYEXPDATA(x)	__declspec(dllimport) x
#endif
#ifndef YYEXPFUNC
#define YYEXPFUNC(x)	__declspec(dllimport) x
#endif
#else
#ifndef YYEXPCLASS
#define YYEXPCLASS
#endif
#ifndef YYEXPDATA
#define YYEXPDATA(x)	x
#endif
#ifndef YYEXPFUNC
#define YYEXPFUNC(x)	x
#endif
#endif

/* 32/16-bit modifiers */
#ifndef YYCDECL
#define YYCDECL __cdecl
#endif

/* 16-bit modifiers */
#ifndef _WIN32
#ifndef YYDCDECL
#define YYDCDECL __cdecl
#endif
#ifndef YYNEAR
#define YYNEAR __near
#endif
#ifndef YYNEARFAR
#if defined(M_I86TM) || defined(M_I86SM)
#define YYNEARFAR __near
#else
#define YYNEARFAR __far
#endif
#endif
#ifndef YYBASED_CODE
#if defined(M_I86MM) || defined(M_I86LM) || defined(M_I86HM)
#define YYBASED_CODE __based(__segname("_CODE"))
#endif
#endif
#endif

/* function prototypes */
#ifndef YYPROTOTYPE
#define YYPROTOTYPE
#endif

/* qualifiers */
#ifndef YYCONST
#define YYCONST const
#endif

/* yybool (Microsoft Visual C++ version 5 and above) */
#if _MSC_VER >= 1100
#ifndef yybool
#define yybool bool
#endif
#ifndef yytrue
#define yytrue true
#endif
#ifndef yyfalse
#define yyfalse false
#endif
#endif

/* YYNAMESPACE (Microsoft Visual C++ version 5 and above) */
#if _MSC_VER >= 1100
#ifndef YYNAMESPACE
#define YYNAMESPACE
#endif
#endif

/* YYSTDCPPLIB (Microsoft Visual C++ version 5 and above) */
#if _MSC_VER >= 1100
#ifndef YYSTDCPPLIB
#define YYSTDCPPLIB
#endif
#endif

/* YYCSTDCPPLIB */

/* YYMT (Microsoft Visual C++ version 4 and above) */
#if _MSC_VER >= 1000
#ifdef _MT
#ifndef YYMT
#define YYMT
#endif
#endif
#endif

/* YYNUNICODE (Below Microsoft Visual C++ version 4) */
#if _MSC_VER < 1000
#ifndef YYNUNICODE
#define YYNUNICODE
#endif
#endif

/* YYDLLENTRYPOINT */

#endif


/* Borland defines */
#ifdef __BORLANDC__

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#if (__BORLANDC__) >= 0x0530
#pragma pack(push, 1)
#pragma nopackwarning
#else
#pragma option -a-
#endif  /* (__BORLANDC__) >= 0x0530 */

#endif  /* !RC_INVOKED */

/* win32 */
#ifdef __WIN32__
#ifndef YYWIN32
#define YYWIN32
#endif
#endif

/* stream initialisation */
#ifdef _RTLDLL
#ifndef YYNINITSTREAM
#define YYNINITSTREAM
#endif
#endif

/* dll modifiers */
#if defined(YYBUILDDLL)
#ifndef YYEXPCLASS
#define YYEXPCLASS		__export
#endif
#ifndef YYEXPDATA
#define YYEXPDATA(x)	x __export
#endif
#ifndef YYEXPFUNC
#define YYEXPFUNC(x)	x __export
#endif
#elif defined(YYDLL)
#ifndef YYEXPCLASS
#define YYEXPCLASS		__import
#endif
#ifndef YYEXPDATA
#define YYEXPDATA(x)	x __import
#endif
#ifndef YYEXPFUNC
#define YYEXPFUNC(x)	x __import
#endif
#else
#ifndef YYEXPCLASS
#define YYEXPCLASS
#endif
#ifndef YYEXPDATA
#define YYEXPDATA(x)	x
#endif
#ifndef YYEXPFUNC
#define YYEXPFUNC(x)	x
#endif
#endif

/* 32/16-bit modifiers */
#ifndef YYCDECL
#define YYCDECL __cdecl
#endif
#ifndef YYDCDECL
#define YYDCDECL __cdecl
#endif

/* 16-bit modifiers */
#ifndef __WIN32__
#ifndef YYNEAR
#define YYNEAR __near
#endif
#ifndef YYFAR
#ifdef __DLL__
#define YYFAR __far
#endif
#endif
#ifndef YYNEARFAR
#if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
#define YYNEARFAR __near
#else
#define YYNEARFAR __far
#endif
#endif
#endif

/* function prototypes */
#ifndef YYPROTOTYPE
#define YYPROTOTYPE
#endif

/* qualifiers */
#ifndef YYCONST
#define YYCONST const
#endif

/* yybool (Borland C++Builder version 3 and above) */
#if (__BORLANDC__) >= 0x0530
#ifndef yybool
#define yybool bool
#endif
#ifndef yytrue
#define yytrue true
#endif
#ifndef yyfalse
#define yyfalse false
#endif
#endif

/* YYNAMESPACE (Borland C++Builder version 3 and above) */
#if (__BORLANDC__) >= 0x0530
#ifndef YYNAMESPACE
#define YYNAMESPACE
#endif
#endif

/* YYSTDCPPLIB (Borland C++Builder version 3 and above) */
#if (__BORLANDC__) >= 0x0530
#ifndef YYSTDCPPLIB
#define YYSTDCPPLIB
#endif
#endif

/* YYCSTDCPPLIB (Borland C++Builder version 3 and above) */
#if (__BORLANDC__) >= 0x0530
#ifndef YYCSTDCPPLIB
#define YYCSTDCPPLIB
#endif
#endif

/* YYMT (Borland C++Builder and Borland C++ version 4.52 and above) */
#if (__BORLANDC__) >= 0x0460
#ifdef __MT__
#ifndef YYMT
#define YYMT
#endif
#endif
#endif

/* YYNUNICODE (Below Borland C++ version 3) */
#if (__BORLANDC__) < 0x0530
#ifndef YYNUNICODE
#define YYNUNICODE
#endif
#endif

/* YYDLLENTRYPOINT (Below Borland C++ version 3) */
#if (__BORLANDC__) < 0x0530
#ifndef YYDLLENTRYPOINT
#define YYDLLENTRYPOINT
#endif
#endif

#endif

#ifdef __cplusplus
};
#endif
