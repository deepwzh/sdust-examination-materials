/************************************************************
yyacpp.cpp
This file can be freely modified for the generation of
custom code.

[MBCS]

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

/************************************************************
Because of the size of debug libraries generated when using
C++ streams, ansi and unicode c++ source files have been
grouped together. This reduces the size of the resultant
libraries considerably. Note that this does not occur for
release libraries.
************************************************************/

#include "yydefs.h"

#if defined(YYDEBUG) && defined(YYSTDCPPLIB)

#define YYGROUP

#include "yyacback.cpp"
#include "yyaccpya.cpp"
#include "yyacdci.cpp"
#include "yyacdcic.cpp"
#include "yyacdela.cpp"
#include "yyacdisc.cpp"
#include "yyacdop.cpp"
#include "yyacdpop.cpp"
#include "yyacecho.cpp"
#include "yyacgetc.cpp"
#include "yyacgtok.cpp"
#include "yyacinp.cpp"
#include "yyaclcln.cpp"
#include "yyaclcon.cpp"
#include "yyaclcre.cpp"
#include "yyacldbg.cpp"
#include "yyacldes.cpp"
#include "yyaclerr.cpp"
#include "yyacless.cpp"
#include "yyaclex.cpp"
#include "yyaclexc.cpp"
#include "yyaclvts.cpp"
#include "yyaclvtv.cpp"
#include "yyacnewa.cpp"
#include "yyacoutp.cpp"
#include "yyacpar.cpp"
#include "yyacpcln.cpp"
#include "yyacpcon.cpp"
#include "yyacpcre.cpp"
#include "yyacperr.cpp"
#include "yyacpdbg.cpp"
#include "yyacpdes.cpp"
#include "yyacpop.cpp"
#include "yyacpush.cpp"
#include "yyacres.cpp"
#include "yyacserr.cpp"
#include "yyacsin.cpp"
#include "yyacsofw.cpp"
#include "yyacsskp.cpp"
#include "yyacsssz.cpp"
#include "yyacstsz.cpp"
#include "yyacstv.cpp"
#include "yyacsup.cpp"
#include "yyacsusz.cpp"
#include "yyactofw.cpp"
#include "yyacucin.cpp"
#include "yyacunp.cpp"
#include "yyacuofw.cpp"
#include "yyacvtlv.cpp"
#include "yyacvts.cpp"
#include "yyacwip.cpp"
#include "yyacwrap.cpp"
#include "yyacwrk.cpp"
#include "yyacwrkc.cpp"

#endif
