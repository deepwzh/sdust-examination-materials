%{
/****************************************************************************
lexer.l
Lexical analyser for a simple calculator. The lexical analyser is
implemented using a C++ class. This is specified by selecting the -Tcpp
option in ALex (the "C++" selection from the Target Language combo box in
the ALex Options dialog box).
****************************************************************************/

#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "parser.h"
%}

// include file
%include {
// forward references
class calc_parser;
class symboltable;
}

// lexical analyser name
%name calc_lexer

// class definition
{
// Attributes
protected:
	symboltable* m_symboltable;		// the symbol table

// Operations
public:
	int create(calc_parser* parser, symboltable* symboltable);
	
	// attribute commands
	double number() const;
	symbol* id() const;
}

// constructor
{
	// do nothing
}

// macros
exponent	([Ee][+-]?[0-9]+)

%%

%{
// extract yylval for use later on in actions
YYSTYPE& yylval = *(YYSTYPE*)yyparserptr->yylvalptr;
%}

// number
[0-9]+"."[0-9]*{exponent}?	|
"."[0-9]+{exponent}?		|
[0-9]+{exponent}?			{ yylval.value = number(); return NUMBER; }

// keywords
"sin"						{ return SIN; }
"cos"						{ return COS; }
"tan"						{ return TAN; }

// id
[a-zA-Z_][a-zA-Z0-9_]*		{ yylval.symbol = id(); return ID; }

// operators
"="							{ return '='; }
"+"							{ return '+'; }
"-"							{ return '-'; }
"*"							{ return '*'; }
"/"							{ return '/'; }
"("							{ return '('; }
")"							{ return ')'; }

// white space
[ \t]						{ /* do nothing */ }
\n							{ return '\n'; }

.							{ printf("invalid character '0x%02x'\n", (unsigned int)yytext[0]); }

%%

/////////////////////////////////////////////////////////////////////////////
// calc_lexer commands

int calc_lexer::create(calc_parser* parser, symboltable* symboltable)
{
	assert(parser != NULL);
	assert(symboltable != NULL);
	
	m_symboltable = symboltable;
	return yycreate(parser);
}

/////////////////////////////////////////////////////////////////////////////
// calc_lexer attribute commands

double calc_lexer::number() const
{
	errno = 0;		// clear error flag
	char* endp;
	double d = strtod(yytext, &endp);
	if ((d == +HUGE_VAL || d == -HUGE_VAL) && errno == ERANGE) {
		printf("number too big\n");
	}
	return d;
}

symbol* calc_lexer::id() const
{
	symbol* p = m_symboltable->install(yytext);
	return p;
}
