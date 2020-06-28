%{
/************************************************************
multinst.y
This example demonstates how to generate multiple instances
of parsers and lexical analysers. You will need to build
this example with the -mi option (The "Multiple Instance
Parser" selection from the Model option in the AYACC Options
dialog box).

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
the file "miyconv.h" which converts yyerror() to yymerror()
supplying the relevant parameters where necessary. The file
also provides a number of other function and variable
conversions. If you don't want any then simply undefine them
after the file has been included.

Local copies of the parser and lexical analyser are created
in the main function. These are then used to parse the input
stream before being destroyed. Note that there are two
additional assignments made, one to the created parser and
the other to the created lexical analyser. This is so that
the parser knows which lexical analyser to call, and
similarly so that the lexical analyser knows where to place
any yylval values.

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
#include <string.h>
#define YYSTYPE double /* double type for YACC stack */

/* multiple instance yacc conversion file */
#include <miyconv.h>
%}

%name calc_parser		// give the parser a name

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
/* include the lexical analyser */
#include "lexer.c"

/* redefine main */
int main(void)
{
	/* create our local parser and lexer */
	int n;
	yymparser_t parser;
	yymlexer_t lexer;
	yymcreateparser(&parser, &calc_parser);
	yymcreatelexer(&lexer, &calc_lexer);

	parser.yymlexerptr = &lexer;		/* parser points to correct lexer */
	lexer.yymparserptr = &parser;		/* lexer gets access to yylval */
	
	n = yymparse(&parser);				/* will allocate its own stacks */
	
	/* do some clean up */
	yymdestroyparser(&parser);
	yymdestroylexer(&lexer);

	return n;
}
