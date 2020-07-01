#ifndef WMYCONV_H
#define WMYCONV_H

/************************************************************
wmyconv.h
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
#define yycparse() yywmcparse(&(YYPARSERNAME))
#define yycwipe() yywmcwipe(&(YYPARSERNAME))
#define yycwork() yywmcwork(&(YYPARSERNAME))
#define yydestructpop(num) yywmdestructpop(&(YYPARSERNAME), (num))
#define yyparse() yywmparse(&(YYPARSERNAME))
#define yycleanupparser() yywmcleanupparser(&(YYPARSERNAME))
#define yyinitparser() yywminitparser(&(YYPARSERNAME))
#define yysetstacksize(size) yywmsetstacksize(&(YYPARSERNAME), (size))
#define yysetup() yywmsetup(&(YYPARSERNAME))
#define yywipe() yywmwipe(&(YYPARSERNAME))
#define yywork() yywmwork(&(YYPARSERNAME))

/* service functions */
#define yygettoken() (*(YYPARSERNAME).yymgettoken)(&(YYPARSERNAME))
#define yydiscard(token) (*(YYPARSERNAME).yymdiscard)(&(YYPARSERNAME), (token))
#define yysyntaxerror() (*(YYPARSERNAME).yymsyntaxerror)(&(YYPARSERNAME))
#define yystackoverflow() (*(YYPARSERNAME).yymstackoverflow)(&(YYPARSERNAME))
#define yyparsererror(text) (*(YYPARSERNAME).yymerror)(&(YYPARSERNAME), (text))

/* action functions */
#define yycdestructclearin() yywmcdestructclearin(&(YYPARSERNAME))
#define yydestructclearin() yywmdestructclearin(&(YYPARSERNAME))
#define yysetin(token) yywmsetin(&(YYPARSERNAME), (token))
#define yyunclearin() yywmunclearin(&(YYPARSERNAME))
#define yyabort() yywmabort(&(YYPARSERNAME))
#define yyaccept() yywmaccept(&(YYPARSERNAME))
#define yyclearin() yywmclearin(&(YYPARSERNAME))
#define yydestructclearin() yywmdestructclearin(&(YYPARSERNAME))
#define yyerrok() yywmerrok(&(YYPARSERNAME))
#define yyexit(exitcode) yywmexit(&(YYPARSERNAME), (exitcode))
#define yyforceerror() yywmforceerror(&(YYPARSERNAME))
#define yypopping() yywmpopping(&(YYPARSERNAME))
#define yyrecovering() yywmrecovering(&(YYPARSERNAME))
#define yyretire(retirecode) yywmretire(&(YYPARSERNAME), (retirecode))
#define yythrowerror(pop) yywmthrowerror(&(YYPARSERNAME), (pop))

#ifdef YY_COMPATIBLE
#undef yyerrok
#define yyerrok yywmerrok(&(YYPARSERNAME))
#undef yyclearin
#define yyclearin yywmclearin(&(YYPARSERNAME))
#endif
#define YYACCEPT yywmaccept(&(YYPARSERNAME))
#define YYABORT yywmabort(&(YYPARSERNAME))
#define YYERROR yywmthrowerror(&(YYPARSERNAME), 0)
#define YYRECOVERING yywmrecovering(&(YYPARSERNAME))
#ifndef YYNDEBUG
#define yydebug (YYPARSERNAME).yymdebug
#endif
#ifndef YYNERROR
#define yyerror(text) (*(YYPARSERNAME).yymerror)(&(YYPARSERNAME), (text))
#endif

#endif
