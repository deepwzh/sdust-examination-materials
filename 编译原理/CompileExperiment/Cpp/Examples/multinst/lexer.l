%{
/************************************************************
lexer.l
Lexical analyser for the multiple instance example. Note
that the lexical analyser now recognises illegal characters
on the input stream.
************************************************************/

/* multiple instance lex conversion file */
#include "milconv.h"
%}

%name calc_lexer		// give the lexical analyser a name

digit	[0-9]
exp		((e|E)("+"|"-")?{digit}+)

%%
%{
/*
This code goes at the top of our action routine. It allows
us to easily extract yylval for use later on in any
actions.
*/
YYSTYPE *yymlvalptr;
yymparser_t *parserptr = yy->yymparserptr;
yyassert(parserptr != NULL);
yymlvalptr = (YYSTYPE *) parserptr->yymlvalptr;
yyassert(yymlvalptr != NULL);
#define yylval (*yymlvalptr)
%}

{digit}+"."{digit}*{exp}?	|
"."{digit}+{exp}?			|
{digit}+{exp}?				{ sscanf(yytext, "%lf", &yylval); return NUMBER; }

"\n"						{ return '\n'; }
"+"							{ return '+'; }
"-"							{ return '-'; }
"*"							{ return '*'; }
"/"							{ return '/'; }
"("							{ return '('; }
")"							{ return ')'; }

[ \t]						{ /* white space */ }

.							{ printf("invalid character\n"); }
