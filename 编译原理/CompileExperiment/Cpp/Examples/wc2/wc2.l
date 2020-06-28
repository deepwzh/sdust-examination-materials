%{
/************************************************************
wc2.l
This program uses start states for counting words. Instead
of matching the entire word, the program looks for a
starting letter. When one is found the lexical analyser
enters a special WORD start state. It then stays in this
start state until a non-letter is encountered.

Note that there is at most one character stored in yytext
at any one time. Since the default size of the buffer is 100
characters, this means that it will never need to grow. In
fact it would be possible to redefine the size of the buffer
as:

#define YYTEXT_SIZE 1

Finally, main is defined in the programs section since the
one in the library calls yyparse instead. 
************************************************************/

int wc = 0;		/* word count */
%}

%start WORD		// the word start state

%%
// this is for when we are inside a word (they need to go first)
<WORD>[a-zA-Z]	{ /* gobble up */ }
<WORD>.|\n		{ yybegin(0); }

// this is for when we are outside word
[a-zA-Z]		{ wc++; yybegin(WORD); }
.|\n			{ /* gobble up */ }

%%
int main(void)
{
	return yylex();
}

int yywrap(void)
{
	printf("word count: %d\n", wc);
	return 1;
}
