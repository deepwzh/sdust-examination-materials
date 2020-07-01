%{
/************************************************************
destruct.y
This example demonstrates the use of symbol destructors.
They are used for performing cleanup when the parser enters
error recovery and starts popping symbols off of the stack
and/or discarding lookahead tokens. Typically it is only
necessary to do this if memory has been allocated on the
heap and would overwise be lost. The example given here is
of a node tree which is first built and then evaluated,
before being discarded.

The example builds on the basic calculator example. It
features floating point arithmetic using the addition,
subtraction, multiplication and divide operators, and unary
minus. Expressions can be grouped using parentheses, and
simple error recovery is supported.

Note that this is not the way to write such a simple
calculator program, however it does demonstate what is
possible.
************************************************************/

#include <ctype.h>
#include <stdio.h>
#include <malloc.h>

/* node types */
enum {
	NT_LEAF,		/* leaf node */
	NT_INTERIOR,	/* interior node (has an associated operator */
};

/* interior node operations */
enum {
	OP_ADD,			/* addition */
	OP_SUBTRACT,	/* subtraction */
	OP_TIMES,		/* multiplication */
	OP_DIVIDE,		/* division */
	OP_UMINUS,		/* unary minus */
};

/* node */
typedef struct tagNODE {
	int type;						/* node type (either leaf or interior) */
	union {
		struct {
			double value;			/* leaf value */
		} leaf;
		struct {
			int operation;			/* operation */
			struct tagNODE *left;	/* left node */
			struct tagNODE *right;	/* right node (not needed for unary minus) */
		} interior;
	} u;
} NODE;

static NODE *newleafnode(double value)
{
	NODE *node = malloc(sizeof(NODE));
	node->type = NT_LEAF;
	node->u.leaf.value = value;
	return node;
}

static NODE *newinteriornode(int operation, NODE *left, NODE *right)
{
	NODE *node = malloc(sizeof(NODE));
	node->type = NT_INTERIOR;
	node->u.interior.operation = operation;
	node->u.interior.left = left;
	node->u.interior.right = right;
	return node;
}

static double evaluatetree(NODE *node)
{
	if (node->type == NT_LEAF) {
		return node->u.leaf.value;
	}
	else {
		switch (node->u.interior.operation) {
		case OP_ADD:
			return evaluatetree(node->u.interior.left) + evaluatetree(node->u.interior.right);
		case OP_SUBTRACT:
			return evaluatetree(node->u.interior.left) - evaluatetree(node->u.interior.right);
		case OP_TIMES:
			return evaluatetree(node->u.interior.left) * evaluatetree(node->u.interior.right);
		case OP_DIVIDE:
			return evaluatetree(node->u.interior.left) / evaluatetree(node->u.interior.right);
		default:
			return -evaluatetree(node->u.interior.left);
		}
	}
}

static void deletetree(NODE *node)
{
	if (node != NULL) {
		if (node->type == NT_INTERIOR) {
			deletetree(node->u.interior.left);
			deletetree(node->u.interior.right);
		}
		free(node);
	}
}

%}

%union {
	NODE *node;
	double value;
}

%type <node> lines expr term factor

%token <value> NUMBER

%%
lines	: lines expr '\n'			{ printf("%g\n", evaluatetree($2)); deletetree($2); }
		| lines '\n'
		| /* e */					{ /* do nothing */ }
		| error '\n'				{ yyerror("reenter last line:"); yyerrok(); }
		;

expr	: expr '+' term				{ $$ = newinteriornode(OP_ADD, $1, $3); }
		| expr '-' term				{ $$ = newinteriornode(OP_SUBTRACT, $1, $3); }
		| term
		;

term	: term '*' factor			{ $$ = newinteriornode(OP_TIMES, $1, $3); }
		| term '/' factor			{ $$ = newinteriornode(OP_DIVIDE, $1, $3); }
		| factor
		;

factor	: '(' expr ')'				{ $$ = $2; }
		| '(' expr error			{ $$ = $2; yyerror("missing ')'"); yyerrok(); }
		| '-' factor				{ $$ = newinteriornode(OP_UMINUS, $2, NULL); }
		| NUMBER					{ $$ = newleafnode($1); }
		;

/************************************************************
The symbol destructor itself. Whenever any of these symbols
are popped off of the stack during error recovery then this
action will be called. Note that the missing right
parenthesis error ')' will never pop any symbols off of the
stack.

It is not necessary to specify a symbol destructor for
"lines". This is because it never actually holds a pointer
to a node itself. However it must be typed so a "node" type
is as good as anything else. You could for arguments sake
define it as being of type "value", or create a new type
altogether.

Because expr, term and factor are of the same type, it is
possible to combine them in the same symbol destructor. If
one of them had a different type then it would have to go in
a separate destructor.

For embedded actions (which generate an invisible
nonterminal) do the following:

A: { ... } ~{ ... } B  C
   $1      <skip>   $2 $3
   
Note that embedded action symbol destructors are ignored for
the purposes of counting the attribute number.
************************************************************/

~expr | ~term | ~factor : { printf("deleting node\n"); deletetree($$); } ;

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
