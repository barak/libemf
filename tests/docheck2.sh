#!/bin/sh

## Checkout script for libEMF.
## Copyright (C) 2002 lignum Computing, Inc. <dallenbarnett@users.sourceforge.net>
## $Id: docheck2.sh 80 2018-12-29 19:07:24Z dallenbarnett $
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

./check2 && cmp -l ${srcdir}/emfs/check1.emf check2.emf
