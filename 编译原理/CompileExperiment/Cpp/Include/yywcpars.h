#ifndef YYWCPARS_H
#define YYWCPARS_H

/************************************************************
yywcpars.h
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
class YYEXPCLASS YYFAR yywlexer;

#ifndef YYWINT_T
#define YYWINT_T
#ifdef YYWIN32
typedef int yywint_t;
#else
typedef long yywint_t;
#endif
#endif

typedef short yywstack_t;

// yyparse return values
#define YYEXIT_SUCCESS	0
#define YYEXIT_FAILURE	1

// common tokens
#define YYWTK_ALL		(-1)		// match all tokens
#define YYWTK_END		0			// $end token
#define YYWTK_ERROR		65536		// (wide) error token

typedef short yywcstategoto_t;

#ifndef YYWCNONTERMGOTO_T
#define YYWCNONTERMGOTO_T
typedef struct yywcnontermgoto {
	short yynonterm;				// nonterminal
	short yynext;					// next state
} yywcnontermgoto_t;
#endif

#ifndef YYWSTATEGOTO_T
#define YYWSTATEGOTO_T
typedef struct yywstategoto {
	short yybase;					// base
	short yydef;					// default state
} yywstategoto_t;
#endif

#ifndef YYWNONTERMGOTO_T
#define YYWNONTERMGOTO_T
typedef struct yywnontermgoto {
	short yycheck;					// check
	short yynext;					// next state
} yywnontermgoto_t;
#endif

// action types
#define YYAT_SHIFT		0			// shift action
#define YYAT_REDUCE		1			// reduce action
#define YYAT_ERROR		2			// error
#define YYAT_ACCEPT		3			// accept
#define YYAT_DEFAULT	4			// default state

typedef short yywcstateaction_t;

#ifndef YYWCTOKENACTION_T
#define YYWCTOKENACTION_T
typedef struct yywctokenaction {
	yywint_t yytoken;				// lookahead token
	unsigned char yytype;			// action to perform
	short yysr;						// state to shift/production to reduce
} yywctokenaction_t;
#endif

#ifndef YYWSTATEACTION_T
#define YYWSTATEACTION_T
typedef struct yywstateaction {
	long yybase;					// base
	unsigned char yylookahead;		// lookahead needed
	unsigned char yytype;			// action to perform
	short yysr;						// shift/reduce
} yywstateaction_t;
#endif

#ifndef YYWTOKENACTION_T
#define YYWTOKENACTION_T
typedef struct yywtokenaction {
	short yycheck;					// check
	unsigned char yytype;			// action type
	short yysr;						// shift/reduce
} yywtokenaction_t;
#endif

// nonterminals
#define YYNT_ALL		(-1)		// match all nonterminals

// states
#define YYST_ERROR		(-1)		// goto error

#ifndef YYWREDUCTION_T
#define YYWREDUCTION_T
typedef struct yywreduction {
	short yynonterm;				// the rhs symbol
	short yylength;					// number of symbols on lhs
	short yyaction;					// the user action
} yywreduction_t;
#endif

typedef short yywdestructor_t;

#ifndef YYWTOKENDEST_T
#define YYWTOKENDEST_T
typedef struct yywtokendest {
	short yycheck;					// check
	short yyaction;					// action
} yywtokendest_t;
#endif

typedef long yywtokendestbase_t;

#ifndef YYWCTOKENDEST_T
#define YYWCTOKENDEST_T
typedef struct yywctokendest {
	yywint_t yytoken;				// token
	short yyaction;					// the user action
} yywctokendest_t;
#endif

// debugging
#ifdef YYDEBUG
#ifndef YYWSYMBOL_T
#define YYWSYMBOL_T
typedef struct yywsymbol {
	const wchar_t* yyname;			// symbol name
	yywint_t yytoken;				// symbol token
} yywsymbol_t;
#endif
#endif

class YYEXPCLASS YYFAR yywparser {
public:
	yywparser();
	virtual ~yywparser();

// Attributes
protected:
	// stack
	yywstack_t YYFAR* yystackptr;		// (state) stack
	yywstack_t YYFAR* yysstackptr;		// static (state) stack
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
	yywint_t yychar;					// current lookahead token

	// error recovery
	yybool yywipeflg;					// whether to "wipe" stack on abort
	yybool yypopflg;					// popping symbols during error recovery
	int yyskip;							// error recovery token shift counter

	// actions
	yybool yyexitflg;					// whether yymexit called
	yybool yyretireflg;					// whether yymretire called
	yybool yyerrorflg;					// whether yymthrowerror called
	int yyexitcode;						// yymexit exit code
	int yyretirecode;					// yymretire exit code
	int yyerrorpop;						// how many error transitions to pop
public:
	yywlexer YYFAR* yylexerptr;			// pointer to the attached lexical analyser

	yybool yystackgrow;					// whether stack can grow
	void YYFAR* yylvalptr;				// current token attribute
#ifdef YYSTDCPPLIB
	YYSTD wostream YYFAR* yyerr;		// error output file
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
	yybool yypush(yywstack_t state);
	yywstack_t yypeek() const { return yystackptr[yytop]; }

public:
	// instance functions
	yybool yycreate(yywlexer YYFAR* lexerptr = NULL);
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
	virtual yywint_t yygettoken();
	virtual void yydiscard(yywint_t token);
	virtual void yysyntaxerror();
	virtual void yystackoverflow();
	virtual void yyerror(const wchar_t YYFAR* text);

	// action functions
	void yysetin(yywint_t token);
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
	const yywreduction_t YYNEARFAR* yyreduction;
	const yywdestructor_t YYNEARFAR* yydestructorptr;

// Debugging
#ifdef YYDEBUG
public:
	yybool yydebug;						// whether debug information should be output
	yybool yydebugstack;				// whether stack debug information should be output
	yybool yydebugflush;				// whether debug output should be flushed
#ifdef YYSTDCPPLIB
	YYSTD wostream YYFAR* yydebugout;	// debug output file
#else
	YYCSTD FILE YYFAR* yydebugout;		// debug output file
#endif
protected:
	const yywsymbol_t YYNEARFAR* yysymbol;
	const wchar_t* const YYNEARFAR* yyrule;

	// debugging functions
protected:
	const wchar_t* yytokenstring(yywint_t token) const;
	void yydgettoken(yywint_t token) const;
	void yydshift(yywint_t token) const;
	void yydreduce(int rule) const;
	void yydsyntaxerror() const;
	void yydaccept() const;
	void yydabort() const;
	void yyddiscard(yywint_t token) const;
	void yydexit(int exitcode) const;
	void yydthrowerror(int errorpop) const;
	void yydretire(int retirecode) const;
	void yydattemptrecovery() const;
	void yydebugoutput(const wchar_t YYFAR* string) const;
#endif
};

class YYEXPCLASS YYFAR yywfparser : public yywparser {
public:
	yywfparser() { /* do nothing */ }

// Operations
public:
	virtual int yywork();
	virtual void yydestructclearin();

// Tables
protected:
	const yywstateaction_t YYNEARFAR* yystateaction;
	const yywtokenaction_t YYNEARFAR* yytokenaction;
	long yytokenaction_size;
	const yywstategoto_t YYNEARFAR* yystategoto;
	const yywnontermgoto_t YYNEARFAR* yynontermgoto;
	int yynontermgoto_size;
	const yywtokendest_t YYNEARFAR* yytokendestptr;
	long yytokendest_size;
	const yywtokendestbase_t YYNEARFAR* yytokendestbaseptr;
	int yytokendestbase_size;
};

class YYEXPCLASS YYFAR yywcparser : public yywparser {
public:
	yywcparser() { /* do nothing */ }

// Operations
public:
	virtual int yywork();
	virtual void yydestructclearin();

// Tables
protected:
	const yywcstateaction_t YYNEARFAR* yycstateaction;
	const yywctokenaction_t YYNEARFAR* yyctokenaction;
	const yywcstategoto_t YYNEARFAR* yycstategoto;
	const yywcnontermgoto_t YYNEARFAR* yycnontermgoto;
	const yywctokendest_t YYNEARFAR* yyctokendestptr;
};

_YL_END

// user defines
#if defined(YYBUDEFS) || defined(YYUDEFS)
#include <yybudefs.h>
#endif

// defines
#include <yybdefs.h>

#endif
