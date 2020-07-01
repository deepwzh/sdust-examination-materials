/************************************************************
yywcpp.cpp
This file can be freely modified for the generation of
custom code.

[Unicode]

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

#include "yywcback.cpp"
#include "yywccpya.cpp"
#include "yywcdci.cpp"
#include "yywcdcic.cpp"
#include "yywcdela.cpp"
#include "yywcdisc.cpp"
#include "yywcdop.cpp"
#include "yywcdpop.cpp"
#include "yywcecho.cpp"
#include "yywcgetc.cpp"
#include "yywcgtok.cpp"
#include "yywcinp.cpp"
#include "yywclcln.cpp"
#include "yywclcon.cpp"
#include "yywclcre.cpp"
#include "yywcldbg.cpp"
#include "yywcldes.cpp"
#include "yywclerr.cpp"
#include "yywcless.cpp"
#include "yywclex.cpp"
#include "yywclexc.cpp"
#include "yywclvts.cpp"
#include "yywclvtv.cpp"
#include "yywcnewa.cpp"
#include "yywcoutp.cpp"
#include "yywcpar.cpp"
#include "yywcpcln.cpp"
#include "yywcpcon.cpp"
#include "yywcpcre.cpp"
#include "yywcpdbg.cpp"
#include "yywcpdes.cpp"
#include "yywcperr.cpp"
#include "yywcpop.cpp"
#include "yywcpush.cpp"
#include "yywcres.cpp"
#include "yywcserr.cpp"
#include "yywcsin.cpp"
#include "yywcsofw.cpp"
#include "yywcsskp.cpp"
#include "yywcsssz.cpp"
#include "yywcstsz.cpp"
#include "yywcstv.cpp"
#include "yywcsup.cpp"
#include "yywcsusz.cpp"
#include "yywctofw.cpp"
#include "yywcucin.cpp"
#include "yywcunp.cpp"
#include "yywcuofw.cpp"
#include "yywcvtlv.cpp"
#include "yywcvts.cpp"
#include "yywcwipe.cpp"
#include "yywcwrap.cpp"
#include "yywcwrk.cpp"
#include "yywcwrkc.cpp"

#endif
