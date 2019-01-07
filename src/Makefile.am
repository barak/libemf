## Makefile.am -- Process this file with automake to produce Makefile.in
## Copyright (C) 2002 lignum Computing, Inc. <dallenbarnett@users.sourceforge.net>
## $Id: Makefile.am 70 2015-11-21 21:14:35Z dallenbarnett $
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; either version 2, or (at your option)
## any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 59 Temple Place, Suite 30, Boston, MA 02111-1307, USA.

AM_CPPFLAGS = -I$(top_srcdir)/include
bin_PROGRAMS = printemf
LDADD = $(top_builddir)/libemf/libEMF.la -lstdc++ -lm
