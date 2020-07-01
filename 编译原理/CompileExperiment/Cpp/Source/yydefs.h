#ifndef YYDEFS_H
#define YYDEFS_H

/************************************************************
yydefs.h
This file can be freely modified for the generation of
custom code.

Copyright (c) 1999-2003 Bumble-Bee Software Ltd.
************************************************************/

// defines
#include <yytdefs.h>

// user defines
#if defined(YYTUDEFS) || defined(YYUDEFS)
#include <yytudefs.h>
#endif

// user defines
#if defined(YYBUDEFS) || defined(YYUDEFS)
#include <yybudefs.h>
#endif

// defines
#include <yybdefs.h>

#endif
