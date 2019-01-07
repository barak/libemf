/*
 * Checkout program for the EMF library
 * Copyright (C) 2015 Allen Barnett <dallenbarnett@users.sourceforge.net>
 * $Id: check3.c 54 2010-07-21 18:57:31Z dallenbarnett $
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

  PCSTR filename = "check4.emf";
  PCSTR description = "Test metafile created\0with libEMF\0";

  RECT size = { 0, 0, 20000, 10000 }; /* 10cm x 20cm */
  HDC metaDC = CreateEnhMetaFile( dc, filename, &size, description );

  WCHAR the_string[] = { 'A', '=', 0x03c0, 'r', 0x00b2 };
  HFONT font;

  font = CreateFont( -32, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET,
		     OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		     DEFAULT_PITCH | FF_DONTCARE, "Helvetica" );

  SelectObject( metaDC, font );
  TextOutW( metaDC, 50, 50, the_string, 5 );

  DeleteEnhMetaFile( CloseEnhMetaFile( metaDC ) );

  DeleteDC( metaDC );

  return 0;
}
