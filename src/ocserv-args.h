/*   -*- buffer-read-only: t -*- vi: set ro:
 *  
 *  DO NOT EDIT THIS FILE   (ocserv-args.h)
 *  
 *  It has been AutoGen-ed  February 12, 2013 at 07:18:40 PM by AutoGen 5.16
 *  From the definitions    ocserv-args.def
 *  and the template file   options
 *
 * Generated from AutoOpts 36:4:11 templates.
 *
 *  AutoOpts is a copyrighted work.  This header file is not encumbered
 *  by AutoOpts licensing, but is provided under the licensing terms chosen
 *  by the ocserv author or copyright holder.  AutoOpts is
 *  licensed under the terms of the LGPL.  The redistributable library
 *  (``libopts'') is licensed under the terms of either the LGPL or, at the
 *  users discretion, the BSD license.  See the AutoOpts and/or libopts sources
 *  for details.
 *
 * The ocserv program is copyrighted and licensed
 * under the following terms:
 *
 *  Copyright (C) 2013 Nikos Mavrogiannopoulos, all rights reserved.
 *  This is free software. It is licensed for use, modification and
 *  redistribution under the terms of the
 *  GNU General Public License, version 2 <http://gnu.org/licenses/gpl.html>
 *
 *  ocserv is free software: you can redistribute it and/or modify it
 *  under the terms of version 2 of the GNU General Public License,
 *  as published by the Free Software Foundation.
 *  
 *  ocserv is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *  See the GNU General Public License for more details.
 *  
 *  You should have received a copy of the GNU General Public License,
 *  version 2, along with this program.
 *  If not, see <http://www.gnu.org/licenses/>.
 */
/*
 *  This file contains the programmatic interface to the Automated
 *  Options generated for the ocserv program.
 *  These macros are documented in the AutoGen info file in the
 *  "AutoOpts" chapter.  Please refer to that doc for usage help.
 */
#ifndef AUTOOPTS_OCSERV_ARGS_H_GUARD
#define AUTOOPTS_OCSERV_ARGS_H_GUARD 1
#include "config.h"
#include <autoopts/options.h>

/*
 *  Ensure that the library used for compiling this generated header is at
 *  least as new as the version current when the header template was released
 *  (not counting patch version increments).  Also ensure that the oldest
 *  tolerable version is at least as old as what was current when the header
 *  template was released.
 */
#define AO_TEMPLATE_VERSION 147460
#if (AO_TEMPLATE_VERSION < OPTIONS_MINIMUM_VERSION) \
 || (AO_TEMPLATE_VERSION > OPTIONS_STRUCT_VERSION)
# error option template version mismatches autoopts/options.h header
  Choke Me.
#endif

/*
 *  Enumeration of each option:
 */
typedef enum {
    INDEX_OPT_FOREGROUND  =  0,
    INDEX_OPT_TLS_DEBUG   =  1,
    INDEX_OPT_DEBUG       =  2,
    INDEX_OPT_CONFIG      =  3,
    INDEX_OPT_HELP        =  4,
    INDEX_OPT_MORE_HELP   =  5
} teOptIndex;

#define OPTION_CT    6

/*
 *  Interface defines for all options.  Replace "n" with the UPPER_CASED
 *  option name (as in the teOptIndex enumeration above).
 *  e.g. HAVE_OPT(FOREGROUND)
 */
#define         DESC(n) (ocservOptions.pOptDesc[INDEX_OPT_## n])
#define     HAVE_OPT(n) (! UNUSED_OPT(& DESC(n)))
#define      OPT_ARG(n) (DESC(n).optArg.argString)
#define    STATE_OPT(n) (DESC(n).fOptState & OPTST_SET_MASK)
#define    COUNT_OPT(n) (DESC(n).optOccCt)
#define    ISSEL_OPT(n) (SELECTED_OPT(&DESC(n)))
#define ISUNUSED_OPT(n) (UNUSED_OPT(& DESC(n)))
#define  ENABLED_OPT(n) (! DISABLED_OPT(& DESC(n)))
#define  STACKCT_OPT(n) (((tArgList*)(DESC(n).optCookie))->useCt)
#define STACKLST_OPT(n) (((tArgList*)(DESC(n).optCookie))->apzArgs)
#define    CLEAR_OPT(n) STMTS( \
                DESC(n).fOptState &= OPTST_PERSISTENT_MASK;   \
                if ((DESC(n).fOptState & OPTST_INITENABLED) == 0) \
                    DESC(n).fOptState |= OPTST_DISABLED; \
                DESC(n).optCookie = NULL )

/* * * * * *
 *
 *  Enumeration of ocserv exit codes
 */
typedef enum {
    OCSERV_EXIT_SUCCESS = 0,
    OCSERV_EXIT_FAILURE = 1,
    OCSERV_EXIT_LIBOPTS_FAILURE = 70
} ocserv_exit_code_t;
/* * * * * *
 *
 *  Interface defines for specific options.
 */
#define VALUE_OPT_FOREGROUND     'f'
#define VALUE_OPT_TLS_DEBUG      1
#define VALUE_OPT_DEBUG          'd'
#define VALUE_OPT_CONFIG         'c'
#define VALUE_OPT_HELP          'h'
#define VALUE_OPT_MORE_HELP     '!'
/*
 *  Interface defines not associated with particular options
 */
#define ERRSKIP_OPTERR  STMTS(ocservOptions.fOptSet &= ~OPTPROC_ERRSTOP)
#define ERRSTOP_OPTERR  STMTS(ocservOptions.fOptSet |= OPTPROC_ERRSTOP)
#define RESTART_OPT(n)  STMTS( \
                ocservOptions.curOptIdx = (n); \
                ocservOptions.pzCurOpt  = NULL)
#define START_OPT       RESTART_OPT(1)
#define USAGE(c)        (*ocservOptions.pUsageProc)(&ocservOptions, c)
/* extracted from opthead.tlib near line 484 */

#ifdef  __cplusplus
extern "C" {
#endif


/* * * * * *
 *
 *  Declare the ocserv option descriptor.
 */
extern tOptions ocservOptions;

#if defined(ENABLE_NLS)
# ifndef _
#   include <stdio.h>
static inline char* aoGetsText(char const* pz) {
    if (pz == NULL) return NULL;
    return (char*)gettext(pz);
}
#   define _(s)  aoGetsText(s)
# endif /* _() */

# define OPT_NO_XLAT_CFG_NAMES  STMTS(ocservOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT_CFG;)
# define OPT_NO_XLAT_OPT_NAMES  STMTS(ocservOptions.fOptSet |= \
                                    OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG;)

# define OPT_XLAT_CFG_NAMES     STMTS(ocservOptions.fOptSet &= \
                                  ~(OPTPROC_NXLAT_OPT|OPTPROC_NXLAT_OPT_CFG);)
# define OPT_XLAT_OPT_NAMES     STMTS(ocservOptions.fOptSet &= \
                                  ~OPTPROC_NXLAT_OPT;)

#else   /* ENABLE_NLS */
# define OPT_NO_XLAT_CFG_NAMES
# define OPT_NO_XLAT_OPT_NAMES

# define OPT_XLAT_CFG_NAMES
# define OPT_XLAT_OPT_NAMES

# ifndef _
#   define _(_s)  _s
# endif
#endif  /* ENABLE_NLS */

#ifdef  __cplusplus
}
#endif
#endif /* AUTOOPTS_OCSERV_ARGS_H_GUARD */
/* ocserv-args.h ends here */
