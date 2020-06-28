#ifndef WMILCONV_H
#define WMILCONV_H

/************************************************************
wmilconv.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* variables */
#define yymoreflg (yy)->yymmoreflg
#define yyrejectflg (yy)->yymrejectflg
#define yyreturnflg (yy)->yymreturnflg
#define yytextgrow (yy)->yymtextgrow
#define yyunputgrow (yy)->yymunputgrow
#define yyeol (yy)->yymeol
#define yyoldeol (yy)->yymoldeol
#define yystart (yy)->yymstart
#define yyin (yy)->yymin
#define yyout (yy)->yymout
#define yylexererr (yy)->yymerr
#define yyleng (yy)->yymleng
#define yylineno (yy)->yymlineno
#define yyunputindex (yy)->yymunputindex
#define yytext (yy)->yymtext
#define yystext (yy)->yymstext
#define yytext_size (yy)->yymtext_size
#define yystext_size (yy)->yymstext_size
#define yytext_max (yy)->yymtext_max
#define yystatebuf (yy)->yymstatebuf
#define yysstatebuf (yy)->yymsstatebuf
#define yyunputbufptr (yy)->yymunputbufptr
#define yysunputbufptr (yy)->yymsunputbufptr
#define yyunput_size (yy)->yymunput_size
#define yysunput_size (yy)->yymsunput_size
#define yyunput_max (yy)->yymunput_max
#define yylexerdebug (yy)->yymdebug
#define yylexerdebugflush (yy)->yymdebugflush
#define yylexerdebugout (yy)->yymdebugout

/* general functions */
#define yyinitlexer() yywminitlexer(yy)
#define yylex() yywmlex(yy)
#define yyclex() yywmclex(yy)
#define yyreset() yywmreset(yy)
#define yycleanuplexer() yywmcleanuplexer(yy)
#define yysettextsize(size) yywmsettextsize(yy, (size))
#define yysetunputsize(size) yywmsetunputsize(yy, (size))

/* service functions */
#define yygetchar() (*yy->yymgetchar)(yy)
#define yyinput() (*yy->yyminput)(yy)
#define yyoutput(ch) (*yy->yymoutput)(yy, (ch))
#define yyunput(ch) (*yy->yymunput)(yy, (ch))
#define yywrap() (*yy->yymwrap)(yy)
#define yytextoverflow() (*yy->yymtextoverflow)(yy)
#define yyunputoverflow() (*yy->yymunputoverflow)(yy)
#define yylexererror(text) (*yy->yymerror)(yy, (text))

/* action functions */
#define yybegin(state) yywmbegin(yy, (state))
#define yyecho() yywmecho(yy)
#define yyless(length) yywmless(yy, (length))
#define yymore() yywmmore(yy)
#define yynewline(newline) yywmnewline(yy, (newline))
#define yyreject() yywmreject(yy)
#define yyunputcount() yywmunputcount(yy)

/* compatibility */
#define BEGIN (yy)->yymstart = 
#define ECHO yywmecho(yy)
#define REJECT yywmreject(yy)
#define YYSTATE (yy)->yymstart
#define YY_START (yy)->yymstart

#endif
