/*
 * Checkout program for the EMF library
 * Copyright (C) 2002, 2003 lignum Computing, Inc. <dallenbarnett@users.sourceforge.net>
 * $Id: check1.c 70 2015-11-21 21:14:35Z dallenbarnett $
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

static XFORM xform = { 2., 0., 0., 2., -3., -4. };

static POINT plarray[4] = { { -4, -3 }, { -2, -1 }, { 0, 1 }, { 2, 3 } };
static POINT plarrayl[4] = { { -400000, -300000 }, { -200000, -100000 },
			     { 0, 100000 }, { 200000, 300000 } };
static POINT pltoarray[4] = { { -10, -20 }, { -30, -40 }, { 50, 61 }, { 72, 83 } };
static POINT pltoarrayl[4] = { { -1000000, -2000000 }, { -3000000, -4000000 },
			       { 5000000, 6100000 }, { 7200000, 8300000 } };
static POINT pgarray[4] = {
  { -400, -300 }, { -200, -100 }, { 0, 100 }, { 200, 300 }
};
static POINT pgarrayl[4] = {
  { -40000000, -30000000 }, { -20000000, -10000000 },
  { 0, 10000000 }, { 20000000, 30000000 }
};
static INT advances[7] = { 11, 22, 33, 44, 55, 66, 77 };
static POINT plplarray[7] = { { -101, -201 }, { -301, -401 }, { -501, -601 },
			      { 101, 201 }, { 301, 401 }, { 501, 601 }, { 701, 801 } };
static POINT plplarrayl[7] = { { -10100000, -20100000 }, { -30100000, -40100000 },
			       { -50100000, -60100000 },
			       { 10100000, 20100000 }, { 30100000, 40100000 },
			       { 50100000, 60100000 }, { 70100000, 80100000 } };
static INT plplsizes[2] = { 3, 4 };
static LOGPEN lpen = { PS_SOLID, {20,20}, RGB(0,0xff,0xff) };
static LOGBRUSH lbrush = { BS_HATCHED, RGB(0x0,0x0,0xff), HS_DIAGCROSS };

int main ( int argc, char* argv[] )
{
  (void)argc;
  (void)argv;

  HWND desktop = GetDesktopWindow();
  HDC dc = GetDC( desktop );

  RECT size = { 0, 0, 10000, 20000 }; /* 10cm x 20cm */
  PCSTR filename = "check1.emf";
  PCSTR description = "Test metafile created\0with libEMF\0";

  HENHMETAFILE mfh;
  HDC metaDC = CreateEnhMetaFile( dc, filename, &size, description );

  HPEN pen;
  HBRUSH brush;
  HFONT font;

  FLOAT old_miter_limit;

  SetViewportOrgEx( metaDC, 123, 456, 0 );
  SetViewportExtEx( metaDC, 789, 1011, 0 );
  ScaleViewportExtEx( metaDC, 1, 2, 1, 2, 0 );

  SetWindowOrgEx( metaDC, 124, 248, 0 );
  SetWindowExtEx( metaDC, 481, 812, 0 );
  ScaleWindowExtEx( metaDC, 1, 2, 1, 2, 0 );

  ModifyWorldTransform( metaDC, &xform, MWT_IDENTITY );
  SetWorldTransform( metaDC, &xform );

  SetTextColor( metaDC, RGB(0x12,0x34,0x56) );
  SetTextAlign( metaDC, TA_CENTER+TA_BASELINE );
  SetBkMode( metaDC, TRANSPARENT );
  SetBkColor( metaDC, RGB(0x78,0x9a,0xbc) );
  SetPolyFillMode( metaDC, WINDING );
  SetMapMode( metaDC, MM_ANISOTROPIC );

  SelectObject( metaDC, GetStockObject( WHITE_BRUSH ) );

  MoveToEx( metaDC, 123, 456, 0 );
  LineTo( metaDC, 789, 1011 );

  Arc( metaDC, 12, 23, 34, 45, 56, 67, 78, 89 );
  ArcTo( metaDC, 12, 23, 34, 45, 56, 67, 78, 89 );

  Rectangle( metaDC, 98, 76, 54, 32 );
  Ellipse( metaDC, 32, 54, 76, 98 );

  SetMiterLimit( metaDC, 20.f, &old_miter_limit );
  Polyline( metaDC, plarray, 4 );
  Polyline( metaDC, plarrayl, 4 );
  PolylineTo( metaDC, pltoarray, 4 );
  PolylineTo( metaDC, pltoarrayl, 4 );
  PolyBezier( metaDC, plarray, 4 );
  PolyBezier( metaDC, plarrayl, 4 );
  PolyBezierTo( metaDC, pltoarray, 4 );
  PolyBezierTo( metaDC, pltoarrayl, 4 );
  Polygon( metaDC, pgarray, 4 );
  Polygon( metaDC, pgarrayl, 4 );
  PolyPolygon( metaDC, plplarray, plplsizes, 2 );
  PolyPolygon( metaDC, plplarrayl, plplsizes, 2 );

  TextOut( metaDC, 50, 75, "A larger font, e?", 17 );
  ExtTextOut( metaDC, 100, 200, ETO_GRAYED|ETO_CLIPPED, 0, "And now", 7, advances );

  pen = CreatePenIndirect( &lpen );
  SelectObject( metaDC, pen );
  SelectObject( metaDC, GetStockObject( GRAY_BRUSH ) );
  DeleteObject( GetStockObject( GRAY_BRUSH ) );

  brush = CreateBrushIndirect( &lbrush );
  SelectObject( metaDC, brush );

  font = CreateFont( -11, 0, 0, 0, FW_BOLD, 0, 0, 0, ANSI_CHARSET,
		     OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		     DEFAULT_PITCH | FF_DONTCARE, "Helvetica" );
  SelectObject( metaDC, font );
  DeleteObject( font );
  DeleteObject( brush );
  DeleteObject( pen );

  BeginPath( metaDC );
  EndPath( metaDC );
  CloseFigure( metaDC );

  FillPath( metaDC );
  StrokePath( metaDC );
  StrokeAndFillPath( metaDC );

  SetPixel( metaDC, 123, 456, RGB(0x24,0x68,0xac) );

  SaveDC( metaDC );
  SetMetaRgn( metaDC );
  RestoreDC( metaDC, 1 );

  pen = ExtCreatePen( PS_SOLID, 1, &lbrush, 0, 0 );
  SelectObject( metaDC, pen );
  DeleteObject( pen );

  mfh = CloseEnhMetaFile( metaDC );
  DeleteEnhMetaFile( mfh );
  DeleteDC( metaDC );

  return 0;
}
