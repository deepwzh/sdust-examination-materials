/************************************************************
yyaspdbg.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yypars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

#ifdef YYWIN32
#include <windows.h>
#include <winbase.h>
#endif

_YL_BEGIN

#ifdef YYDEBUG

YYBOOL YYNEAR YYDCDECL yyparserdebug = YYFALSE;
YYBOOL YYNEAR YYDCDECL yyparserdebugstack = YYFALSE;
YYBOOL YYNEAR YYDCDECL yyparserdebugflush = YYFALSE;
#ifndef YYNINITSTREAM
FILE YYFAR *YYNEAR YYDCDECL yyparserdebugout = stdout;
#else
FILE YYFAR *YYNEAR YYDCDECL yyparserdebugout = NULL;
#endif

#ifdef YYPROTOTYPE
YYCONST char *YYCDECL yytokenstring(int token)
#else
YYCONST char *YYCDECL yytokenstring(token)
int token;
#endif
{
	YYCONST yysymbol_t YYNEARFAR *symbol;
	yyassert(token >= 0);

	symbol = yysymbol;
	while (symbol->yyname != NULL) {
		if (symbol->yytoken == token) {
			return symbol->yyname;
		}
		symbol++;
	}
	return "illegal-token";
}

#ifdef YYPROTOTYPE
void YYCDECL yydgettoken(int token)
#else
void YYCDECL yydgettoken(token)
int token;
#endif
{
	yyassert(token >= 0);
	if (yygetglobaldebug() || yyparserdebug) {
		char string[128];
		YYCONST char *tokenstring = yytokenstring(token);
		yyassert(tokenstring != NULL);

		yyparserdebugoutput("get token ");
		yyparserdebugoutput(tokenstring);
		sprintf(string, " (%d)\n", (int) token);
		yyparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yydshift(int token)
#else
void YYCDECL yydshift(token)
int token;
#endif
{
	yyassert(token >= 0);
	if (yygetglobaldebug() || yyparserdebug) {
		char string[128];
		YYCONST char *tokenstring = yytokenstring(token);
		yyassert(tokenstring != NULL);

		yyparserdebugoutput("shift token ");
		yyparserdebugoutput(tokenstring);
		sprintf(string, " (%d)\n", (int) token);
		yyparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yydreduce(int rule)
#else
void YYCDECL yydreduce(rule)
int rule;
#endif
{
	yyassert(rule >= 0);
	if (yygetglobaldebug() || yyparserdebug) {
		char string[128];

		yyparserdebugoutput("reduce rule ");
		yyparserdebugoutput(yyrule[rule]);
		sprintf(string, " (%d)\n", (int) rule);
		yyparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yydsyntaxerror(void)
#else
void YYCDECL yydsyntaxerror()
#endif
{
	if (yygetglobaldebug() || yyparserdebug) {
		yyparserdebugoutput("syntax error\n");
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yydaccept(void)
#else
void YYCDECL yydaccept()
#endif
{
	if (yygetglobaldebug() || yyparserdebug) {
		yyparserdebugoutput("accept\n");
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yydabort(void)
#else
void YYCDECL yydabort()
#endif
{
	if (yygetglobaldebug() || yyparserdebug) {
		yyparserdebugoutput("abort\n");
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yyddiscard(int token)
#else
void YYCDECL yyddiscard(token)
int token;
#endif
{
	yyassert(token >= 0);
	if (yygetglobaldebug() || yyparserdebug) {
		char string[128];
		YYCONST char *tokenstring = yytokenstring(token);
		yyassert(tokenstring != NULL);

		yyparserdebugoutput("discard token ");
		yyparserdebugoutput(tokenstring);
		sprintf(string, " (%d)\n", (int) token);
		yyparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yydexit(int exitcode)
#else
void YYCDECL yydexit(exitcode)
int exitcode;
#endif
{
	if (yygetglobaldebug() || yyparserdebug) {
		char string[128];

		sprintf(string, "exit with code %d\n", (int) exitcode);
		yyparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yydthrowerror(int errorpop)
#else
void YYCDECL yydthrowerror(errorpop)
int errorpop;
#endif
{
	if (yygetglobaldebug() || yyparserdebug) {
		char string[128];

		sprintf(string, "throw error and pop %d error handling state(s)\n",
			(int) errorpop);
		yyparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yydretire(int retirecode)
#else
void YYCDECL yydretire(retirecode)
int retirecode;
#endif
{
	if (yygetglobaldebug() || yyparserdebug) {
		char string[128];

		sprintf(string, "retire with code %d\n", (int) retirecode);
		yyparserdebugoutput(string);
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yydattemptrecovery(void)
#else
void YYCDECL yydattemptrecovery()
#endif
{
	if (yygetglobaldebug() || yyparserdebug) {
		yyparserdebugoutput("attempting error recovery\n");
	}
}

#ifdef YYPROTOTYPE
void YYCDECL yyparserdebugoutput(YYCONST char YYFAR *string)
#else
void YYCDECL yyparserdebugoutput(string)
YYCONST char YYFAR *string;
#endif
{
	yyassert(string != NULL);

#ifdef YYWIN32
	if (yyparserdebugout != NULL) {
#else
		yyassert(yyparserdebugout != NULL);
#endif
		while (*string != '\0') {
			putc(*string++, yyparserdebugout);
		}

		if (yygetglobaldebugflush() || yyparserdebugflush) {
			fflush(yyparserdebugout);
		}
#ifdef YYWIN32
	}
	else {
		OutputDebugString(string);
		Sleep(0);		// makes sure debug string is processed
	}
#endif
}

#endif

_YL_END

#endif
