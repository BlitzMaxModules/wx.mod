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

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxCollapsiblePane::MaxCollapsiblePane(BBObject * handle, wxWindow * parent, wxWindowID id, const wxString& label, int x, int y,
		int w, int h, long style)
	: wxCollapsiblePane(parent, id, label, wxPoint(x, y), wxSize(w, h), style)
{
	wxbind(this, handle);
}

MaxCollapsiblePane::~MaxCollapsiblePane() {
	wxunbind(this);
}


// *********************************************

MaxCollapsiblePane * bmx_wxcollapsiblepane_create(BBObject * maxHandle, wxWindow * parent, wxWindowID id, BBString * label, int x, int y,
		int w, int h, long style) {

	return new MaxCollapsiblePane(maxHandle, parent, id, wxStringFromBBString(label), x, y, w, h, style);
}

bool bmx_wxcollapsiblepane_iscollapsed(wxCollapsiblePane * pane) {
	return pane->IsCollapsed();
}

bool bmx_wxcollapsiblepane_isexpanded(wxCollapsiblePane * pane) {
	return pane->IsExpanded();
}

void bmx_wxcollapsiblepane_collapse(wxCollapsiblePane * pane, bool value) {
	pane->Collapse(value);
}

void bmx_wxcollapsiblepane_expand(wxCollapsiblePane * pane) {
	pane->Expand();
}

wxWindow * bmx_wxcollapsiblepane_getpane(wxCollapsiblePane * pane) {
	return pane->GetPane();
}


bool bmx_wxcollapsiblepaneevent_getcollapsed(wxCollapsiblePaneEvent & event) {
	return event.GetCollapsed();
}

void bmx_wxcollapsiblepaneevent_setcollapsed(wxCollapsiblePaneEvent & event, bool value) {
	event.SetCollapsed(value);
}


int bmx_wxcollapsiblepane_geteventtype(int type) {
	switch(type) {
		case 1102: return wxEVT_COMMAND_COLLPANE_CHANGED;
	}
	
	return 0;
}
