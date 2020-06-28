/************************************************************
yywcpdbg.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yywcpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

#ifdef YYWIN32
#include <windows.h>
#include <winbase.h>
#endif

_YL_BEGIN

#ifdef YYDEBUG

const wchar_t* yywparser::yytokenstring(yywint_t token) const
{
	yyassert(token >= 0);

	const yywsymbol_t YYNEARFAR* symbol = yysymbol;
	while (symbol->yyname != NULL) {
		if (symbol->yytoken == token) {
			return symbol->yyname;
		}
		symbol++;
	}
	return L"illegal-token";
}

void yywparser::yydgettoken(yywint_t token) const
{
	yyassert(token >= 0);
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];
		const wchar_t* tokenstring = yytokenstring(token);
		yyassert(tokenstring != NULL);

		swprintf(string, L"%p: get token ", (void*)this);
		yydebugoutput(string);
		yydebugoutput(tokenstring);
		swprintf(string, L" (%ld)\n", (long)token);
		yydebugoutput(string);
	}
}

void yywparser::yydshift(yywint_t token) const
{
	yyassert(token >= 0);
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];
		const wchar_t* tokenstring = yytokenstring(token);
		yyassert(tokenstring != NULL);

		swprintf(string, L"%p: shift token ", (void*)this);
		yydebugoutput(string);
		yydebugoutput(tokenstring);
		swprintf(string, L" (%ld)\n", (long)token);
		yydebugoutput(string);
	}
}

void yywparser::yydreduce(int rule) const
{
	yyassert(rule >= 0);
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];

		swprintf(string, L"%p: reduce rule ", (void*)this);
		yydebugoutput(string);
		yydebugoutput(yyrule[rule]);
		swprintf(string, L" (%d)\n", (int)rule);
		yydebugoutput(string);
	}
}

void yywparser::yydsyntaxerror() const
{
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];

		swprintf(string, L"%p: syntax error\n", (void*)this);
		yydebugoutput(string);
	}
}

void yywparser::yydaccept() const
{
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];

		swprintf(string, L"%p: accept\n", (void*)this);
		yydebugoutput(string);
	}
}

void yywparser::yydabort() const
{
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];

		swprintf(string, L"%p: abort\n", (void*)this);
		yydebugoutput(string);
	}
}

void yywparser::yyddiscard(yywint_t token) const
{
	yyassert(token >= 0);
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];
		const wchar_t* tokenstring = yytokenstring(token);
		yyassert(tokenstring != NULL);

		swprintf(string, L"%p: discard token ", (void*)this);
		yydebugoutput(string);
		yydebugoutput(tokenstring);
		swprintf(string, L" (%ld)\n", (long)token);
		yydebugoutput(string);
	}
}

void yywparser::yydexit(int exitcode) const
{
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];

		swprintf(string, L"%p: exit with code %d\n", (void*)this, (int)exitcode);
		yydebugoutput(string);
	}
}

void yywparser::yydthrowerror(int errorpop) const
{
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];

		swprintf(string, L"%p: throw error and pop %d error handling state(s)\n",
			(void*)this, (int)errorpop);
		yydebugoutput(string);
	}
}

void yywparser::yydretire(int retirecode) const
{
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];

		swprintf(string, L"%p: retire with code %d\n", (void*)this, (int)retirecode);
		yydebugoutput(string);
	}
}

void yywparser::yydattemptrecovery() const
{
	if (yygetglobaldebug() || yydebug) {
		wchar_t string[128];

		swprintf(string, L"%p: attempting error recovery\n", (void*)this);
		yydebugoutput(string);
	}
}

void yywparser::yydebugoutput(const wchar_t YYFAR* string) const
{
	yyassert(string != NULL);

#ifdef YYWIN32
	if (yydebugout != NULL) {
#else
		yyassert(yydebugout != NULL);
#endif
		while (*string != L'\0') {
#ifdef YYSTDCPPLIB
			yydebugout->put(*string++);
#else
			putwc(*string++, yydebugout);
#endif
		}

		if (yygetglobaldebugflush() || yydebugflush) {
#ifdef YYSTDCPPLIB
			yydebugout->flush();
#else
			fflush(yydebugout);
#endif
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
