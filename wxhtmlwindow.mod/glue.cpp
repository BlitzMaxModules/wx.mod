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

MaxHtmlWindow::MaxHtmlWindow(BBObject * handle, wxWindow * parent, wxWindowID id, int x, int y,
		int w, int h, long style)
	: maxHandle(handle), wxHtmlWindow(parent, id, wxPoint(x, y), wxSize(w, h), style)
{
	wxbind(this, handle);
}

MaxHtmlWindow::~MaxHtmlWindow() {
	wxunbind(this);
}

wxHtmlOpeningStatus MaxHtmlWindow::OnOpeningURL(wxHtmlURLType type,const wxString& url, wxString *redirect) const {
	wxHtmlOpeningStatus status;

	*redirect = wxStringFromBBString(_wx_wxhtmlwindow_wxHtmlWindow__OnOpeningURL(maxHandle, type,
		bbStringFromWxString(url), &status));

	return status;
}

void MaxHtmlWindow::OnSetTitle(const wxString& title) const{
	_wx_wxhtmlwindow_wxHtmlWindow__OnSetTitle(maxHandle, bbStringFromWxString(title));
}


MaxHtmlProcessor::MaxHtmlProcessor(BBObject * handle)
	: maxHandle(handle)
{
	wxbind(this, handle);
}

MaxHtmlProcessor::~MaxHtmlProcessor() {
	wxunbind(this);
}

wxString MaxHtmlProcessor::Process(const wxString& text) const {
	return wxStringFromBBString(_wx_wxhtmlwindow_wxHtmlProcessor__Process(maxHandle, bbStringFromWxString(text)));
}


MaxHtmlLinkInfo::MaxHtmlLinkInfo(const wxHtmlLinkInfo & linkInfo)
{
	info = linkInfo;
}

wxHtmlLinkInfo & MaxHtmlLinkInfo::Info() {
	return info;
}


// *********************************************

BEGIN_EVENT_TABLE(MaxHtmlWindow, wxHtmlWindow)
END_EVENT_TABLE()


MaxHtmlWindow * bmx_wxhtmlwindow_create(BBObject * maxHandle, wxWindow * parent, wxWindowID id, int x, int y,
		int w, int h, long style) {

	return new MaxHtmlWindow(maxHandle, parent, id, x, y, w, h, style);
}

bool bmx_wxhtmlwindow_setpage(wxHtmlWindow * window, BBString * source) {
	return window->SetPage(wxStringFromBBString(source));
}


bool bmx_wxhtmlwindow_appendtopage(wxHtmlWindow * window, BBString * source) {
	return window->AppendToPage(wxStringFromBBString(source));
}

BBString * bmx_wxhtmlwindow_getopenedanchor(wxHtmlWindow * window) {
	return bbStringFromWxString(window->GetOpenedAnchor());
}

BBString * bmx_wxhtmlwindow_getopenedpage(wxHtmlWindow * window) {
	return bbStringFromWxString(window->GetOpenedPage());
}

BBString * bmx_wxhtmlwindow_getopenedpagetitle(wxHtmlWindow * window) {
	return bbStringFromWxString(window->GetOpenedPageTitle());
}

wxFrame * bmx_wxhtmlwindow_getrelatedframe(wxHtmlWindow * window) {
	return window->GetRelatedFrame();
}

bool bmx_wxhtmlwindow_historyback(wxHtmlWindow * window) {
	return window->HistoryBack();
}

bool bmx_wxhtmlwindow_hisotrycanback(wxHtmlWindow * window) {
	return window->HistoryCanBack();
}

bool bmx_wxhtmlwindow_historycanforward(wxHtmlWindow * window) {
	return window->HistoryCanForward();
}

void bmx_wxhtmlwindow_historyclear(wxHtmlWindow * window) {
	window->HistoryClear();
}

bool bmx_wxhtmlwindow_historyforward(wxHtmlWindow * window) {
	return window->HistoryForward();
}

bool bmx_wxhtmlwindow_loadpage(wxHtmlWindow * window, BBString * location) {
	return window->LoadPage(wxStringFromBBString(location));
}

void bmx_wxhtmlwindow_selectall(wxHtmlWindow * window) {
	window->SelectAll();
}

BBString * bmx_wxhtmlwindow_selectiontotext(wxHtmlWindow * window) {
	return bbStringFromWxString(window->SelectionToText());
}

void bmx_wxhtmlwindow_selectline(wxHtmlWindow * window, int x, int y) {
	window->SelectLine(wxPoint(x, y));
}

void bmx_wxhtmlwindow_selectword(wxHtmlWindow * window, int x, int y) {
	window->SelectWord(wxPoint(x, y));
}

void bmx_wxhtmlwindow_setborders(wxHtmlWindow * window, int size) {
	window->SetBorders(size);
}

void bmx_wxhtmlwindow_setfonts(wxHtmlWindow * window, BBString * normalFace, BBString * fixedFace, BBArray * sizes) {
	//window->SetFonts(wxStringFromBBString(normalFace), wxStringFromBBString(fixedFace), 
}

void bmx_wxhtmlwindow_setrelatedframe(wxHtmlWindow * window, wxFrame * frame, BBString * format) {
	window->SetRelatedFrame(frame, wxStringFromBBString(format));
}

void bmx_wxhtmlwindow_setrelatedstatusbar(wxHtmlWindow * window, int bar) {
	window->SetRelatedStatusBar(bar);
}

BBString * bmx_wxhtmlwindow_totext(wxHtmlWindow * window) {
	return bbStringFromWxString(window->ToText());
}


MaxHtmlLinkInfo * bmx_wxhtmllinkevent_getlinkinfo(wxHtmlLinkEvent & event) {
	return new MaxHtmlLinkInfo(event.GetLinkInfo());
}

void bmx_wxhtmlcellevent_getpoint(wxHtmlCellEvent & event, int * x, int * y) {
	wxPoint p = event.GetPoint();
	*x = p.x;
	*y = p.y;
}

void bmx_wxhtmlcellevent_setlinkclicked(wxHtmlCellEvent & event, bool clicked) {
	event.SetLinkClicked(clicked);
}

bool bmx_wxhtmlcellevent_getlinkclicked(wxHtmlCellEvent & event) {
	return event.GetLinkClicked();
}

wxHtmlCell * bmx_wxhtmlcellevent_getcell(wxHtmlCellEvent & event) {
	return event.GetCell();
}



const wxMouseEvent & bmx_wxhtmllinkinfo_getevent(MaxHtmlLinkInfo * info) {
	return * info->Info().GetEvent();
}

BBString * bmx_wxhtmllinkinfo_gethref(MaxHtmlLinkInfo * info) {
	return bbStringFromWxString(info->Info().GetHref());
}

BBString * bmx_wxhtmllinkinfo_gettarget(MaxHtmlLinkInfo * info) {
	return bbStringFromWxString(info->Info().GetTarget());
}

void bmx_wxhtmllinkinfo_delete(MaxHtmlLinkInfo * info) {
	delete info;
}


void bmx_wxhtmlwindow_addprocessor(wxHtmlWindow * window, wxHtmlProcessor * proc) {
	window->AddProcessor(proc);
}

MaxHtmlProcessor * bmx_wxhtmlprocessor_create(BBObject * handle) {
	return new MaxHtmlProcessor(handle);
}

void bmx_wxhtmlprocessor_enable(wxHtmlProcessor * proc, bool value) {
	proc->Enable(value);
}

bool bmx_wxhtmlprocessor_isenabled(wxHtmlProcessor * proc) {
	return proc->IsEnabled();
}


int bmx_wxhtmlevent_geteventtype(int type) {
	switch(type) {
		case 1000: return wxEVT_COMMAND_HTML_CELL_CLICKED;
		case 1001: return wxEVT_COMMAND_HTML_CELL_HOVER;
		case 1002: return wxEVT_COMMAND_HTML_LINK_CLICKED;
	}
	
	return 0;
}

