/************************************************************
yywspdbg.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

#ifdef YYWIN32
#include <windows.h>
#include <winbase.h>
#endif

_YL_BEGIN

#ifdef YYDEBUG

YYBOOL YYNEAR YYDCDECL yywparserdebug = YYFALSE;
YYBOOL YYNEAR YYDCDECL yywparserdebugstack = YYFALSE;
YYBOOL YYNEAR YYDCDECL yywparserdebugflush = YYFALSE;
#ifndef YYNINITSTREAM
FILE YYFAR *YYNEAR YYDCDECL yywparserdebugout = stdout;
#else
FILE YYFAR *YYNEAR YYDCDECL yywparserdebugout = NULL;
#endif

#ifdef YYPROTOTYPE
YYCONST wchar_t *YYCDECL yywtokenstring(yywint_t token)
#else
YYCONST wchar_t *YYCDECL yywtokenstring(token)
yywint_t token;
#endif
{
	YYCONST yywsymbol_t YYNEARFAR *symbol;
	yyassert(token >= 0);

	symbol = yywsymbol;
	while (symbol->yyname != NULL) {
		if (symbol->yytoken == token) {
			return symbol->yyname;
		}
		symbol++;
	}
	return L"illegal-token";
}

#ifdef YYPROTOTYPE
void YYCDECL yywdgettoken(yywint_t token)
#else
void YYCDECL yywdgettoken(token)
yywint_t token;
#endif
{
	yyassert(token >= 0);
	if (yygetglobaldebug() || yywparserdebug) {
		wchar_t string[128];
		YYCONST wchar_t *tokenstring = yywtokenstring(token);
		yyassert(tokenstring != NULL);

		yywparserdebugoutput(L"get token ");
		yywparserdebugoutput(tokenstring);
		swprintf(string, L" (%ld)\n", (long) token);
		yywparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yywdshift(yywint_t token)
#else
void YYCDECL yywdshift(token)
yywint_t token;
#endif
{
	yyassert(token >= 0);
	if (yygetglobaldebug() || yywparserdebug) {
		wchar_t string[128];
		YYCONST wchar_t *tokenstring = yywtokenstring(token);
		yyassert(tokenstring != NULL);

		yywparserdebugoutput(L"shift token ");
		yywparserdebugoutput(tokenstring);
		swprintf(string, L" (%ld)\n", (long) token);
		yywparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yywdreduce(int rule)
#else
void YYCDECL yywdreduce(rule)
int rule;
#endif
{
	yyassert(rule >= 0);
	if (yygetglobaldebug() || yywparserdebug) {
		wchar_t string[128];

		yywparserdebugoutput(L"reduce rule ");
		yywparserdebugoutput(yywrule[rule]);
		swprintf(string, L" (%d)\n", (int) rule);
		yywparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yywdsyntaxerror(void)
#else
void YYCDECL yywdsyntaxerror()
#endif
{
	if (yygetglobaldebug() || yywparserdebug) {
		yywparserdebugoutput(L"syntax error\n");
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yywdaccept(void)
#else
void YYCDECL yywdaccept()
#endif
{
	if (yygetglobaldebug() || yywparserdebug) {
		yywparserdebugoutput(L"accept\n");
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yywdabort(void)
#else
void YYCDECL yywdabort()
#endif
{
	if (yygetglobaldebug() || yywparserdebug) {
		yywparserdebugoutput(L"abort\n");
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yywddiscard(yywint_t token)
#else
void YYCDECL yywddiscard(token)
yywint_t token;
#endif
{
	yyassert(token >= 0);
	if (yygetglobaldebug() || yywparserdebug) {
		wchar_t string[128];
		YYCONST wchar_t *tokenstring = yywtokenstring(token);
		yyassert(tokenstring != NULL);

		yywparserdebugoutput(L"discard token ");
		yywparserdebugoutput(tokenstring);
		swprintf(string, L" (%ld)\n", (long) token);
		yywparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yywdexit(int exitcode)
#else
void YYCDECL yywdexit(exitcode)
int exitcode;
#endif
{
	if (yygetglobaldebug() || yywparserdebug) {
		wchar_t string[128];

		swprintf(string, L"exit with code %d\n", (int) exitcode);
		yywparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yywdthrowerror(int errorpop)
#else
void YYCDECL yywdthrowerror(errorpop)
int errorpop;
#endif
{
	if (yygetglobaldebug() || yywparserdebug) {
		wchar_t string[128];

		swprintf(string, L"throw error and pop %d error handling state(s)\n",
			(int) errorpop);
		yywparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yywdretire(int retirecode)
#else
void YYCDECL yywdretire(retirecode)
int retirecode;
#endif
{
	if (yygetglobaldebug() || yywparserdebug) {
		wchar_t string[128];

		swprintf(string, L"retire with code %d\n", (int) retirecode);
		yywparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yywdattemptrecovery(void)
#else
void YYCDECL yywdattemptrecovery()
#endif
{
	if (yygetglobaldebug() || yywparserdebug) {
		yywparserdebugoutput(L"attempting error recovery\n");
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yywparserdebugoutput(YYCONST wchar_t YYFAR *string)
#else
void YYCDECL yywparserdebugoutput(string)
YYCONST wchar_t YYFAR *string;
#endif
{
	yyassert(string != NULL);

#ifdef YYWIN32
	if (yywparserdebugout != NULL) {
#else
		yyassert(yywparserdebugout != NULL);
#endif
		while (*string != L'\0') {
			putwc(*string++, yywparserdebugout);
		}

		if (yygetglobaldebugflush() || yywparserdebugflush) {
			fflush(yywparserdebugout);
		}
#ifdef YYWIN32
	}
	else {
		OutputDebugStringW(string);
		Sleep(0);		// makes sure debug string is processed
	}
#endif
}

#endif

_YL_END

#endif
