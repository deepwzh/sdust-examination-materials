#ifndef WMIYCONV_H
#define WMIYCONV_H

/************************************************************
wmiyconv.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* variables */
#define yylookahead (yy)->yymlookahead
#define yystackgrow (yy)->yymstackgrow
#define yyexitflg (yy)->yymexitflg
#define yyretireflg (yy)->yymretireflg
#define yyerrorflg (yy)->yymerrorflg
#define yypopflg (yy)->yympopflg
#define yywipeflg (yy)->yymwipeflg
#define yytop (yy)->yymtop
#define yychar (yy)->yymchar
#define yyskip (yy)->yymskip
#define yyerrorcount (yy)->yymerrorcount
#define yyexitcode (yy)->yymexitcode
#define yyretirecode (yy)->yymretirecode
#define yyerrorpop (yy)->yymerrorpop
#define yyparsererr (yy)->yymerr
#define yystackptr (yy)->yymstackptr
#define yysstackptr (yy)->yymsstackptr
#define yystack_size (yy)->yymstack_size
#define yysstack_size (yy)->yymsstack_size
#define yystack_max (yy)->yymstack_max
#define yyattribute_size (yy)->yymattribute_size
#define yyvalptr (yy)->yymvalptr
#define yylvalptr (yy)->yymlvalptr
#define yyattributestackptr (yy)->yymattributestackptr
#define yysattributestackptr (yy)->yymsattributestackptr
#define yyparserdebug (yy)->yymdebug
#define yyparserdebugstack (yy)->yymdebugstack
#define yyparserdebugflush (yy)->yymdebugflush
#define yyparserdebugout (yy)->yymdebugout

/* general functions */
#define yycparse() yywmcparse(yy)
#define yycwipe() yywmcwipe(yy)
#define yycwork() yywmcwork(yy)
#define yydestructpop(num) yywmdestructpop(yy, (num))
#define yyparse() yywmparse(yy)
#define yycleanupparser() yywmcleanupparser(yy)
#define yyinitparser() yywminitparser(yy)
#define yysetstacksize(size) yywmsetstacksize(yy, (size))
#define yysetup() yywmsetup(yy)
#define yywipe() yywmwipe(yy)
#define yywork() yywmwork(yy)

/* service functions */
#define yygettoken() (*yy->yymgettoken)(yy)
#define yydiscard(token) (*yy->yymdiscard)(yy, (token))
#define yysyntaxerror() (*yy->yymsyntaxerror)(yy)
#define yystackoverflow() (*yy->yymstackoverflow)(yy)
#define yyparsererror(text) (*yy->yymerror)(yy, (text))

/* action functions */
#define yycdestructclearin() yywmcdestructclearin(yy)
#define yydestructclearin() yywmdestructclearin(yy)
#define yysetin(token) yywmsetin(yy, (token))
#define yyunclearin() yywmunclearin(yy)
#define yyabort() yywmabort(yy)
#define yyaccept() yywmaccept(yy)
#define yyclearin() yywmclearin(yy)
#define yydestructclearin() yywmdestructclearin(yy)
#define yyerrok() yywmerrok(yy)
#define yyexit(exitcode) yywmexit(yy, (exitcode))
#define yyforceerror() yywmforceerror(yy)
#define yypopping() yywmpopping(yy)
#define yyrecovering() yywmrecovering(yy)
#define yyretire(retirecode) yywmretire(yy, (retirecode))
#define yythrowerror(pop) yywmthrowerror(yy, (pop))

#ifdef YY_COMPATIBLE
#undef yyerrok
#define yyerrok yywmerrok(yy)
#undef yyclearin
#define yyclearin yywmclearin(yy)
#endif
#define YYACCEPT yywmaccept(yy)
#define YYABORT yywmabort(yy)
#define YYERROR yywmthrowerror(yy, 0)
#define YYRECOVERING yywmrecovering(yy)
#ifndef YYNDEBUG
#define yydebug (yy)->yymdebug
#endif
#ifndef YYNERROR
#define yyerror(text) (*yy->yymerror)(yy, (text))
#endif

#endif
