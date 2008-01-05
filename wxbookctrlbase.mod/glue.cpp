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



// *********************************************

bool bmx_wxbookctrlbase_addpage(wxBookCtrlBase * book, wxWindow * page, BBString * text, bool selected, int imageId) {
	return book->AddPage(page, wxStringFromBBString(text), selected, imageId);
}

bool bmx_wxbookctrlbase_insertpage(wxBookCtrlBase * book, int index, wxWindow * page, BBString * text, bool selected, int imageId) {
	return book->InsertPage(index, page, wxStringFromBBString(text), selected, imageId);
}

void bmx_wxbookctrlbase_advanceselection(wxBookCtrlBase * book, bool forward) {
	book->AdvanceSelection(forward);
}

void bmx_wxbookctrlbase_assignimagelist(wxBookCtrlBase * book, wxImageList * list) {
	// need to unbind the imagelist, just in case! (so we don't try to delete it later)
	wxunbind(list);
	book->AssignImageList(list);
}

void bmx_wxbookctrlbase_setimagelist(wxBookCtrlBase * book, wxImageList * list) {
	book->SetImageList(list);
}

bool bmx_wxbookctrlbase_deleteallpages(wxBookCtrlBase * book) {
	return book->DeleteAllPages();
}

bool bmx_wxbookctrlbase_deletepage(wxBookCtrlBase * book, int page) {
	return book->DeletePage(page);
}

wxWindow *  bmx_wxbookctrlbase_getcurrentpage(wxBookCtrlBase * book) {
	return book->GetCurrentPage();
}

wxWindow * bmx_wxbookctrlbase_getpage(wxBookCtrlBase * book, int page) {
	return book->GetPage(page);
}

int bmx_wxbookctrlbase_getpagecount(wxBookCtrlBase * book) {
	return book->GetPageCount();
}

int bmx_wxbookctrlbase_getpageimage(wxBookCtrlBase * book, int page) {
	return book->GetPageImage(page);
}

BBString * bmx_wxbookctrlbase_getpagetext(wxBookCtrlBase * book, int page) {
	return bbStringFromWxString(book->GetPageText(page));
}

int bmx_wxbookctrlbase_getselection(wxBookCtrlBase * book) {
	return book->GetSelection();
}

int bmx_wxbookctrlbase_hittest(wxBookCtrlBase * book, int x, int y, long * flags) {
	return book->HitTest(wxPoint(x, y), flags);
}

bool bmx_wxbookctrlbase_removepage(wxBookCtrlBase * book, int page) {
	return book->RemovePage(page);
}

void bmx_wxbookctrlbase_setpagesize(wxBookCtrlBase * book, int width, int height) {
	book->SetPageSize(wxSize(width, height));
}

bool bmx_wxbookctrlbase_setpageimage(wxBookCtrlBase * book, int page, int image) {
	return book->SetPageImage(page, image);
}

bool bmx_wxbookctrlbase_setpagetext(wxBookCtrlBase * book, int page, BBString * text) {
	return book->SetPageText(page, wxStringFromBBString(text));
}

int bmx_wxbookctrlbase_setselection(wxBookCtrlBase * book, int page) {
	return book->SetSelection(page);
}

int bmx_wxbookctrlbase_changeselection(wxBookCtrlBase * book, int page) {
	return book->ChangeSelection(page);
}


