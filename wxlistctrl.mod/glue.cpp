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

MaxListCtrl::MaxListCtrl(BBObject * handle, wxWindow * parent, wxWindowID id, int x, int y, int w, int h, long style)
	: wxListCtrl(parent, id, wxPoint(x, y), wxSize(w, h), style)
{
	wxbind(this, handle);
}

MaxListCtrl::~MaxListCtrl() {
	wxunbind(this);
}


MaxListItem::MaxListItem(wxListItem & ic)
	: item(ic)
{
}

wxListItem & MaxListItem::Item() {
	return item;
}

MaxListItem::~MaxListItem() {
}

// *********************************************

MaxListCtrl * bmx_wxlistctrl_create(BBObject * handle, wxWindow * parent, int id, int x, int y, int w, int h, long style) {
	return new MaxListCtrl(handle, parent, id, x, y, w, h, style);
}

bool bmx_wxlistctrl_arrange(wxListCtrl * list, int flag) {
	return list->Arrange(flag);
}

void bmx_wxlistctrl_assignimagelist(wxListCtrl * list, wxImageList * imageList, int which) {
	list->AssignImageList(imageList, which);
	wxunbind((wxObject *)imageList);
}

void bmx_wxlistctrl_clearall(wxListCtrl * list) {
	list->ClearAll();
}

bool bmx_wxlistctrl_deleteallitems(wxListCtrl * list) {
	return list->DeleteAllItems();
}

bool bmx_wxlistctrl_deletecolumn(wxListCtrl * list, int col) {
	return list->DeleteColumn(col);
}

bool bmx_wxlistctrl_deleteitem(wxListCtrl * list, long item) {
	return list->DeleteItem(item);
}

void bmx_wxlistctrl_editlabel(wxListCtrl * list, long item) {
	list->EditLabel(item);
}

bool bmx_wxlistctrl_ensurevisible(wxListCtrl * list, long item) {
	return list->EnsureVisible(item);
}

long bmx_wxlistctrl_finditem(wxListCtrl * list, long start, BBString * text, bool partial) {
	return list->FindItem(start, wxStringFromBBString(text), partial);
}

long bmx_wxlistctrl_finditemdata(wxListCtrl * list, long start, BBObject * data) {
	return list->FindItem(start, wxPtrToUInt((void *)data));
}

long bmx_wxlistctrl_finditematpos(wxListCtrl * list, long start, int x, int y, int direction) {
	return list->FindItem(start, wxPoint(x, y), direction);
}

bool bmx_wxlistctrl_getcolumn(wxListCtrl * list, int col, MaxListItem * item) {
	return list->GetColumn(col, item->Item());
}

int bmx_wxlistctrl_getcolumncount(wxListCtrl * list) {
	return list->GetColumnCount();
}

int bmx_wxlistctrl_getcolumnwidth(wxListCtrl * list, int col) {
	return list->GetColumnWidth(col);
}

int bmx_wxlistctrl_getcountperpage(wxListCtrl * list) {
	return list->GetCountPerPage();
}

wxTextCtrl * bmx_wxlistctrl_geteditcontrol(wxListCtrl * list) {
	return list->GetEditControl();
}

wxImageList * bmx_wxlistctrl_getimagelist(wxListCtrl * list, int which) {
	return list->GetImageList(which);
}

bool bmx_wxlistctrl_getitem(wxListCtrl * list, MaxListItem * item) {
	return list->GetItem(item->Item());
}

MaxColour * bmx_wxlistctrl_getitembackgroundcolour(wxListCtrl * list, long item) {
	wxColour c(list->GetItemBackgroundColour(item));
	return new MaxColour(c);
}

int bmx_wxlistctrl_getitemcount(wxListCtrl * list) {
	return list->GetItemCount();
}

BBObject * bmx_wxlistctrl_getitemdata(wxListCtrl * list, long item) {
	return (BBObject*)wxUIntToPtr(list->GetItemData(item));
}

MaxFont * bmx_wxlistctrl_getitemfont(wxListCtrl * list, long item) {
	wxFont f(list->GetItemFont(item));
	return new MaxFont(f);
}

bool bmx_wxlistctrl_getitemposition(wxListCtrl * list, long item, int * x, int * y) {
	wxPoint p;
	bool ret = list->GetItemPosition(item, p);
	*x = p.x;
	*y = p.y;
	return ret;
}

bool bmx_wxlistctrl_getitemrect(wxListCtrl * list, long item, int * x, int * y, int * w, int * h, int code) {
	wxRect r;
	bool ret = list->GetItemRect(item, r, code);
	*x = r.x;
	*y = r.y;
	*w = r.width;
	*h = r.height;
	return ret;
}

bool bmx_wxlistctrl_getsubitemrect(wxListCtrl * list, long item, long subitem, int * x, int * y, int * w, int * h, int code) {
#ifdef WIN32
	wxRect r;
	bool ret = list->GetSubItemRect(item, subitem, r, code);
	*x = r.x;
	*y = r.y;
	*w = r.width;
	*h = r.height;
	return ret;
#else
	return 0;
#endif
}

void bmx_wxlistctrl_getitemspacing(wxListCtrl * list, int * w, int * h) {
	wxSize s = list->GetItemSpacing();
	*w = s.x;
	*h = s.y;
}

int bmx_wxlistctrl_getitemstate(wxListCtrl * list, long item, long stateMask) {
	return list->GetItemState(item , stateMask);
}

BBString * bmx_wxlistctrl_getitemtext(wxListCtrl * list, long item) {
	return bbStringFromWxString(list->GetItemText(item));
}

MaxColour * bmx_wxlistctrl_getitemtextcolour(wxListCtrl * list, long item) {
	wxColour c(list->GetItemTextColour(item));
	return new MaxColour(c);
}

long bmx_wxlistctrl_getnextitem(wxListCtrl * list, long item, int geometry, int state) {
	return list->GetNextItem(item, geometry, state);
}

int bmx_wxlistctrl_getselecteditemcount(wxListCtrl * list) {
	return list->GetSelectedItemCount();
}

MaxColour * bmx_wxlistctrl_gettextcolour(wxListCtrl * list) {
	wxColour c(list->GetTextColour());
	return new MaxColour(c);
}

long bmx_wxlistctrl_gettopitem(wxListCtrl * list) {
	return list->GetTopItem();
}

void bmx_wxlistctrl_getviewrect(wxListCtrl * list, int * x, int * y, int * w, int * h) {
	wxRect r = list->GetViewRect();
	*x = r.x;
	*y = r.y;
	*w = r.width;
	*h = r.height;
}

long bmx_wxlistctrl_hittest(wxListCtrl * list, int x, int y, int flags) {
	return list->HitTest(wxPoint(x, y), flags);
}

long bmx_wxlistctrl_insertcolumn(wxListCtrl * list, long col, BBString * heading, int format, int width) {
	return list->InsertColumn(col, wxStringFromBBString(heading), format, width);
}

long bmx_wxlistctrl_insertcolumnitem(wxListCtrl * list, long col, MaxListItem * info) {
	return list->InsertColumn(col, info->Item());
}

long bmx_wxlistctrl_insertitem(wxListCtrl * list, MaxListItem * item) {
	return list->InsertItem(item->Item());
}

long bmx_wxlistctrl_insertstringitem(wxListCtrl * list, long index, BBString * label) {
	return list->InsertItem(index, wxStringFromBBString(label));
}

long bmx_wxlistctrl_insertimageitem(wxListCtrl * list, long index, int imageIndex) {
	return list->InsertItem(index, imageIndex);
}

long bmx_wxlistctrl_insertimagestringitem(wxListCtrl * list, long index, BBString * label, int imageIndex) {
	return list->InsertItem(index, wxStringFromBBString(label), imageIndex);
}

void bmx_wxlistctrl_refreshitem(wxListCtrl * list, long item) {
	list->RefreshItem(item);
}

void bmx_wxlistctrl_refreshitems(wxListCtrl * list, long itemFrom, long itemTo) {
	list->RefreshItems(itemFrom, itemTo);
}

bool bmx_wxlistctrl_scrolllist(wxListCtrl * list, int dx, int dy) {
	return list->ScrollList(dx, dy);
}

void bmx_wxlistctrl_setbackgroundcolour(wxListCtrl * list, MaxColour * colour) {
	list->SetBackgroundColour(colour->Colour());
}

bool bmx_wxlistctrl_setcolumn(wxListCtrl * list, int col, MaxListItem * item) {
	return list->SetColumn(col, item->Item());
}

bool bmx_wxlistctrl_setcolumnwidth(wxListCtrl * list, int col, int width) {
	return list->SetColumnWidth(col, width);
}

void bmx_wxlistctrl_setimagelist(wxListCtrl * list, wxImageList * imageList, int which) {
	list->SetImageList(imageList, which);
}

bool bmx_wxlistctrl_setitem(wxListCtrl * list, MaxListItem * item) {
	return list->SetItem(item->Item());
}

long bmx_wxlistctrl_setstringitem(wxListCtrl * list, long item, int col, BBString * label, int imageId) {
	return list->SetItem(item, col, wxStringFromBBString(label), imageId);
}

void bmx_wxlistctrl_setitembackgroundcolour(wxListCtrl * list, long item, MaxColour * colour) {
	list->SetItemBackgroundColour(item, colour->Colour());
}

void bmx_wxlistctrl_setitemcount(wxListCtrl * list, long count) {
	list->SetItemCount(count);
}

bool bmx_wxlistctrl_setitemdata(wxListCtrl * list, long item, BBObject * data) {
	return list->SetItemData(item, wxPtrToUInt((void *)data));
}

void bmx_wxlistctrl_setitemfont(wxListCtrl * list, long item, MaxFont * font) {
	list->SetItemFont(item, font->Font());
}

bool bmx_wxlistctrl_setitemimage(wxListCtrl * list, long item, int image) {
	return list->SetItemImage(item, image);
}

bool bmx_wxlistctrl_setitemcolumnimage(wxListCtrl * list, long item, int col, int image) {
	return list->SetItemColumnImage(item, col, image);
}

bool bmx_wxlistctrl_setitemposition(wxListCtrl * list, long item, int x, int y) {
	return list->SetItemPosition(item, wxPoint(x, y));
}

bool bmx_wxlistctrl_setitemstate(wxListCtrl * list, long item, long state, long stateMask) {
	return list->SetItemState(item , state, stateMask);
}

void bmx_wxlistctrl_setitemtext(wxListCtrl * list, long item, BBString * text) {
	list->SetItemText(item, wxStringFromBBString(text));
}

void bmx_wxlistctrl_setitemtextcolour(wxListCtrl * list, long item, MaxColour * colour) {
	list->SetItemTextColour(item, colour->Colour());
}

void bmx_wxlistctrl_setsinglestyle(wxListCtrl * list, long style, bool add) {
	list->SetSingleStyle(style, add);
}

void bmx_wxlistctrl_settextcolour(wxListCtrl * list, MaxColour * colour) {
	list->SetTextColour(colour->Colour());
}

void bmx_wxlistctrl_setwindowstyleflag(wxListCtrl * list, long style) {
	list->SetWindowStyleFlag(style);
}



// *********************************************

MaxListItem * bmx_wxlistitem_create() {
	wxListItem i;
	return new MaxListItem(i);
}

void bmx_wxlistitem_delete(MaxListItem * item) {
	delete item;
}

void bmx_wxlistitem_clear(MaxListItem * item) {
	item->Item().Clear();
}

wxListColumnFormat bmx_wxlistitem_getalign(MaxListItem * item) {
	return item->Item().GetAlign();
}

MaxColour * bmx_wxlistitem_getbackgroundcolour(MaxListItem * item) {
	wxColour c(item->Item().GetBackgroundColour());
	return new MaxColour(c);
}

int bmx_wxlistitem_getcolumn(MaxListItem * item) {
	return item->Item().GetColumn();
}

BBObject * bmx_wxlistitem_getdata(MaxListItem * item) {
	return (BBObject *)item->Item().GetData();
}

MaxFont * bmx_wxlistitem_getfont(MaxListItem * item) {
	wxFont f(item->Item().GetFont());
	return new MaxFont(f);
}

long bmx_wxlistitem_getid(MaxListItem * item) {
	return item->Item().GetId();
}

int bmx_wxlistitem_getimage(MaxListItem * item) {
	return item->Item().GetImage();
}

long bmx_wxlistitem_getmask(MaxListItem * item) {
	return item->Item().GetMask();
}

long bmx_wxlistitem_getstate(MaxListItem * item) {
	return item->Item().GetState();
}

BBString * bmx_wxlistitem_gettext(MaxListItem * item) {
	return bbStringFromWxString(item->Item().GetText());
}

MaxColour * bmx_wxlistitem_gettextcolour(MaxListItem * item) {
	wxColour c(item->Item().GetTextColour());
	return new MaxColour(c);
}

int bmx_wxlistitem_getwidth(MaxListItem * item) {
	return item->Item().GetWidth();
}

void bmx_wxlistitem_setalign(MaxListItem * item, wxListColumnFormat align) {
	item->Item().SetAlign(align);
}

void bmx_wxlistitem_setbackgroundcolour(MaxListItem * item, MaxColour * colour) {
	item->Item().SetBackgroundColour(colour->Colour());
}

void bmx_wxlistitem_setcolumn(MaxListItem * item, int col) {
	item->Item().SetColumn(col);
}

void bmx_wxlistitem_setdata(MaxListItem * item, BBObject * data) {
	item->Item().SetData((void*)data);
}

void bmx_wxlistitem_setfont(MaxListItem * item, MaxFont * font) {
	item->Item().SetFont(font->Font());
}

void bmx_wxlistitem_setid(MaxListItem * item, long id) {
	item->Item().SetId(id);
}

void bmx_wxlistitem_setimage(MaxListItem * item, int image) {
	item->Item().SetImage(image);
}

void bmx_wxlistitem_setmask(MaxListItem * item, long mask) {
	item->Item().SetMask(mask);
}

void bmx_wxlistitem_setstate(MaxListItem * item, long state) {
	item->Item().SetState(state);
}

void bmx_wxlistitem_setstatemask(MaxListItem * item, long stateMask) {
	item->Item().SetStateMask(stateMask);
}

void bmx_wxlistitem_settext(MaxListItem * item, BBString * text) {
	item->Item().SetText(wxStringFromBBString(text));
}

void bmx_wxlistitem_settextcolour(MaxListItem * item, MaxColour * colour) {
	item->Item().SetTextColour(colour->Colour());
}

void bmx_wxlistitem_setwidth(MaxListItem * item, int width) {
	item->Item().SetWidth(width);
}




int bmx_wxlistctrl_geteventtype(int type) {
	switch(type) {
		case 700: return wxEVT_COMMAND_LIST_BEGIN_DRAG;
		case 701: return wxEVT_COMMAND_LIST_BEGIN_RDRAG;
		case 702: return wxEVT_COMMAND_LIST_BEGIN_LABEL_EDIT;
		case 703: return wxEVT_COMMAND_LIST_END_LABEL_EDIT;
		case 704: return wxEVT_COMMAND_LIST_DELETE_ITEM;
		case 705: return wxEVT_COMMAND_LIST_DELETE_ALL_ITEMS;
		case 708: return wxEVT_COMMAND_LIST_ITEM_SELECTED;
		case 709: return wxEVT_COMMAND_LIST_ITEM_DESELECTED;
		case 710: return wxEVT_COMMAND_LIST_KEY_DOWN;
		case 711: return wxEVT_COMMAND_LIST_INSERT_ITEM;
		case 712: return wxEVT_COMMAND_LIST_COL_CLICK;
		case 713: return wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK;
		case 714: return wxEVT_COMMAND_LIST_ITEM_MIDDLE_CLICK;
		case 715: return wxEVT_COMMAND_LIST_ITEM_ACTIVATED;
		case 716: return wxEVT_COMMAND_LIST_CACHE_HINT;
		case 717: return wxEVT_COMMAND_LIST_COL_RIGHT_CLICK;
		case 718: return wxEVT_COMMAND_LIST_COL_BEGIN_DRAG;
		case 719: return wxEVT_COMMAND_LIST_COL_DRAGGING;
		case 720: return wxEVT_COMMAND_LIST_COL_END_DRAG;
		case 721: return wxEVT_COMMAND_LIST_ITEM_FOCUSED;
	}
	
	return 0;
}
