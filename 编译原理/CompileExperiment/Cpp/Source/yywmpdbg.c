/************************************************************
yywmpdbg.c
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywmpars.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

#ifdef YYWIN32
#include <windows.h>
#include <winbase.h>
#endif

_YL_BEGIN

#ifdef YYDEBUG

#ifdef YYPROTOTYPE
YYEXPFUNC(YYCONST wchar_t *) YYCDECL yywmtokenstring(yywmparser_t YYFAR *yy, yywint_t token)
#else
YYEXPFUNC(YYCONST wchar_t *) YYCDECL yywmtokenstring(yy, token)
yywmparser_t YYFAR *yy;
yywint_t token;
#endif
{
	YYCONST yywmsymbol_t YYNEARFAR *symbol;
	yyassert(yy != NULL);
	yyassert(token >= 0);

	symbol = yy->yymsymbol;
	while (symbol->yymname != NULL) {
		if (symbol->yymtoken == token) {
			return symbol->yymname;
		}
		symbol++;
	}
	return L"illegal-token";
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdgettoken(yywmparser_t YYFAR *yy, yywint_t token)
#else
YYEXPFUNC(void) YYCDECL yywmdgettoken(yy, token)
yywmparser_t YYFAR *yy;
yywint_t token;
#endif
{
	yyassert(yy != NULL);
	yyassert(token >= 0);
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];
		YYCONST wchar_t *tokenstring = yywmtokenstring(yy, token);
		yyassert(tokenstring != NULL);

		swprintf(string, L"%p: get token ", (void *) yy);
		yywmparserdebugoutput(yy, string);
		yywmparserdebugoutput(yy, tokenstring);
		swprintf(string, L" (%ld)\n", (long) token);
		yywmparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdshift(yywmparser_t YYFAR *yy, yywint_t token)
#else
YYEXPFUNC(void) YYCDECL yywmdshift(yy, token)
yywmparser_t YYFAR *yy;
yywint_t token;
#endif
{
	yyassert(yy != NULL);
	yyassert(token >= 0);
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];
		YYCONST wchar_t *tokenstring = yywmtokenstring(yy, token);
		yyassert(tokenstring != NULL);

		swprintf(string, L"%p: shift token ", (void *) yy);
		yywmparserdebugoutput(yy, string);
		yywmparserdebugoutput(yy, tokenstring);
		swprintf(string, L" (%ld)\n", (long) token);
		yywmparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdreduce(yywmparser_t YYFAR *yy, int rule)
#else
YYEXPFUNC(void) YYCDECL yywmdreduce(yy, rule)
yywmparser_t YYFAR *yy;
int rule;
#endif
{
	yyassert(yy != NULL);
	yyassert(rule >= 0);
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];

		swprintf(string, L"%p: reduce rule ", (void *) yy);
		yywmparserdebugoutput(yy, string);
		yywmparserdebugoutput(yy, yy->yymrule[rule]);
		swprintf(string, L" (%d)\n", (int) rule);
		yywmparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdsyntaxerror(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywmdsyntaxerror(yy)
yywmparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];

		swprintf(string, L"%p: syntax error\n", (void *) yy);
		yywmparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdaccept(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywmdaccept(yy)
yywmparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];

		swprintf(string, L"%p: accept\n", (void *) yy);
		yywmparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdabort(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywmdabort(yy)
yywmparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];

		swprintf(string, L"%p: abort\n", (void *) yy);
		yywmparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmddiscard(yywmparser_t YYFAR *yy, yywint_t token)
#else
YYEXPFUNC(void) YYCDECL yywmddiscard(yy, token)
yywmparser_t YYFAR *yy;
yywint_t token;
#endif
{
	yyassert(yy != NULL);
	yyassert(token >= 0);
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];
		YYCONST wchar_t *tokenstring = yywmtokenstring(yy, token);
		yyassert(tokenstring != NULL);

		swprintf(string, L"%p: discard token ", (void *) yy);
		yywmparserdebugoutput(yy, string);
		yywmparserdebugoutput(yy, tokenstring);
		swprintf(string, L" (%ld)\n", (long) token);
		yywmparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdexit(yywmparser_t YYFAR *yy, int exitcode)
#else
YYEXPFUNC(void) YYCDECL yywmdexit(yy, exitcode)
yywmparser_t YYFAR *yy;
int exitcode;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];

		swprintf(string, L"%p: exit with code %d\n", (void *) yy, (int) exitcode);
		yywmparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdthrowerror(yywmparser_t YYFAR *yy, int errorpop)
#else
YYEXPFUNC(void) YYCDECL yywmdthrowerror(yy, errorpop)
yywmparser_t YYFAR *yy;
int errorpop;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];

		swprintf(string, L"%p: throw error and pop %d error handling state(s)\n",
			(void *) yy, (int) errorpop);
		yywmparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdretire(yywmparser_t YYFAR *yy, int retirecode)
#else
YYEXPFUNC(void) YYCDECL yywmdretire(yy, retirecode)
yywmparser_t YYFAR *yy;
int retirecode;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];

		swprintf(string, L"%p: retire with code %d\n", (void *) yy, (int) retirecode);
		yywmparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmdattemptrecovery(yywmparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yywmdattemptrecovery(yy)
yywmparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		wchar_t string[128];

		swprintf(string, L"%p: attempting error recovery\n", (void *) yy);
		yywmparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yywmparserdebugoutput(yywmparser_t YYFAR *yy, YYCONST wchar_t YYFAR *string)
#else
YYEXPFUNC(void) YYCDECL yywmparserdebugoutput(yy, string)
yywmparser_t YYFAR *yy;
YYCONST wchar_t YYFAR *string;
#endif
{
	yyassert(yy != NULL);
	yyassert(string != NULL);

#ifdef YYWIN32
	if (yy->yymdebugout != NULL) {
#else
		yyassert(yy->yymdebugout != NULL);
#endif
		while (*string != L'\0') {
			putwc(*string++, yy->yymdebugout);
		}

		if (yygetglobaldebugflush() || yy->yymdebugflush) {
			fflush(yy->yymdebugout);
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
