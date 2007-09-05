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

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxNotebook::MaxNotebook(BBObject * handle, wxWindow * parent, wxWindowID id, int x, int y, int w, int h, long style)
	: maxHandle(handle), wxNotebook(parent, id, wxPoint(x, y), wxSize(w, h), style)
{
	wxbind(this, handle);
}

MaxNotebook::~MaxNotebook() {
	wxunbind(this);
}

// *********************************************

MaxNotebook * bmx_wxnotebook_create(BBObject * maxHandle, wxWindow * parent, wxWindowID id, int x, int y, int w, int h, long style) {
	return new MaxNotebook(maxHandle, parent, id, x, y, w, h, style);
}

bool bmx_wxnotebook_addpage(MaxNotebook * notebook, wxWindow * page, BBString * text, bool selected, int imageId) {
	return notebook->AddPage(page, wxStringFromBBString(text), selected, imageId);
}

bool bmx_wxnotebook_insertpage(MaxNotebook * notebook, int index, wxWindow * page, BBString * text, bool selected, int imageId) {
	return notebook->InsertPage(index, page, wxStringFromBBString(text), selected, imageId);
}

void bmx_wxnotebook_advanceselection(MaxNotebook * notebook, bool forward) {
	notebook->AdvanceSelection(forward);
}

int bmx_wxnotebookevent_getoldselection(wxNotebookEvent & event) {
	return event.GetOldSelection();
}

int bmx_wxnotebookevent_getselection(wxNotebookEvent & event) {
	return event.GetSelection();
}

void bmx_wxnotebookevent_setoldselection(wxNotebookEvent & event, int page) {
	event.SetOldSelection(page);
}

void bmx_wxnotebookevent_setselection(wxNotebookEvent & event, int page) {
	event.SetSelection(page);
}

int bmx_wxnotebook_geteventtype(int type) {
	switch(type) {
		case 802: return wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED;
		case 803: return wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING;
	}
	
	return 0;
}

void bmx_wxnotebook_assignimagelist(MaxNotebook * notebook, wxImageList * list) {
	// need to unbind the imagelist, just in case! (so we don't try to delete it later)
	wxunbind(list);
	notebook->AssignImageList(list);
}

void bmx_wxnotebook_setimagelist(MaxNotebook * notebook, wxImageList * list) {
	notebook->SetImageList(list);
}


