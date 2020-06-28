/************************************************************
yyampdbg.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yympars.h"

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
YYEXPFUNC(YYCONST char *) YYCDECL yymtokenstring(yymparser_t YYFAR *yy, int token)
#else
YYEXPFUNC(YYCONST char *) YYCDECL yymtokenstring(yy, token)
yymparser_t YYFAR *yy;
int token;
#endif
{
	YYCONST yymsymbol_t YYNEARFAR *symbol;
	yyassert(yy != NULL);
	yyassert(token >= 0);

	symbol = yy->yymsymbol;
	while (symbol->yymname != NULL) {
		if (symbol->yymtoken == token) {
			return symbol->yymname;
		}
		symbol++;
	}
	return "illegal-token";
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdgettoken(yymparser_t YYFAR *yy, int token)
#else
YYEXPFUNC(void) YYCDECL yymdgettoken(yy, token)
yymparser_t YYFAR *yy;
int token;
#endif
{
	yyassert(yy != NULL);
	yyassert(token >= 0);
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];
		YYCONST char *tokenstring = yymtokenstring(yy, token);
		yyassert(tokenstring != NULL);

		sprintf(string, "%p: get token ", (void *) yy);
		yymparserdebugoutput(yy, string);
		yymparserdebugoutput(yy, tokenstring);
		sprintf(string, " (%d)\n", (int) token);
		yymparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdshift(yymparser_t YYFAR *yy, int token)
#else
YYEXPFUNC(void) YYCDECL yymdshift(yy, token)
yymparser_t YYFAR *yy;
int token;
#endif
{
	yyassert(yy != NULL);
	yyassert(token >= 0);
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];
		YYCONST char *tokenstring = yymtokenstring(yy, token);
		yyassert(tokenstring != NULL);

		sprintf(string, "%p: shift token ", (void *) yy);
		yymparserdebugoutput(yy, string);
		yymparserdebugoutput(yy, tokenstring);
		sprintf(string, " (%d)\n", (int) token);
		yymparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdreduce(yymparser_t YYFAR *yy, int rule)
#else
YYEXPFUNC(void) YYCDECL yymdreduce(yy, rule)
yymparser_t YYFAR *yy;
int rule;
#endif
{
	yyassert(yy != NULL);
	yyassert(rule >= 0);
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];

		sprintf(string, "%p: reduce rule ", (void *) yy);
		yymparserdebugoutput(yy, string);
		yymparserdebugoutput(yy, yy->yymrule[rule]);
		sprintf(string, " (%d)\n", (int) rule);
		yymparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdsyntaxerror(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymdsyntaxerror(yy)
yymparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];

		sprintf(string, "%p: syntax error\n", (void *) yy);
		yymparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdaccept(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymdaccept(yy)
yymparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];

		sprintf(string, "%p: accept\n", (void *) yy);
		yymparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdabort(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymdabort(yy)
yymparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];

		sprintf(string, "%p: abort\n", (void *) yy);
		yymparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymddiscard(yymparser_t YYFAR *yy, int token)
#else
YYEXPFUNC(void) YYCDECL yymddiscard(yy, token)
yymparser_t YYFAR *yy;
int token;
#endif
{
	yyassert(yy != NULL);
	yyassert(token >= 0);
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];
		YYCONST char *tokenstring = yymtokenstring(yy, token);
		yyassert(tokenstring != NULL);

		sprintf(string, "%p: discard token ", (void *) yy);
		yymparserdebugoutput(yy, string);
		yymparserdebugoutput(yy, tokenstring);
		sprintf(string, " (%d)\n", (int) token);
		yymparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdexit(yymparser_t YYFAR *yy, int exitcode)
#else
YYEXPFUNC(void) YYCDECL yymdexit(yy, exitcode)
yymparser_t YYFAR *yy;
int exitcode;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];

		sprintf(string, "%p: exit with code %d\n", (void *) yy, (int) exitcode);
		yymparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdthrowerror(yymparser_t YYFAR *yy, int errorpop)
#else
YYEXPFUNC(void) YYCDECL yymdthrowerror(yy, errorpop)
yymparser_t YYFAR *yy;
int errorpop;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];

		sprintf(string, "%p: throw error and pop %d error handling state(s)\n",
			(void *) yy, (int) errorpop);
		yymparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdretire(yymparser_t YYFAR *yy, int retirecode)
#else
YYEXPFUNC(void) YYCDECL yymdretire(yy, retirecode)
yymparser_t YYFAR *yy;
int retirecode;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];

		sprintf(string, "%p: retire with code %d\n", (void *) yy, (int) retirecode);
		yymparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdattemptrecovery(yymparser_t YYFAR *yy)
#else
YYEXPFUNC(void) YYCDECL yymdattemptrecovery(yy)
yymparser_t YYFAR *yy;
#endif
{
	yyassert(yy != NULL);
	if (yygetglobaldebug() || yy->yymdebug) {
		char string[128];

		sprintf(string, "%p: attempting error recovery\n", (void *) yy);
		yymparserdebugoutput(yy, string);
	}
}

#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymparserdebugoutput(yymparser_t YYFAR *yy, YYCONST char YYFAR *string)
#else
YYEXPFUNC(void) YYCDECL yymparserdebugoutput(yy, string)
yymparser_t YYFAR *yy;
YYCONST char YYFAR *string;
#endif
{
	yyassert(yy != NULL);
	yyassert(string != NULL);

#ifdef YYWIN32
	if (yy->yymdebugout != NULL) {
#else
		yyassert(yy->yymdebugout != NULL);
#endif
		while (*string != '\0') {
			putc(*string++, yy->yymdebugout);
		}

		if (yygetglobaldebugflush() || yy->yymdebugflush) {
			fflush(yy->yymdebugout);
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
