/*
  Copyright (c) 2007,2008 Bruce A Henderson
 
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
#include <wx/notebook.h>

class MaxNotebook;

extern "C" {

#include <blitz.h>

	MaxNotebook * bmx_wxnotebook_create(BBObject * maxHandle, wxWindow * parent, wxWindowID id, int x, int y, int w, int h, long style);
	int bmx_wxnotebook_getrowcount(wxNotebook * notebook);
	MaxColour * bmx_wxnotebook_getthemebackgroundcolour(wxNotebook * notebook);
	void bmx_wxnotebook_setpadding(wxNotebook * notebook, int width, int height);

	int bmx_wxnotebookevent_getoldselection(wxNotebookEvent & event);
	int bmx_wxnotebookevent_getselection(wxNotebookEvent & event);
	void bmx_wxnotebookevent_setoldselection(wxNotebookEvent & event, int page);
	void bmx_wxnotebookevent_setselection(wxNotebookEvent & event, int page);

	int bmx_wxnotebook_geteventtype(int type);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxNotebook : public wxNotebook
{
public:
	MaxNotebook(BBObject * handle, wxWindow * parent, wxWindowID id, int x, int y, int w, int h, long style);
	~MaxNotebook();
};

