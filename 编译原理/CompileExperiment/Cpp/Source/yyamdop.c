/************************************************************
yyamdop.c
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
#include <cstring>
#include <cctype>
#else
#include <string.h>
#include <ctype.h>
#endif

#include "yymlex.h"

#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif

_YL_BEGIN

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
YYEXPFUNC(void) YYCDECL yymdebugoutput(yymlexer_t YYFAR *yy, int ch)
#else
YYEXPFUNC(void) YYCDECL yymdebugoutput(yy, ch)
yymlexer_t YYFAR *yy;
int ch;
#endif
{
	char string[32];
	yyassert(yy != NULL);

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
	yymlexerdebugoutput(yy, string);
}

#endif

_YL_END
