#ifndef MLCONV_H
#define MLCONV_H

/************************************************************
mlconv.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* variables */
#define yymoreflg (YYLEXERNAME).yymmoreflg
#define yyrejectflg (YYLEXERNAME).yymrejectflg
#define yyreturnflg (YYLEXERNAME).yymreturnflg
#define yytextgrow (YYLEXERNAME).yymtextgrow
#define yyunputgrow (YYLEXERNAME).yymunputgrow
#define yyeol (YYLEXERNAME).yymeol
#define yyoldeol (YYLEXERNAME).yymoldeol
#define yystart (YYLEXERNAME).yymstart
#define yyin (YYLEXERNAME).yymin
#define yyout (YYLEXERNAME).yymout
#define yylexererr (YYLEXERNAME).yymerr
#define yyleng (YYLEXERNAME).yymleng
#define yylineno (YYLEXERNAME).yymlineno
#define yyunputindex (YYLEXERNAME).yymunputindex
#define yytext (YYLEXERNAME).yymtext
#define yystext (YYLEXERNAME).yymstext
#define yytext_size (YYLEXERNAME).yymtext_size
#define yystext_size (YYLEXERNAME).yymstext_size
#define yytext_max (YYLEXERNAME).yymtext_max
#define yystatebuf (YYLEXERNAME).yymstatebuf
#define yysstatebuf (YYLEXERNAME).yymsstatebuf
#define yyunputbufptr (YYLEXERNAME).yymunputbufptr
#define yysunputbufptr (YYLEXERNAME).yymsunputbufptr
#define yyunput_size (YYLEXERNAME).yymunput_size
#define yysunput_size (YYLEXERNAME).yymsunput_size
#define yyunput_max (YYLEXERNAME).yymunput_max
#define yylexerdebug (YYLEXERNAME).yymdebug
#define yylexerdebugflush (YYLEXERNAME).yymdebugflush
#define yylexerdebugout (YYLEXERNAME).yymdebugout

/* general functions */
#define yyinitlexer() yyminitlexer(&(YYLEXERNAME))
#define yylex() yymlex(&(YYLEXERNAME))
#define yyclex() yymclex(&(YYLEXERNAME))
#define yyreset() yymreset(&(YYLEXERNAME))
#define yycleanuplexer() yymcleanuplexer(&(YYLEXERNAME))
#define yysettextsize(size) yymsettextsize(&(YYLEXERNAME), (size))
#define yysetunputsize(size) yymsetunputsize(&(YYLEXERNAME), (size))

/* service functions */
#define yygetchar() (*(YYLEXERNAME).yymgetchar)(&(YYLEXERNAME))
#define yyinput() (*(YYLEXERNAME).yyminput)(&(YYLEXERNAME))
#define yyoutput(ch) (*(YYLEXERNAME).yymoutput)(&(YYLEXERNAME), (ch))
#define yyunput(ch) (*(YYLEXERNAME).yymunput)(&(YYLEXERNAME), (ch))
#define yywrap() (*(YYLEXERNAME).yymwrap)(&(YYLEXERNAME))
#define yytextoverflow() (*(YYLEXERNAME).yymtextoverflow)(&(YYLEXERNAME))
#define yyunputoverflow() (*(YYLEXERNAME).yymunputoverflow)(&(YYLEXERNAME))
#define yylexererror(text) (*(YYLEXERNAME).yymerror)(&(YYLEXERNAME), (text))

/* action functions */
#define yybegin(state) yymbegin(&(YYLEXERNAME), (state))
#define yyecho() yymecho(&(YYLEXERNAME))
#define yyless(length) yymless(&(YYLEXERNAME), (length))
#define yymore() yymmore(&(YYLEXERNAME))
#define yynewline(newline) yymnewline(&(YYLEXERNAME), (newline))
#define yyreject() yymreject(&(YYLEXERNAME))
#define yyunputcount() yymunputcount(&(YYLEXERNAME))

/* compatibility */
#define BEGIN (YYLEXERNAME).yymstart = 
#define ECHO yymecho(&(YYLEXERNAME))
#define REJECT yymreject(&(YYLEXERNAME))
#define YYSTATE (YYLEXERNAME).yymstart
#define YY_START (YYLEXERNAME).yymstart

#endif
