#ifndef WLCONV_H
#define WLCONV_H

/************************************************************
wlconv.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* variables */
#define yymoreflg yywmoreflg
#define yyrejectflg yywrejectflg
#define yyreturnflg yywreturnflg
#define yytextgrow yywtextgrow
#define yyunputgrow yywunputgrow
#define yyeol yyweol
#define yyoldeol yywoldeol
#define yystart yywstart
#define yyin yywin
#define yyout yywout
#define yylexererr yywlexererr
#define yyleng yywleng
#define yylineno yywlineno
#define yyunputindex yywunputindex
#define yytext yywtext
#define yystext yywstext
#define yytext_size yywtext_size
#define yystext_size yywstext_size
#define yytext_max yywtext_max
#define yystatebuf yywstatebuf
#define yysstatebuf yywsstatebuf
#define yyunputbufptr yywunputbufptr
#define yysunputbufptr yywsunputbufptr
#define yyunput_size yywunputbufptr
#define yysunput_size yywsunput_size
#define yyunput_max yywunput_max
#define yylexerdebug yywlexerdebug
#define yylexerdebugflush yywlexerdebugflush
#define yylexerdebugout yywlexerdebugout

/* general functions */
#define yyinitlexer() yywinitlexer()
#define yylex() yywlex()
#define yyclex() yywclex()
#define yyreset() yywreset()
#define yycleanuplexer() yywcleanuplexer()
#define yysettextsize(size) yywsettextsize((size))
#define yysetunputsize(size) yywsetunputsize((size))

/* service functions */
#define yygetchar() yywgetchar()
#define yyinput() yywinput()
#define yyoutput(ch) yywoutput((ch))
#define yyunput(ch) yywunput((ch))
#define yywrap() yywwrap()
#define yytextoverflow() yywtextoverflow()
#define yyunputoverflow() yywunputoverflow()
#define yylexererror(text) yywlexererror((text))

/* action functions */
#define yybegin(state) yywbegin((state))
#define yyecho() yywecho()
#define yyless(length) yywless((length))
#define yymore() yywmore()
#define yynewline(newline) yywnewline((newline))
#define yyreject() yywreject()
#define yyunputcount() yywunputcount()

/* compatibility */
#define BEGIN yywstart = 
#define ECHO yywecho()
#define REJECT yywreject()
#define YYSTATE yywstart
#define YY_START yywstart

#endif
