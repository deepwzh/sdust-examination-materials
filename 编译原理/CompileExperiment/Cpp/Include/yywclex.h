#ifndef YYWCLEX_H
#define YYWCLEX_H

/************************************************************
yywclex.h
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
#else
#include <stdio.h>
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

#define YY_ALEX

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
class YYEXPCLASS YYFAR yywparser;

// yylex return values
#define YYEOF 0			// end of file

#ifndef YYWSTATE_T
#define YYWSTATE_T
typedef struct yywstate {
	short yydef;		// default state
	long yybase;		// base
	short yymatch;		// action associated with state
} yywstate_t;
#endif

#ifndef YYWTRANSITION_T
#define YYWTRANSITION_T
typedef struct yywtransition {
	short yynext;		// next state on transition
	short yycheck;		// check
} yywtransition_t;
#endif

#ifndef YYWCTRANSITION_T
#define YYWCTRANSITION_T
typedef struct yywctransition {
	wchar_t yyfirst;		// first character in range
	wchar_t yylast;			// last character in range
	short yynext;			// next state on transition
} yywctransition_t;
#endif

#ifndef YYWINT_T
#define YYWINT_T
#ifdef YYWIN32
typedef int yywint_t;
#else
typedef long yywint_t;
#endif
#endif

typedef short yywmatch_t;
typedef unsigned char yywbackup_t;

class YYEXPCLASS YYFAR yywlexer {
public:
	yywlexer();
	virtual ~yywlexer();

// Attributes
protected:
	// left context
	int yystart;					// current start state
	yybool yyeol;					// whether an end-of-line '\n' has been seen
	yybool yyoldeol;				// previous end-of-line value

	// text buffer
	int YYFAR* yystatebuf;			// state buffer
	int YYFAR* yysstatebuf;			// initial (static) state buffer
	wchar_t YYFAR* yystext;			// initial (static) text buffer
	int yytext_size;				// text buffer size
	int yystext_size;				// initial (static) text buffer size
	int yytext_max;					// maximum size of the text buffer

	// unput buffer
	yywint_t YYFAR* yyunputbufptr;	// unput buffer
	yywint_t YYFAR* yysunputbufptr;	// initial (static) unput buffer
	int yyunput_size;				// unput buffer size
	int yysunput_size;				// initial (static) unput buffer size
	int yyunputindex;				// unput buffer position
	int yyunput_max;				// maximum size of the unput buffer

	// actions
	yybool yymoreflg;				// concatenate matched strings
	yybool yyrejectflg;				// yyreject called from an action
	yybool yyreturnflg;				// return from an action
public:
	yywparser YYFAR* yyparserptr;	// pointer to the attached parser

	// buffer flags
	yybool yytextgrow;				// whether text buffer is allowed to grow
	yybool yyunputgrow;				// whether unput buffer is allowed to grow

	// streams
#ifdef YYSTDCPPLIB
	YYSTD wistream YYFAR* yyin;		// input text stream
	YYSTD wostream YYFAR* yyout;	// output text stream
	YYSTD wostream YYFAR* yyerr;	// error stream
#else
	YYCSTD FILE YYFAR* yyin;		// input text stream
	YYCSTD FILE YYFAR* yyout;		// output text stream
	YYCSTD FILE YYFAR* yyerr;		// error stream
#endif

	// matched string
	wchar_t YYFAR* yytext;			// text buffer
	int yyleng;						// matched string length
	int yylineno;					// current line number

// Operations
protected:
	// helper functions
	static yybool yyback(const yywmatch_t YYNEARFAR* p, int action);
public:
	// instance functions
	yybool yycreate(yywparser YYFAR* parserptr = NULL);
	void yydestroy();

	// general functions
	void yycleanup();
	virtual yywint_t yylex() = 0;
	void yyreset();
	yybool yysettextsize(int size);
	yybool yysetunputsize(int size);

	// service functions
	virtual yywint_t yygetchar();
	virtual yywint_t yyinput();
	virtual void yyoutput(yywint_t ch);
	virtual void yyunput(yywint_t ch);
	virtual int yywrap();
	virtual void yytextoverflow();
	virtual void yyunputoverflow();
	virtual void yyerror(const wchar_t YYFAR* text);
	virtual yywint_t yyaction(int action) = 0;

	// action functions
	void yyecho();
	void yyless(int length);
	void yybegin(int state) { yystart = state; }
	void yymore() { yymoreflg = yytrue; }
	void yynewline(yybool newline) { newline ? yyeol = yytrue : (yyeol = yyfalse); }
	void yyreject() { yyrejectflg = yytrue; }
	int yyunputcount() const { return yyunputindex; }

	// compatibility
	yywint_t yyclex() { return yylex(); }
	void yylexcleanup() { yycleanup(); }
	void yylexinit() { /* do nothing */ }
	void yycleanuplexer() { yycleanup(); }
	void yyinitlexer() { /* do nothing */ }
#define BEGIN yystart = 
#define ECHO yyecho()
#define REJECT yyreject()
#define YYSTATE yystart
#define YY_START yystart

// Tables
protected:
	const yywmatch_t YYNEARFAR* yymatch;
	const yywstate_t YYNEARFAR* yystate;
	const yywbackup_t YYNEARFAR* yybackup;

// Debugging
#ifdef YYDEBUG
public:
	yybool yydebug;						// whether debug information should be output
	yybool yydebugflush;				// whether debug output should be flushed
#ifdef YYSTDCPPLIB
	YYSTD wostream YYFAR* yydebugout;	// debug output file
#else
	YYCSTD FILE YYFAR* yydebugout;		// debug output file
#endif
protected:
	void yydebugoutput(yywint_t ch) const;
	void yydmatch(int expr) const;
	void yydebugoutput(const wchar_t YYFAR* string) const;
#endif
};

class YYEXPCLASS YYFAR yywflexer : public yywlexer {
public:
	yywflexer() { /* do nothing */ }

// Operations
public:
	virtual yywint_t yylex();

// Tables
protected:
	const yywtransition_t YYNEARFAR* yytransition;
	long yytransitionmax;
};

class YYEXPCLASS YYFAR yywclexer : public yywlexer {
public:
	yywclexer() { /* do nothing */ }

// Operations
public:
	virtual yywint_t yylex();

// Tables
protected:
	const yywctransition_t YYNEARFAR* yyctransition;
};

_YL_END

// user defines
#if defined(YYBUDEFS) || defined(YYUDEFS)
#include <yybudefs.h>
#endif

// defines
#include <yybdefs.h>

#endif
