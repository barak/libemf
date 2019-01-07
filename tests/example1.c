/*
 * Example program for the EMF library
 * Copyright (C) 2002, 2003 lignum Computing, Inc. <dallenbarnett@users.sourceforge.net>
 * $Id: example1.c 70 2015-11-21 21:14:35Z dallenbarnett $
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

static int nplpl[] = { 3 };
static POINT plpl[] = { { 0, 0 }, { 100, 100 }, { 100, 0 } };

int main ( int argc, char* argv[] )
{
  (void)argc;
  (void)argv;

  HWND desktop = GetDesktopWindow();
  HDC dc = GetDC( desktop );

  PCSTR filename = "example1.emf";
  PCSTR description = "Example metafile created\0with libEMF\0";

  HENHMETAFILE mfh;
  HDC metaDC = CreateEnhMetaFile( dc, filename, 0, description );

  HPEN pen;
  HBRUSH brush;

  brush = CreateSolidBrush( RGB(0xff,0x00,0xff) );
  SelectObject( metaDC, brush );

  pen = CreatePen( PS_SOLID, 10, RGB(0x00,0xff,0x00) );
  SelectObject( metaDC, pen );

  PolyPolygon( metaDC, plpl, nplpl, 1 );

  mfh = CloseEnhMetaFile( metaDC );
  DeleteEnhMetaFile( mfh );
  DeleteDC( metaDC );

  return 0;
}
