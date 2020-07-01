/************************************************************
yyasdop.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* single model c parsers and lexers cannot go in a dll */
#ifndef YYBUILDDLL

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#include <cctype>
#else
#include <string.h>
#include <ctype.h>
#endif

#include "yylex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
void YYCDECL yydebugoutput(int ch)
#else
void YYCDECL yydebugoutput(ch)
int ch;
#endif
{
	char string[32];
	switch (ch) {
	case EOF:
		strcpy(string, "EOF");
		break;
	case '\n':
		strcpy(string, "\\n");
		break;
	case '\t':
		strcpy(string, "\\t");
		break;
	case '\v':
		strcpy(string, "\\v");
		break;
	case '\b':
		strcpy(string, "\\b");
		break;
	case '\r':
		strcpy(string, "\\r");
		break;
	case '\f':
		strcpy(string, "\\f");
		break;
	case '\a':
		strcpy(string, "\\a");
		break;
	case '\\':
		strcpy(string, "\\");
		break;
	case '\?':
		strcpy(string, "\\\?");
		break;
	case '\'':
		strcpy(string, "\\\'");
		break;
	case '\"':
		strcpy(string, "\\\"");
		break;
	default:
		if (!isascii(ch) || isascii(ch) && isprint(ch)) {
			string[0] = (char) ch;
			string[1] = '\0';
		}
		else {
			sprintf(string, "\\%03o", (unsigned int) (unsigned char) ch);
		}
		break;
	}
	yylexerdebugoutput(string);
}

#endif

_YL_END

#endif
