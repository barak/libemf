# Process this file with autoconf to produce a configure script.
# Copyright (C) 2002, 2003 lignum Computing, Inc. <dallenbarnett@users.sourceforge.net>
# $Id: configure.ac 98 2020-06-07 13:10:19Z dallenbarnett $

AC_INIT([libEMF], 1.0.13, dallenbarnett@users.sourceforge.net)
AC_CONFIG_AUX_DIR(config)
AM_CONFIG_HEADER([config/config.h])
AC_CONFIG_SRCDIR([include/libEMF/emf.h])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL
#AC_PROG_LIBTOOL
AC_PROG_MAKE_SET

LT_INIT

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([errno.h stddef.h stdlib.h string.h unistd.h limits.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_MEMCMP
AC_CHECK_LIB(m, ceil)
AC_CHECK_FUNCS([floor memset select])

# Autoheader seems to complain about a lack of these (perhaps rightly)
AH_TEMPLATE(LIBEMF_DEBUG, [Turn on any addition debugging edits])
AH_TEMPLATE(ENABLE_EDITING, [Enable the EditEnhMetaFile() function])

# If you want to use Checker, then you have to enable debugging and
# disable threads

AC_ARG_ENABLE(debug,
[  --enable-debug          enable libEMF debugging [default=no]],
  enable_debug=$enableval, enable_debug=no)
if test "x$enable_debug" = xyes; then
  AC_DEFINE(LIBEMF_DEBUG, 1)
  if test "x$GCC" = xyes; then
    CFLAGS="$CFLAGS -g -O0 -Wall -W"
    CXXFLAGS="$CXXFLAGS -g -O0 -Wall -W"
  else
    AC_MSG_WARN([compiler unknown, please disable optimizations manually in \
your CFLAGS])
  fi
fi

AC_ARG_ENABLE(threads,
[  --enable-threads           enable threads [default=yes]],
  have_threads=$enableval, have_threads=yes)
if test "x$have_threads" = xyes; then
THREAD_LIBS=
AC_CHECK_HEADERS(pthread.h,
  AC_MSG_CHECKING(for pthread_create in -lpthread)

  save_LIBS=$LIBS
  LIBS="$LIBS -lpthread"
  AC_TRY_LINK([#include <pthread.h>],[
pthread_create (NULL, NULL, NULL, NULL)],[
    AC_MSG_RESULT(yes)
    CFLAGS="$CFLAGS -D_REENTRANT -DPTHREADS"
    CXXFLAGS="$CXXFLAGS -D_REENTRANT -DPTHREADS"
    THREAD_LIBS="$THREAD_LIBS -lpthread"],
    AC_MSG_RESULT(no)))
  LIBS=$save_LIBS
AC_SUBST(THREAD_LIBS)
else
  CFLAGS="$CFLAGS -D_NOTHREADS"
  CXXFLAGS="$CXXFLAGS -D_NOTHREADS"
fi

# You can turn on (human readable) editing of metafile if desired.
# Adds a lot of code and data to the library, though.

AC_ARG_ENABLE(editing,
[  --enable-editing     enable EditEnhMetaFile() function [default=no]],
  enable_editing=$enableval, enable_editing=no)
if test "x$enable_editing" = xyes; then
   AC_DEFINE(ENABLE_EDITING, 1)
fi

AM_CONDITIONAL(LIBEMF_DEBUG, test $enable_debug = yes)
AM_CONDITIONAL(HAVE_THREADS, test $have_threads = yes)
AM_CONDITIONAL(ENABLE_EDITING, test $enable_editing = no)

AC_CONFIG_FILES([Makefile include/Makefile libemf/Makefile \
src/Makefile doc/Makefile tests/Makefile])

AC_OUTPUT
