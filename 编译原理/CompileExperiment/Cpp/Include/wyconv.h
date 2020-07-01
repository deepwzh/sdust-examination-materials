#ifndef WYCONV_H
#define WYCONV_H

/************************************************************
wyconv.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/* variables */
#define yylookahead yywlookahead
#define yystackgrow yywstackgrow
#define yyexitflg yywexitflg
#define yyretireflg yywretireflg
#define yyerrorflg yywerrorflg
#define yypopflg yywpopflg
#define yywipeflg yywwipeflg
#define yytop yywtop
#define yychar yywchar
#define yyskip yywskip
#define yyerrorcount yywerrorcount
#define yyexitcode yywexitcode
#define yyretirecode yywretirecode
#define yyerrorpop yywerrorpop
#define yyparsererr yywparsererr
#define yystackptr yywstackptr
#define yysstackptr yywsstackptr
#define yystack_size yywstack_size
#define yysstack_size yywsstack_size
#define yystack_max yywstack_max
#define yyattribute_size yywattribute_size
#define yyvalptr yywvalptr
#define yylvalptr yywlvalptr
#define yyattributestackptr yywattributestackptr
#define yysattributestackptr yywsattributestackptr
#define yyparserdebug yywparserdebug
#define yyparserdebugstack yywparserdebugstack
#define yyparserdebugflush yywparserdebugflush
#define yyparserdebugout yywparserdebugout

/* general functions */
#define yycparse() yywcparse()
#define yycwipe() yywcwipe()
#define yycwork() yywcwork()
#define yydestructpop(num) yywdestructpop((num))
#define yyparse() yywparse()
#define yycleanupparser() yywcleanupparser()
#define yyinitparser() yywinitparser()
#define yysetstacksize(size) yywsetstacksize((size))
#define yysetup() yywsetup()
#define yywipe() yywwipe()
#define yywork() yywwork()

/* service functions */
#define yygettoken() yywgettoken()
#define yydiscard(token) yywdiscard(token)
#define yysyntaxerror() yywsyntaxerror()
#define yystackoverflow() yywstackoverflow()
#define yyparsererror(text) yywparsererror((text))

/* action functions */
#define yycdestructclearin() yywcdestructclearin()
#define yydestructclearin() yywdestructclearin()
#define yysetin(token) yywsetin((token))
#define yyunclearin() yywunclearin()
#define yyabort() yywabort()
#define yyaccept() yywaccept()
#define yyclearin() yywclearin()
#define yydestructclearin() yywdestructclearin()
#define yyerrok() yywerrok()
#define yyexit(exitcode) yywexit((exitcode))
#define yyforceerror() yywforceerror()
#define yypopping() yywpopping()
#define yyrecovering() yywrecovering()
#define yyretire(retirecode) yywretire((retirecode))
#define yythrowerror(pop) yywthrowerror((pop))

/* compatibility */
#ifdef YY_COMPATIBLE
#undef yyclearin
#define yyclearin (yywlookahead = YYFALSE)
#undef yyerrok
#define yyerrok yywsetskip(0)
#endif
#define YYABORT yywexit(1)
#define YYACCEPT yywexit(0)
#define YYERROR yywthrowerror(0)
#define YYRECOVERING yywrecovering()
#ifndef YYNDEBUG
#define yydebug yywparserdebug
#endif
#ifndef YYNERROR
#define yyerror(text) yywparsererror((text))
#endif

#endif
