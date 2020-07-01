#ifndef YYCPARS_H
#define YYCPARS_H

/************************************************************
yycpars.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

// globals
#include <yyglobal.h>

// standard include files
#ifdef YYSTDCPPLIB
#include <iostream>
#include <cstdio>
#include <cstddef>
#else
#include <stdio.h>
#include <stddef.h>
#endif

// defines
#include <yytdefs.h>

// user defines
#if defined(YYTUDEFS) || defined(YYUDEFS)
#include <yytudefs.h>
#endif

#ifndef YYSTD
#ifdef YYSTDCPPLIB
#define YYSTD std::
#else
#define YYSTD
#endif
#endif

#ifndef YYCSTD
#ifdef YYCSTDCPPLIB
#define YYCSTD std::
#else
#define YYCSTD
#endif
#endif

// namespace
#ifdef YYNAMESPACE
#ifndef _YL_NAME
#define _YL_NAME	yl
#endif
#ifndef _YL
#define _YL			yl::
#endif
#ifndef _YL_BEGIN
#define _YL_BEGIN	namespace yl {
#endif
#ifndef _YL_END
#define _YL_END		}
#endif
#else
#ifndef _YL_NAME
#define _YL_NAME
#endif
#ifndef _YL
#define _YL
#endif
#ifndef _YL_BEGIN
#define _YL_BEGIN
#endif
#ifndef _YL_END
#define _YL_END
#endif
#endif

_YL_BEGIN

#define YY_AYACC

// modifiers
#ifndef YYEXPCLASS
#define YYEXPCLASS
#endif
#ifndef YYEXPDATA
#define YYEXPDATA(x) x
#endif
#ifndef YYEXPFUNC
#define YYEXPFUNC(x) x
#endif
#ifndef YYCDECL
#define YYCDECL
#endif
#ifndef YYDCDECL
#define YYDCDECL
#endif
#ifndef YYNEAR
#define YYNEAR
#endif
#ifndef YYFAR
#define YYFAR
#endif
#ifndef YYNEARFAR
#define YYNEARFAR
#endif
#ifndef YYBASED_CODE
#define YYBASED_CODE
#endif

// forward references
class YYEXPCLASS YYFAR yylexer;

typedef short yystack_t;

// yyparse return values
#define YYEXIT_SUCCESS	0
#define YYEXIT_FAILURE	1

// common tokens
#define YYTK_ALL		(-1)		// match all tokens
#define YYTK_END		0			// $end token
#define YYTK_ERROR		256			// error token

typedef short yycstategoto_t;

#ifndef YYCNONTERMGOTO_T
#define YYCNONTERMGOTO_T
typedef struct yycnontermgoto {
	short yynonterm;				// nonterminal
	short yynext;					// next state
} yycnontermgoto_t;
#endif

#ifndef YYSTATEGOTO_T
#define YYSTATEGOTO_T
typedef struct yystategoto {
	short yybase;					// base
	short yydef;					// default state
} yystategoto_t;
#endif

#ifndef YYNONTERMGOTO_T
#define YYNONTERMGOTO_T
typedef struct yynontermgoto {
	short yycheck;					// check
	short yynext;					// next state
} yynontermgoto_t;
#endif

// action types
#define YYAT_SHIFT		0			// shift action
#define YYAT_REDUCE		1			// reduce action
#define YYAT_ERROR		2			// error
#define YYAT_ACCEPT		3			// accept
#define YYAT_DEFAULT	4			// default state

typedef short yycstateaction_t;

#ifndef YYCTOKENACTION_T
#define YYCTOKENACTION_T
typedef struct yyctokenaction {
	int yytoken;					// lookahead token
	unsigned char yytype;			// action to perform
	short yysr;						// state to shift/production to reduce
} yyctokenaction_t;
#endif

#ifndef YYSTATEACTION_T
#define YYSTATEACTION_T
typedef struct yystateaction {
	short yybase;					// base
	unsigned char yylookahead;		// lookahead needed
	unsigned char yytype;			// action to perform
	short yysr;						// shift/reduce
} yystateaction_t;
#endif

#ifndef YYTOKENACTION_T
#define YYTOKENACTION_T
typedef struct yytokenaction {
	short yycheck;					// check
	unsigned char yytype;			// action type
	short yysr;						// shift/reduce
} yytokenaction_t;
#endif

// nonterminals
#define YYNT_ALL		(-1)		// match all nonterminals

// states
#define YYST_ERROR		(-1)		// goto error

#ifndef YYREDUCTION_T
#define YYREDUCTION_T
typedef struct yyreduction {
	short yynonterm;				// the rhs symbol
	short yylength;					// number of symbols on lhs
	short yyaction;					// the user action
} yyreduction_t;
#endif

typedef short yydestructor_t;

#ifndef YYTOKENDEST_T
#define YYTOKENDEST_T
typedef struct yytokendest {
	short yycheck;
	short yyaction;
} yytokendest_t;
#endif

typedef short yytokendestbase_t;

#ifndef YYCTOKENDEST_T
#define YYCTOKENDEST_T
typedef struct yyctokendest {
	int yytoken;					// token
	short yyaction;					// the user action
} yyctokendest_t;
#endif

// debugging
#ifdef YYDEBUG
#ifndef YYSYMBOL_T
#define YYSYMBOL_T
typedef struct yysymbol {
	const char* yyname;				// symbol name
	int yytoken;					// symbol token
} yysymbol_t;
#endif
#endif

class YYEXPCLASS YYFAR yyparser {
public:
	yyparser();
	virtual ~yyparser();

// Attributes
protected:
	// stack
	yystack_t YYFAR* yystackptr;		// (state) stack
	yystack_t YYFAR* yysstackptr;		// static (state) stack
	void YYFAR* yyattributestackptr;	// attribute stack
	void YYFAR* yysattributestackptr;	// static attribute stack
	int yystack_size;					// number of elements in stack
	int yysstack_size;					// initial number of elements in stack
	int yystack_max;					// maximum size of stack

	int yytop;							// the current top of the stack
	size_t yyattribute_size;			// size of attribute

	void YYFAR* yyvalptr;				// attribute for $$

	// lookahead token
	yybool yylookahead;					// whether current lookahead token is valid
	int yychar;							// current lookahead token

	// error recovery
	yybool yywipeflg;					// whether to "wipe" stack on abort
	yybool yypopflg;					// popping symbols during error recovery
	int yyskip;							// error recovery token shift counter

	// actions
	yybool yyexitflg;					// whether yyexit called
	yybool yyretireflg;					// whether yyretire called
	yybool yyerrorflg;					// whether yythrowerror called
	int yyexitcode;						// yymexit exit code
	int yyretirecode;					// yymretire exit code
	int yyerrorpop;						// how many error transitions to pop
public:
	yylexer YYFAR* yylexerptr;			// pointer to the attached lexical analyser

	yybool yystackgrow;					// whether stack can grow
	void YYFAR* yylvalptr;				// current token attribute
#ifdef YYSTDCPPLIB
	YYSTD ostream YYFAR* yyerr;			// error output file
#else
	YYCSTD FILE YYFAR* yyerr;			// error output file
#endif
	int yyerrorcount;					// how many syntax errors have occurred

// Operations
protected:
	virtual void yyaction(int action) = 0;

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

	// helper functions
#ifdef YYDEBUG
	void yypop(int num);
	void yysetskip(int skip);
#else
	void yypop(int num) { yytop -= num; }
	void yysetskip(int skip) { yyskip = skip; }
#endif
	yybool yypush(yystack_t state);
	yystack_t yypeek() const { return yystackptr[yytop]; }

public:
	// instance functions
	yybool yycreate(yylexer YYFAR* lexerptr = NULL);
	void yydestroy();

	// general functions
	void yydestructpop(int num);
	int yyparse();
	void yycleanup();
	yybool yysetstacksize(int size);
	int yysetup();
	void yywipe();
	virtual int yywork() = 0;
	virtual void yydestructclearin() = 0;

	// service functions
	virtual int yygettoken();
	virtual void yydiscard(int token);
	virtual void yysyntaxerror();
	virtual void yystackoverflow();
	virtual void yyerror(const char YYFAR* text);

	// action functions
	void yysetin(int token);
	yybool yyunclearin();
	void yyabort() { yyexit(1); }
	void yyaccept() { yyexit(0); }
#ifndef YY_COMPATIBLE
	void yyclearin() { yylookahead = yyfalse; }
	void yyerrok() { yysetskip(0); }
#else
	void _yyclearin() { yylookahead = yyfalse; }
	void _yyerrok() { yysetskip(0); }
#endif
	void yyexit(int exitcode) { yyexitflg = yytrue; yyexitcode = exitcode; }
	void yyforceerror() { yythrowerror(); }
	yybool yypopping() const { return yypopflg; }
	yybool yyrecovering() const { return yyskip > 0; }
	void yyretire(int retirecode) { yyretireflg = yytrue; yyretirecode = retirecode; }
	void yythrowerror(int pop = 0) { yyerrorflg = yytrue; yyerrorpop = pop; }

	// compatibility
	int yycparse() { return yyparse(); }
	int yycwork() { return yywork(); }
	void yyparsecleanup() { yycleanup(); }
	void yyparseinit() { /* do nothing */ }
	void yycleanupparser() { yycleanup(); }
	void yyinitparser() { /* do nothing */ }
#ifdef YY_COMPATIBLE
#define yyclearin _yyclearin()
#define yyerrok _yyerrok()
#endif
#define YYABORT yyexit(1)
#define YYACCEPT yyexit(0)
#define YYERROR yythrowerror()
#define YYRECOVERING yyrecovering()

// Tables
protected:
	const yyreduction_t YYNEARFAR* yyreduction;
	const yydestructor_t YYNEARFAR* yydestructorptr;

// Debugging
#ifdef YYDEBUG
public:
	yybool yydebug;						// whether debug information should be output
	yybool yydebugstack;				// whether stack debug information should be output
	yybool yydebugflush;				// whether debug output should be flushed
#ifdef YYSTDCPPLIB
	YYSTD ostream YYFAR* yydebugout;	// debug output file
#else
	YYCSTD FILE YYFAR* yydebugout;		// debug output file
#endif
protected:
	const yysymbol_t YYNEARFAR* yysymbol;
	const char* const YYNEARFAR* yyrule;

	// debugging functions
protected:
	const char* yytokenstring(int token) const;
	void yydgettoken(int token) const;
	void yydshift(int token) const;
	void yydreduce(int rule) const;
	void yydsyntaxerror() const;
	void yydaccept() const;
	void yydabort() const;
	void yyddiscard(int token) const;
	void yydexit(int exitcode) const;
	void yydthrowerror(int errorpop) const;
	void yydretire(int retirecode) const;
	void yydattemptrecovery() const;
	void yydebugoutput(const char YYFAR* string) const;
#endif
};

class YYEXPCLASS YYFAR yyfparser : public yyparser {
public:
	yyfparser() { /* do nothing */ }

// Operations
public:
	virtual int yywork();
	virtual void yydestructclearin();

// Tables
protected:
	const yystateaction_t YYNEARFAR* yystateaction;
	const yytokenaction_t YYNEARFAR* yytokenaction;
	int yytokenaction_size;
	const yystategoto_t YYNEARFAR* yystategoto;
	const yynontermgoto_t YYNEARFAR* yynontermgoto;
	int yynontermgoto_size;
	const yytokendest_t YYNEARFAR* yytokendestptr;
	int yytokendest_size;
	const yytokendestbase_t YYNEARFAR* yytokendestbaseptr;
	int yytokendestbase_size;
};

class YYEXPCLASS YYFAR yycparser : public yyparser {
public:
	yycparser() { /* do nothing */ }

// Operations
public:
	virtual int yywork();
	virtual void yydestructclearin();

// Tables
protected:
	const yycstateaction_t YYNEARFAR* yycstateaction;
	const yyctokenaction_t YYNEARFAR* yyctokenaction;
	const yycstategoto_t YYNEARFAR* yycstategoto;
	const yycnontermgoto_t YYNEARFAR* yycnontermgoto;
	const yyctokendest_t YYNEARFAR* yyctokendestptr;
};

_YL_END

// user defines
#if defined(YYBUDEFS) || defined(YYUDEFS)
#include <yybudefs.h>
#endif

// defines
#include <yybdefs.h>

#endif
