%{
/************************************************************
prec.y
Simple calculator. Features floating point arithmetic using
the addition, subtraction, multiplication and divide
operators, and unary minus. Expressions can be grouped
using parentheses, and simple error recovery is supported.

This version is implemented using the %left, %right and
%prec keywords. This results in a faster, smaller parser,
but the grammar is not so clean or obvious.
************************************************************/

#include <ctype.h>
#include <stdio.h>
#define YYSTYPE double /* double type for YACC stack */
%}

%token NUMBER		// no precedence or associativity

/************************************************************
This is where we define the precedence and associativity for
each of the operators. The operators listed first have the
lowest precedence. Those listed last, the highest
precedence. Associativity is either left or right. In most
cases boolean operators are left associative.

The token UMINUS is not an actual token. It is rather a
pseudo token that is used to distinguish between the
subtraction operator and the unary minus operator. It is
used with the %prec keyword (see below).
************************************************************/

%left '+', '-'		// lowest precedence
%left '*', '/'
%right UMINUS		// highest precedence

%%
lines	: lines expr '\n'			{ printf("%g\n", $2); }
		| lines '\n'
		| /* e */
		| error '\n'				{ yyerror("reenter last line:"); yyerrok(); }
		;

expr	: expr '+' expr				{ $$ = $1 + $3; }
		| expr '-' expr				{ $$ = $1 - $3; }
		| expr '*' expr				{ $$ = $1 * $3; }
		| expr '/' expr				{ $$ = $1 / $3; }
		| '(' expr ')'				{ $$ = $2; }
		| '(' expr error			{ $$ = $2; if (yypopping()) { yythrowerror(1); }
										else { yyerror("missing ')'"); yyerrok(); } }
		| '-' expr %prec UMINUS		{ $$ = -$2; }
		| NUMBER
		;

/************************************************************
Note the use of the %prec keyword above. What it does is
temporarily assign the associativity and precedence of
the UMINUS token to the first token in the production. In
this case, this will be the '-' token. Please note though
that tokens are different from nonterminal symbols. The
unary minus operator now has a higher precedence than
multiplication and division, and subsequently addition and
subtraction.

An example will best clarify the results of both having and
not having %prec in the grammar. If the string "-8*9" is
input then it will be evaluated as:

with %prec:    ((-(8))*(9)) or (-8)*9
without %prec: (-((8)*(9))) or -(8*9)

The first (with %prec) is the one we mean when we say "-8*9".
It is interesting to note though that in this particular
example both (-8)*9 and -(8*9) evaluate to -72.
************************************************************/

%%
int main(void)
{
	return yyparse();
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
