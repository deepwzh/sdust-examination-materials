#ifndef WMLCONV_H
#define WMLCONV_H

/************************************************************
wmlconv.h
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
#define yyinitlexer() yywminitlexer(&(YYLEXERNAME))
#define yylex() yywmlex(&(YYLEXERNAME))
#define yyclex() yywmclex(&(YYLEXERNAME))
#define yyreset() yywmreset(&(YYLEXERNAME))
#define yycleanuplexer() yywmcleanuplexer(&(YYLEXERNAME))
#define yysettextsize(size) yywmsettextsize(&(YYLEXERNAME), (size))
#define yysetunputsize(size) yywmsetunputsize(&(YYLEXERNAME), (size))

/* service functions */
#define yyinput() (*(YYLEXERNAME).yyminput)(&(YYLEXERNAME))
#define yyoutput(ch) (*(YYLEXERNAME).yymoutput)(&(YYLEXERNAME), (ch))
#define yyunput(ch) (*(YYLEXERNAME).yymunput)(&(YYLEXERNAME), (ch))
#define yywrap() (*(YYLEXERNAME).yymwrap)(&(YYLEXERNAME))
#define yygetchar() (*(YYLEXERNAME).yymgetchar)(&(YYLEXERNAME))
#define yytextoverflow() (*(YYLEXERNAME).yymtextoverflow)(&(YYLEXERNAME))
#define yyunputoverflow() (*(YYLEXERNAME).yymunputoverflow)(&(YYLEXERNAME))
#define yylexererror(text) (*(YYLEXERNAME).yymerror)(&(YYLEXERNAME), (text))

/* action functions */
#define yybegin(state) yywmbegin(&(YYLEXERNAME), (state))
#define yyecho() yywmecho(&(YYLEXERNAME))
#define yyless(length) yywmless(&(YYLEXERNAME), (length))
#define yymore() yywmmore(&(YYLEXERNAME))
#define yynewline(newline) yywmnewline(&(YYLEXERNAME), (newline))
#define yyreject() yywmreject(&(YYLEXERNAME))
#define yyunputcount() yywmunputcount(&(YYLEXERNAME))

/* compatibility */
#define BEGIN (YYLEXERNAME).yymstart = 
#define ECHO yywmecho(&(YYLEXERNAME))
#define REJECT yywmreject(&(YYLEXERNAME))
#define YYSTATE (YYLEXERNAME).yymstart
#define YY_START (YYLEXERNAME).yymstart

#endif
