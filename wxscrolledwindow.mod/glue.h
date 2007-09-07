/*
  Copyright (c) 2007 Bruce A Henderson
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/ 

#include "wxglue.h"

class MaxScrolledWindow;

extern "C" {

#include <blitz.h>

	void bmx_wxscrolledwindow_calcscrolledposition(wxScrolledWindow * window, int x, int y, int * xx, int * yy);
	void bmx_wxscrolledwindow_calcunscrolledposition(wxScrolledWindow * window, int x, int y, int * xx, int * yy);
	void bmx_wxscrolledwindow_enablescrolling(wxScrolledWindow * window, int xScrolling, int yScrolling);
	void bmx_wxscrolledwindow_getscrollpixelsperunit(wxScrolledWindow * window, int * xUnit, int * yUnit);
	void bmx_wxscrolledwindow_getviewstart(wxScrolledWindow * window, int * x, int * y);
	void bmx_wxscrolledwindow_getvirtualsize(wxScrolledWindow * window, int * x, int * y);
	void bmx_wxscrolledwindow_dopreparedc(wxScrolledWindow * window, MaxDC * dc);
	void bmx_wxscrolledwindow_scroll(wxScrolledWindow * window, int x, int y);
	void bmx_wxscrolledwindow_setscrollbars(wxScrolledWindow * window, int pixelsPerUnitX, int pixelsPerUnitY, int noUnitsX, int noUnitsY, int xPos, int yPos, bool noRefresh);
	void bmx_wxscrolledwindow_setscrollrate(wxScrolledWindow * window, int xStep, int yStep);
	void bmx_wxscrolledwindow_settargetwindow(wxScrolledWindow * window, wxWindow * target);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxScrolledWindow: public wxScrolledWindow
{
public:
	MaxScrolledWindow(BBObject * handle, wxWindow * parent, wxWindowID id, int x, int y,
		int w, int h, long style);
	~MaxScrolledWindow();
	
};
