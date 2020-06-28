#ifndef MYCONV_H
#define MYCONV_H

/************************************************************
myconv.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* variables */
#define yylookahead (YYPARSERNAME).yymlookahead
#define yystackgrow (YYPARSERNAME).yymstackgrow
#define yyexitflg (YYPARSERNAME).yymexitflg
#define yyretireflg (YYPARSERNAME).yymretireflg
#define yyerrorflg (YYPARSERNAME).yymerrorflg
#define yypopflg (YYPARSERNAME).yympopflg
#define yywipeflg (YYPARSERNAME).yymwipeflg
#define yytop (YYPARSERNAME).yymtop
#define yychar (YYPARSERNAME).yymchar
#define yyskip (YYPARSERNAME).yymskip
#define yyerrorcount (YYPARSERNAME).yymerrorcount
#define yyexitcode (YYPARSERNAME).yymexitcode
#define yyretirecode (YYPARSERNAME).yymretirecode
#define yyerrorpop (YYPARSERNAME).yymerrorpop
#define yyparsererr (YYPARSERNAME).yymerr
#define yystackptr (YYPARSERNAME).yymstackptr
#define yysstackptr (YYPARSERNAME).yymsstackptr
#define yystack_size (YYPARSERNAME).yymstack_size
#define yysstack_size (YYPARSERNAME).yymsstack_size
#define yystack_max (YYPARSERNAME).yymstack_max
#define yyattribute_size (YYPARSERNAME).yymattribute_size
#define yyvalptr (YYPARSERNAME).yymvalptr
#define yylvalptr (YYPARSERNAME).yymlvalptr
#define yyattributestackptr (YYPARSERNAME).yymattributestackptr
#define yysattributestackptr (YYPARSERNAME).yymsattributestackptr
#define yyparserdebug (YYPARSERNAME).yymdebug
#define yyparserdebugstack (YYPARSERNAME).yymdebugstack
#define yyparserdebugflush (YYPARSERNAME).yymdebugflush
#define yyparserdebugout (YYPARSERNAME).yymdebugout

/* general functions */
#define yycparse() yymcparse(&(YYPARSERNAME))
#define yycwipe() yymcwipe(&(YYPARSERNAME))
#define yycwork() yymcwork(&(YYPARSERNAME))
#define yydestructpop(num) yymdestructpop(&(YYPARSERNAME), (num))
#define yyparse() yymparse(&(YYPARSERNAME))
#define yycleanupparser() yymcleanupparser(&(YYPARSERNAME))
#define yyinitparser() yyminitparser(&(YYPARSERNAME))
#define yysetstacksize(size) yymsetstacksize(&(YYPARSERNAME), (size))
#define yysetup() yymsetup(&(YYPARSERNAME))
#define yywipe() yymwipe(&(YYPARSERNAME))
#define yywork() yymwork(&(YYPARSERNAME))

/* service functions */
#define yygettoken() (*(YYPARSERNAME).yymgettoken)(&(YYPARSERNAME))
#define yydiscard(token) (*(YYPARSERNAME).yymdiscard)(&(YYPARSERNAME), (token))
#define yysyntaxerror() (*(YYPARSERNAME).yymsyntaxerror)(&(YYPARSERNAME))
#define yystackoverflow() (*(YYPARSERNAME).yymstackoverflow)(&(YYPARSERNAME))
#define yyparsererror(text) (*(YYPARSERNAME).yymerror)(&(YYPARSERNAME), (text))

/* action functions */
#define yycdestructclearin() yymcdestructclearin(&(YYPARSERNAME))
#define yydestructclearin() yymdestructclearin(&(YYPARSERNAME))
#define yysetin(token) yymsetin(&(YYPARSERNAME), (token))
#define yyunclearin() yymunclearin(&(YYPARSERNAME))
#define yyabort() yymabort(&(YYPARSERNAME))
#define yyaccept() yymaccept(&(YYPARSERNAME))
#define yyclearin() yymclearin(&(YYPARSERNAME))
#define yydestructclearin() yymdestructclearin(&(YYPARSERNAME))
#define yyerrok() yymerrok(&(YYPARSERNAME))
#define yyexit(exitcode) yymexit(&(YYPARSERNAME), (exitcode))
#define yyforceerror() yymforceerror(&(YYPARSERNAME))
#define yypopping() yympopping(&(YYPARSERNAME))
#define yyrecovering() yymrecovering(&(YYPARSERNAME))
#define yyretire(retirecode) yymretire(&(YYPARSERNAME), (retirecode))
#define yythrowerror(pop) yymthrowerror(&(YYPARSERNAME), (pop))

#ifdef YY_COMPATIBLE
#undef yyerrok
#define yyerrok yymerrok(&(YYPARSERNAME))
#undef yyclearin
#define yyclearin yymclearin(&(YYPARSERNAME))
#endif
#define YYACCEPT yymaccept(&(YYPARSERNAME))
#define YYABORT yymabort(&(YYPARSERNAME))
#define YYERROR yymthrowerror(&(YYPARSERNAME), 0)
#define YYRECOVERING yymrecovering(&(YYPARSERNAME))
#ifndef YYNDEBUG
#define yydebug (YYPARSERNAME).yymdebug
#endif
#ifndef YYNERROR
#define yyerror(text) (*(YYPARSERNAME).yymerror)(&(YYPARSERNAME), (text))
#endif

#endif
