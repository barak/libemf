/*
 * Checkout program for the EMF library
 * Copyright (C) 2002, 2003 lignum Computing, Inc. <dallenbarnett@users.sourceforge.net>
 * $Id: check2.c 70 2015-11-21 21:14:35Z dallenbarnett $
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#include <libEMF/emf.h>

int main ( int argc, char* argv[] )
{
  (void)argc;
  (void)argv;

  HWND desktop = GetDesktopWindow();
  HDC dc = GetDC( desktop );

  HENHMETAFILE mfh = GetEnhMetaFile( "check1.emf" );

  PCSTR filename = "check2.emf";
  PCSTR description = "Test metafile created\0with libEMF\0";
  RECT size = { 0, 0, 10000, 20000 }; /* 10cm x 20cm */
  HDC metaDC = CreateEnhMetaFile( dc, filename, &size, description );

  PlayEnhMetaFile( metaDC, mfh, 0 );

  DeleteEnhMetaFile( mfh );

  mfh = CloseEnhMetaFile( metaDC );
  DeleteEnhMetaFile( mfh );
  DeleteDC( metaDC );

  return 0;
}
