/************************************************************
yyacpdbg.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#include "yydefs.h"

#if !(defined(YYDEBUG) && defined(YYSTDCPPLIB)) || defined(YYGROUP)

#ifdef YYSTDCPPLIB
#include <cstdio>
#else
#include <stdio.h>
#endif

#include "yycpars.h"

#ifdef YYSTDCPPLIB
using namespace std;
#endif

#ifdef YYWIN32
#include <windows.h>
#include <winbase.h>
#endif

_YL_BEGIN

#ifdef YYDEBUG

const char* yyparser::yytokenstring(int token) const
{
	yyassert(token >= 0);

	const yysymbol_t YYNEARFAR* symbol = yysymbol;
	while (symbol->yyname != NULL) {
		if (symbol->yytoken == token) {
			return symbol->yyname;
		}
		symbol++;
	}
	return "illegal-token";
}

void yyparser::yydgettoken(int token) const
{
	yyassert(token >= 0);
	if (yygetglobaldebug() || yydebug) {
		char string[128];
		const char* tokenstring = yytokenstring(token);
		yyassert(tokenstring != NULL);

		sprintf(string, "%p: get token ", (void*)this);
		yydebugoutput(string);
		yydebugoutput(tokenstring);
		sprintf(string, " (%d)\n", (int)token);
		yydebugoutput(string);
	}
}

void yyparser::yydshift(int token) const
{
	yyassert(token >= 0);
	if (yygetglobaldebug() || yydebug) {
		char string[128];
		const char* tokenstring = yytokenstring(token);
		yyassert(tokenstring != NULL);

		sprintf(string, "%p: shift token ", (void*)this);
		yydebugoutput(string);
		yydebugoutput(tokenstring);
		sprintf(string, " (%d)\n", (int)token);
		yydebugoutput(string);
	}
}

void yyparser::yydreduce(int rule) const
{
	yyassert(rule >= 0);
	if (yygetglobaldebug() || yydebug) {
		char string[128];

		sprintf(string, "%p: reduce rule ", (void*)this);
		yydebugoutput(string);
		yydebugoutput(yyrule[rule]);
		sprintf(string, " (%d)\n", (int)rule);
		yydebugoutput(string);
	}
}

void yyparser::yydsyntaxerror() const
{
	if (yygetglobaldebug() || yydebug) {
		char string[128];

		sprintf(string, "%p: syntax error\n", (void*)this);
		yydebugoutput(string);
	}
}

void yyparser::yydaccept() const
{
	if (yygetglobaldebug() || yydebug) {
		char string[128];

		sprintf(string, "%p: accept\n", (void*)this);
		yydebugoutput(string);
	}
}

void yyparser::yydabort() const
{
	if (yygetglobaldebug() || yydebug) {
		char string[128];

		sprintf(string, "%p: abort\n", (void*)this);
		yydebugoutput(string);
	}
}

void yyparser::yyddiscard(int token) const
{
	yyassert(token >= 0);
	if (yygetglobaldebug() || yydebug) {
		char string[128];
		const char* tokenstring = yytokenstring(token);
		yyassert(tokenstring != NULL);

		sprintf(string, "%p: discard token ", (void*)this);
		yydebugoutput(string);
		yydebugoutput(tokenstring);
		sprintf(string, " (%d)\n", (int)token);
		yydebugoutput(string);
	}
}

void yyparser::yydexit(int exitcode) const
{
	if (yygetglobaldebug() || yydebug) {
		char string[128];

		sprintf(string, "%p: exit with code %d\n", (void*)this, (int)exitcode);
		yydebugoutput(string);
	}
}

void yyparser::yydthrowerror(int errorpop) const
{
	if (yygetglobaldebug() || yydebug) {
		char string[128];

		sprintf(string, "%p: throw error and pop %d error handling state(s)\n",
			(void*)this, (int)errorpop);
		yydebugoutput(string);
	}
}

void yyparser::yydretire(int retirecode) const
{
	if (yygetglobaldebug() || yydebug) {
		char string[128];

		sprintf(string, "%p: retire with code %d\n", (void*)this, (int)retirecode);
		yydebugoutput(string);
	}
}

void yyparser::yydattemptrecovery() const
{
	if (yygetglobaldebug() || yydebug) {
		char string[128];

		sprintf(string, "%p: attempting error recovery\n", (void*)this);
		yydebugoutput(string);
	}
}

void yyparser::yydebugoutput(const char YYFAR* string) const
{
	yyassert(string != NULL);

#ifdef YYWIN32
	if (yydebugout != NULL) {
#else
		yyassert(yydebugout != NULL);
#endif
		while (*string != '\0') {
#ifdef YYSTDCPPLIB
			yydebugout->put(*string++);
#else
			putc(*string++, yydebugout);
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
		OutputDebugString(string);
		Sleep(0);		// makes sure debug string is processed
	}
#endif
}

#endif

_YL_END

#endif
