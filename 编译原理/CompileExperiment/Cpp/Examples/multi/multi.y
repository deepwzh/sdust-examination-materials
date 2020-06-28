%{
/************************************************************
multi.y
This example demonstates how to generate multiple parsers
(and similarly lexical analysers). You will need to build
this example with the -mm option (The "Multiple Parser"
selection from the Model option in the AYACC Options dialog
box).

Instead of the parser variables, functions and tables being
defined separately they are grouped together in a structure.
This is defined in the header file "myacc.h". A variable of
this type is defined for the parser, and is given a name
using the %name keyword.

The yyerror() function calls in the parser actions are not
really meant for multiple parsers. The multiple version is
called yymerror() and takes two parameters. The first being
a pointer to the parser (structure) variable, and the
second the actual error text itself. You can however include
the file "myconv.h" which converts yyerror() to yymerror()
supplying the relevant parameters where necessary. The file
also provides a number of other function and variable
conversions. If you don't want any then simply undefine them
after the file has been included.

The yymgettoken() function provides the interface between
the parser and the lexical analyser. The default version of
yymgettoken() assumes that you are using a multiple style
lexical analyser. In which case you would assign the address
of the lexical analyser veriable to YYMPARSEDATA:

#define YYMPARSEDATA (void *) &mylexer

For more information on what is going on look at the
generated parser and/or lexical analyser files themselves.

The example is based on the basic calculator example. It
features floating point arithmetic using the addition,
subtraction, multiplication and divide operators, and unary
minus. Expressions can be grouped using parentheses, and
simple error recovery is supported.
************************************************************/

#include <ctype.h>
#include <stdio.h>
#define YYSTYPE double /* double type for YACC stack */

/* multiple yacc conversion file */
#include <myconv.h>

/* redefine the standard yymgettoken (although make it static) */
int yylex(void);

static int yymgettoken(yymparser_t *yy)
{
	return yylex();
}
%}

%name calc		// give the parser a name

%token NUMBER

%%
lines	: lines expr '\n'			{ printf("%g\n", $2); }
		| lines '\n'
		| /* e */
		| error '\n'				{ yyerror("reenter last line:"); yyerrok(); }
		;

expr	: expr '+' term				{ $$ = $1 + $3; }
		| expr '-' term				{ $$ = $1 - $3; }
		| term
		;

term	: term '*' factor			{ $$ = $1 * $3; }
		| term '/' factor			{ $$ = $1 / $3; }
		| factor
		;

factor	: '(' expr ')'				{ $$ = $2; }
		| '(' expr error			{ $$ = $2; yyerror("missing ')'"); yyerrok(); }
		| '-' factor				{ $$ = -$2; }
		| NUMBER
		;

%%
/* redefine main */
int main(void)
{
	int n = yymparse(&calc);
	return n;
}

int yylex(void)
{
	int c;
	while ((c = getchar()) == ' ');
	if (c == '.' || isdigit(c)) {
		ungetc(c, stdin);
		scanf("%lf", &yylval);
		return NUMBER;
	}
	return c;
}
