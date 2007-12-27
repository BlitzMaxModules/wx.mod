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

MaxFlatNotebook:: MaxFlatNotebook(BBObject * handle, wxWindow * parent, wxWindowID id, int x, int y, int w, int h, long style)
	: wxFlatNotebook(parent, id, wxPoint(x, y), wxSize(w, h), style)
{
	wxbind(this, handle);
}

MaxFlatNotebook::~ MaxFlatNotebook() {
	wxunbind(this);
}


// *********************************************

wxFlatNotebook * bmx_wxflatnotebook_create(BBObject * handle, wxWindow * parent, wxWindowID id, int x, int y, int w, int h, long style) {
	return new MaxFlatNotebook(handle, parent, id, x, y, w, h, style);
}

void bmx_wxflatnotebook_advanceselection(wxFlatNotebook * fnb, bool forward) {
    fnb->AdvanceSelection(forward);
}

bool bmx_wxflatnotebook_addpage(wxFlatNotebook * fnb, wxWindow * window, BBString * caption, bool selected, int imgIndex) {
    return fnb->AddPage(window, wxStringFromBBString(caption), selected, imgIndex);
}

bool bmx_wxflatnotebook_insertpage(wxFlatNotebook * fnb, int index, wxWindow * page, BBString * text, bool selected, int imgIndex) {
	return fnb->InsertPage(index, page, wxStringFromBBString(text), selected, imgIndex);
}

void bmx_wxflatnotebook_setselection(wxFlatNotebook * fnb, int page) {
    fnb->SetSelection(page);
}

void bmx_wxflatnotebook_deletepage(wxFlatNotebook * fnb, int page, bool _notify) {
    fnb->DeletePage(page, _notify);
}

bool bmx_wxflatnotebook_deleteallpages(wxFlatNotebook * fnb) {
    return fnb->DeleteAllPages();
}

int bmx_wxflatnotebook_getpagecount(wxFlatNotebook * fnb) {
    return fnb->GetPageCount();
}

wxWindow * bmx_wxflatnotebook_getcurrentpage(wxFlatNotebook * fnb) {
    return fnb->GetCurrentPage();
}

wxWindow * bmx_wxflatnotebook_getpage(wxFlatNotebook * fnb, int page) {
    return fnb->GetPage(page);
}

int bmx_wxflatnotebook_getpageindex(wxFlatNotebook * fnb, wxWindow * win) {
    return fnb->GetPageIndex(win);
}

int bmx_wxflatnotebook_getpreviousselection(wxFlatNotebook * fnb) {
    return fnb->GetPreviousSelection();
}

bool bmx_wxflatnotebook_getpageshapeangle(wxFlatNotebook * fnb, int page, unsigned int * result) {
    return fnb->GetPageShapeAngle(page, result);
}

void bmx_wxflatnotebook_setpageshapeangle(wxFlatNotebook * fnb, int page, unsigned int angle) {
    fnb->SetPageShapeAngle(page, angle);
}

void bmx_wxflatnotebook_setallpagesshapeangle(wxFlatNotebook * fnb, unsigned int angle) {
    fnb->SetAllPagesShapeAngle(angle);
}

void bmx_wxflatnotebook_getpagebestsize(wxFlatNotebook * fnb, int * w, int * h) {
    wxSize s = fnb->GetPageBestSize();
    *w = s.x;
    *h = s.y;
}

bool bmx_wxflatnotebook_setpagetext(wxFlatNotebook * fnb, int page, BBString * text) {
    return fnb->SetPageText(page, wxStringFromBBString(text));
}

bool bmx_wxflatnotebook_removepage(wxFlatNotebook * fnb, int page, bool _notify) {
    return fnb->RemovePage(page, _notify);
}

void bmx_wxflatnotebook_setpadding(wxFlatNotebook * fnb, int padW, int padH) {
    fnb->SetPadding(wxSize(padW, padH));
}

void bmx_wxflatnotebook_setwindowstyleflag(wxFlatNotebook * fnb, long style) {
    fnb->SetWindowStyleFlag(style);
}

void bmx_wxflatnotebook_setrightclickmenu(wxFlatNotebook * fnb, wxMenu * menu) {
    fnb->SetRightClickMenu(menu);
}

BBString * bmx_wxflatnotebook_getpagetext(wxFlatNotebook * fnb, int page) {
    return bbStringFromWxString(fnb->GetPageText(page));
}

void bmx_wxflatnotebook_setpageimageindex(wxFlatNotebook * fnb, int page, int imgIndex) {
    fnb->SetPageImageIndex(page, imgIndex);
}

int bmx_wxflatnotebook_getpageimageindex(wxFlatNotebook * fnb, int page) {
    return fnb->GetPageImageIndex(page);
}

void bmx_wxflatnotebook_setgradientcolors(wxFlatNotebook * fnb, MaxColour * colFrom, MaxColour * colTo, MaxColour * border) {
    fnb->SetGradientColors(colFrom->Colour(), colTo->Colour(), border->Colour());
}

void bmx_wxflatnotebook_setgradientcolorfrom(wxFlatNotebook * fnb, MaxColour * colour) {
    fnb->SetGradientColorFrom(colour->Colour());
}

void bmx_wxflatnotebook_setgradientcolorto(wxFlatNotebook * fnb, MaxColour * colour) {
    fnb->SetGradientColorTo(colour->Colour());
}

void bmx_wxflatnotebook_setgradientcolorborder(wxFlatNotebook * fnb, MaxColour * colour) {
    fnb->SetGradientColorBorder(colour->Colour());
}

void bmx_wxflatnotebook_enablepage(wxFlatNotebook * fnb, int page, bool enabled) {
    fnb->Enable(page, enabled);
}

bool bmx_wxflatnotebook_getpageenabled(wxFlatNotebook * fnb, int page) {
    return fnb->GetEnabled(page);
}

void bmx_wxflatnotebook_setactivetabtextcolour(wxFlatNotebook * fnb, MaxColour * colour) {
    fnb->SetActiveTabTextColour(colour->Colour());
}

MaxColour * bmx_wxflatnotebook_getgradientcolorfrom(wxFlatNotebook * fnb) {
	wxColour c(fnb->GetGradientColorFrom());
    return new MaxColour(c);
}

MaxColour * bmx_wxflatnotebook_getgradientcolorto(wxFlatNotebook * fnb) {
	wxColour c(fnb->GetGradientColorTo());
    return new MaxColour(c);
}

MaxColour * bmx_wxflatnotebook_getgradientcolorborder(wxFlatNotebook * fnb) {
	wxColour c(fnb->SetGradientColorBorder());
    return new MaxColour(c);
}

MaxColour * bmx_wxflatnotebook_getactivetabtextcolour(wxFlatNotebook * fnb) {
	wxColour c(fnb->GetActiveTabTextColour());
    return new MaxColour(c);
}

MaxColour * bmx_wxflatnotebook_getnonactivetabtextcolour(wxFlatNotebook * fnb) {
	wxColour c(fnb->GetNonActiveTabTextColour());
    return new MaxColour(c);
}

void bmx_wxflatnotebook_setnonactivetabtextcolour(wxFlatNotebook * fnb, MaxColour * colour) {
    fnb->SetNonActiveTabTextColour(colour->Colour());
}

wxPanel * bmx_wxflatnotebook_gettabarea(wxFlatNotebook * fnb) {
    return fnb->GetTabArea();
}

MaxColour * bmx_wxflatnotebook_gettabareacolour(wxFlatNotebook * fnb) {
	wxColour c(fnb->GetTabAreaColour());
    return new MaxColour(c);
}

void bmx_wxflatnotebook_settabareacolour(wxFlatNotebook * fnb, MaxColour * colour) {
    fnb->SetTabAreaColour(colour->Colour());
}

MaxColour * bmx_wxflatnotebook_getactivetabcolour(wxFlatNotebook * fnb) {
	wxColour c(fnb->GetActiveTabColour());
    return new MaxColour(c);
}

void bmx_wxflatnotebook_setactivetabcolour(wxFlatNotebook * fnb, MaxColour * colour) {
    fnb->SetActiveTabColour(colour->Colour());
}

int bmx_wxflatnotebook_getpadding(wxFlatNotebook * fnb) {
    return fnb->GetPadding();
}

void bmx_wxflatnotebook_setcustomizeoptions(wxFlatNotebook * fnb, long options) {
    fnb->SetCustomizeOptions(options);
}

long bmx_wxflatnotebook_getcustomizeoptions(wxFlatNotebook * fnb) {
    return fnb->GetCustomizeOptions();
}

void bmx_wxflatnotebook_setforceselection(wxFlatNotebook * fnb, bool force) {
    fnb->SetForceSelection(force);
}

bool bmx_wxflatnotebook_getforceselection(wxFlatNotebook * fnb) {
    return fnb->GetForceSelection();
}

wxBoxSizer * bmx_wxflatnotebook_getmainsizer(wxFlatNotebook * fnb) {
    return fnb->GetMainSizer();
}


