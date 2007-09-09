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


MaxMenu::MaxMenu(BBObject * handle, const wxString& title, long style)
	: wxMenu(title, style)
{
	wxbind(this, handle);
}

MaxMenu::~MaxMenu() {
	wxunbind(this);
}

// *********************************************


MaxMenu * bmx_wxmenu_create(BBObject * maxHandle, BBString * title, long style) {
	return new MaxMenu(maxHandle, wxStringFromBBString(title), style);
}

wxMenuItem * bmx_wxmenu_append(wxMenu * menu, int id, BBString * item, BBString * helpString, wxItemKind kind) {
	return menu->Append(id, wxStringFromBBString(item), wxStringFromBBString(helpString), kind);
}

wxMenuItem * bmx_wxmenu_appendMenu(wxMenu * menu, int id, BBString * item, MaxMenu * subMenu, BBString * helpString) {
	return menu->Append(id, wxStringFromBBString(item), subMenu, wxStringFromBBString(helpString));
}

wxMenuItem * bmx_wxmenu_appendseparator(wxMenu * menu) {
	return menu->AppendSeparator();
}

wxMenuItem * bmx_wxmenu_appendcheckitem(wxMenu * menu, int id, BBString * item, BBString * helpString) {
	return menu->AppendCheckItem(id, wxStringFromBBString(item), wxStringFromBBString(helpString));
}

wxMenuItem * bmx_wxmenu_appendradioitem(wxMenu * menu, int id, BBString * item, BBString * helpString) {
	return menu->AppendRadioItem(id, wxStringFromBBString(item), wxStringFromBBString(helpString));
}

void bmx_wxmenu_break(wxMenu * menu) {
	menu->Break();
}

wxMenuItem * bmx_wxmenu_appendsubmenu(wxMenu * menu, wxMenu * submenu, BBString * item, BBString * helpString) {
	return menu->AppendSubMenu(submenu, wxStringFromBBString(item), wxStringFromBBString(helpString));
}

void bmx_wxmenu_check(wxMenu * menu, int id, bool value) {
	menu->Check(id, value);
}

void bmx_wxmenu_delete(wxMenu * menu, int id) {
	menu->Delete(id);
}

void bmx_wxmenu_destroy(wxMenu * menu, int id) {
	menu->Destroy(id);
}

void bmx_wxmenu_enable(wxMenu * menu, int id, bool value) {
	menu->Enable(id, value);
}

int bmx_wxmenu_finditem(wxMenu * menu, BBString * itemString) {
	return menu->FindItem(wxStringFromBBString(itemString));
}

wxMenuItem * bmx_wxmenu_finditembyposition(wxMenu * menu, int pos) {
	return menu->FindItemByPosition(pos);
}

BBString * bmx_wxmenu_gethelpstring(wxMenu * menu, int id) {
	return bbStringFromWxString(menu->GetHelpString(id));
}

BBString * bmx_wxmenu_getlabel(wxMenu * menu, int id) {
	return bbStringFromWxString(menu->GetLabel(id));
}

int bmx_wxmenu_getmenuitemcount(wxMenu * menu) {
	return menu->GetMenuItemCount();
}

BBString * bmx_wxmenu_gettitle(wxMenu * menu) {
	return bbStringFromWxString(menu->GetTitle());
}

wxMenuItem * bmx_wxmenu_insert(wxMenu * menu, int pos, int id, BBString * item, BBString * helpString, wxItemKind kind) {
	return menu->Insert(pos, id, wxStringFromBBString(item), wxStringFromBBString(helpString), kind);
}

wxMenuItem * bmx_wxmenu_insertcheckitem(wxMenu * menu, int pos, int id, BBString * item, BBString * helpString) {
	return menu->InsertCheckItem(pos, id, wxStringFromBBString(item), wxStringFromBBString(helpString));
}

wxMenuItem * bmx_wxmenu_insertradioitem(wxMenu * menu, int pos, int id, BBString * item, BBString * helpString) {
	return menu->InsertRadioItem(pos, id, wxStringFromBBString(item), wxStringFromBBString(helpString));
}

wxMenuItem * bmx_wxmenu_insertseparator(wxMenu * menu, int pos) {
	return menu->InsertSeparator(pos);
}

bool bmx_wxmenu_ischecked(wxMenu * menu, int id) {
	return menu->IsChecked(id);
}

bool bmx_wxmenu_isenabled(wxMenu * menu, int id) {
	return menu->IsEnabled(id);
}

wxMenuItem * bmx_wxmenu_prepend(wxMenu * menu, int id, BBString * item, BBString * helpString, wxItemKind kind) {
	return menu->Prepend(id, wxStringFromBBString(item), wxStringFromBBString(helpString), kind);
}

wxMenuItem * bmx_wxmenu_prependcheckitem(wxMenu * menu, int id, BBString * item, BBString * helpString) {
	return menu->PrependCheckItem(id, wxStringFromBBString(item), wxStringFromBBString(helpString));
}

wxMenuItem * bmx_wxmenu_prependradioitem(wxMenu * menu, int id, BBString * item, BBString * helpString) {
	return menu->PrependRadioItem(id, wxStringFromBBString(item), wxStringFromBBString(helpString));
}

wxMenuItem * bmx_wxmenu_prependseparator(wxMenu * menu) {
	return menu->PrependSeparator();
}

void bmx_wxmenu_remove(wxMenu * menu, int id) {
	menu->Remove(id);
}

void bmx_wxmenu_sethelpstring(wxMenu * menu, int id, BBString * helpString) {
	menu->SetHelpString(id, wxStringFromBBString(helpString));
}

void bmx_wxmenu_setlabel(wxMenu * menu, int id, BBString * label) {
	menu->SetLabel(id, wxStringFromBBString(label));
}

void bmx_wxmenu_settitle(wxMenu * menu, BBString * title) {
	menu->SetTitle(wxStringFromBBString(title));
}

void bmx_wxmenu_updateui(wxMenu * menu, wxEvtHandler * source) {
	if (source) {
		menu->UpdateUI(source);
	} else {
		menu->UpdateUI();
	}
}


int bmx_wxmenu_geteventtype(int type) {
	switch(type) {
		case 421: return wxEVT_MENU_OPEN;
		case 422: return wxEVT_MENU_CLOSE;
		case 423: return wxEVT_MENU_HIGHLIGHT;
	}
	
	return 0;
}

