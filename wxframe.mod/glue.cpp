#include "glue.h"

// ---------------------------------------------------------------------------------------


BEGIN_EVENT_TABLE(MaxFrame, wxFrame)
END_EVENT_TABLE()

MaxFrame::MaxFrame(BBObject * handle, wxWindow* parent, wxWindowID id, const wxString& title, int x,
		int y, int w, int h, long style)
       : wxFrame(parent, id, title, wxPoint(x, y), wxSize(w,h), style)
{
	wxbind(this, handle);
}

MaxFrame::~MaxFrame() {
	wxunbind(this);
}

MaxStatusBar * MaxFrame::OnCreateStatusBar(int number, long style, wxWindowID id, const wxString& name) {
	MaxStatusBar * statusbar = new MaxStatusBar(this, style, id, name);
	statusbar->SetFieldsCount(number);
	return statusbar;
}


MaxToolBar * MaxFrame::OnCreateToolBar(long style, wxWindowID id, const wxString& name) {
	return new MaxToolBar(this, style, id, name);
}

// ---------------------------------------------------------------------------------------


MaxFrame * bmx_wxframe_create(BBObject * maxHandle, wxWindow* parent, wxWindowID id, BBString * title, int x,
		int y, int w, int h, long style) {
		
	return new MaxFrame(maxHandle, parent, id, wxStringFromBBString(title), x, y, w, h, style);
}

void bmx_wxframe_setmenubar(wxFrame * frame, MaxMenuBar * menubar) {
	frame->SetMenuBar(menubar);
}

MaxStatusBar * bmx_wxframe_createstatusbar(wxFrame * frame, int number, long style, wxWindowID id) {
	return (MaxStatusBar *)frame->CreateStatusBar(number, style, id);
}

void bmx_wxframe_setstatustext(wxFrame * frame, BBString * text, int number) {
	frame->SetStatusText(wxStringFromBBString(text), number);
}

wxMenuBar * bmx_wxframe_getmenubar(wxFrame * frame) {
	return frame->GetMenuBar();
}

void bmx_wxframe_setstatusbar(wxFrame * frame, wxStatusBar * statusbar) {
	if (statusbar) {
		frame->SetStatusBar(statusbar);
	} else {
		frame->SetStatusBar(NULL);
	}
}

wxStatusBar * bmx_wxframe_getstatusbar(wxFrame * frame) {
	return frame->GetStatusBar();
}

void bmx_wxframe_positionstatusbar(MaxFrame * frame) {
	frame->PositionStatusBar();
}

wxToolBar * bmx_wxframe_createtoolbar(wxFrame * frame, long style, wxWindowID id) {
	return frame->CreateToolBar(style, id);
}

wxToolBar * bmx_wxframe_gettoolbar(wxFrame * frame) {
	return frame->GetToolBar();
}

void bmx_wxframe_settoolbar(wxFrame * frame, wxToolBar * toolbar) {
	frame->SetToolBar(toolbar);
}

void bmx_wxframe_sendsizeevent(wxFrame * frame) {
	frame->SendSizeEvent();
}


// *********************************************


