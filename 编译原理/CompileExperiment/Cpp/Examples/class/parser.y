%{
/****************************************************************************
parser.y
Parser for a simple calculator. The parser is implemented using a C++ class.
This is specified by selecting the -Tcpp option in AYACC (the "C++"
selection from the Target Language combo box in the AYACC Options dialog
box).

The parser implements the usual floating point arithmetic using the
addition, subtraction, multiplication and division operators, and unary
minus. Expressions can be grouped and simple error recovery is supported. In
addition it is now posssible to assign values to variables, and to use such
values in expressions.
****************************************************************************/

#include <math.h>
%}

// include file
%include {
// forward references
class symbol;
}

// attribute type
%union {
	symbol* symbol;
	double value;
}

// nonterminals
%type <value> expr

// tokens
%right '='
%left '+', '-'
%left '*', '/'
%right UMINUS

%token <value> NUMBER
%token <symbol> ID

// keywords
%token SIN
%token COS
%token TAN

// include file
%include {
#include "symbol.h"
#include "lexer.h"
}

// parser name
%name calc_parser

// class definition
{
// Attributes
protected:
	symboltable m_symboltable;		// the symbol table
	calc_lexer m_lexer;				// the lexical analyser
	
// Operations
public:
	int create();
	
	// attribute commands
	double assign(symbol* id, double value);
	double divide(double dividend, double divisor);
}

// constructor
{
	// do nothing
}

%%
lines
	: lines line
	| /* empty */
	;

line
	: expr '\n'					{ printf("%g\n", (double)$1); }
	| error '\n'				{ yyerrok(); }
	;

expr
	: ID '=' expr				{ $$ = assign($1, $3); }
	| expr '+' expr				{ $$ = $1 + $3; }
	| expr '-' expr				{ $$ = $1 - $3; }
	| expr '*' expr				{ $$ = $1 * $3; }
	| expr '/' expr				{ $$ = divide($1, $3); }
	| '(' expr ')'				{ $$ = $2; }
	| '-' expr %prec UMINUS		{ $$ = -$2; }
	| NUMBER					{ $$ = $1; }
	| ID						{ $$ = $1->m_value; }
	| SIN '(' expr ')'			{ $$ = sin($3); }
	| COS '(' expr ')'			{ $$ = cos($3); }
	| TAN '(' expr ')'			{ $$ = tan($3); }
	;

%%

/////////////////////////////////////////////////////////////////////////////
// main

int main(void)
{
	int n = YYEXIT_FAILURE;
	
	calc_parser parser;
	if (parser.create()) {
		n = parser.yyparse();
	}
	return n;
}

/////////////////////////////////////////////////////////////////////////////
// calc_parser commands

int calc_parser::create()
{
	if (!yycreate(&m_lexer)) {
		return 0;
	}
	if (!m_lexer.create(this, &m_symboltable)) {
		return 0;
	}
	return 1;	// success
}

/////////////////////////////////////////////////////////////////////////////
// calc_parser attribute commands

double calc_parser::assign(symbol* id, double value)
{
	assert(id != NULL);

	id->m_value = value;
	return id->m_value;
}

double calc_parser::divide(double a, double b)
{
	if (b == 0) {
		printf("division by zero\n");
		yythrowerror();		// causes a syntax error
		return 0;
	}
	else {
		return a / b;
	}
}
