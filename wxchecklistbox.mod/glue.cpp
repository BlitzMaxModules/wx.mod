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


MaxCheckListBox::MaxCheckListBox(BBObject * handle, wxWindow * parent, wxWindowID id, const wxArrayString& array, int x, int y, int w, int h, long style)
	: wxCheckListBox(parent, id, wxPoint(x, y), wxSize(w, h), array, style)
{
	wxbind(this, handle);
}

MaxCheckListBox::~MaxCheckListBox() {
	wxunbind(this);

	// we need to free any items
	int count = GetCount();
	for (int i = 0; i < count; i++) {
		void * data = GetClientData(i);
		if (data) {
			BBRELEASE((BBObject*)data);
		}
	}
}

// *********************************************

BEGIN_EVENT_TABLE(MaxCheckListBox, wxCheckListBox)
END_EVENT_TABLE()

MaxCheckListBox * bmx_wxchecklistbox_create(BBObject * maxHandle, wxWindow * parent, wxWindowID id, BBArray * array, int x, int y, int w, int h, long style) {
	return new MaxCheckListBox(maxHandle, parent, id, bbStringArrayTowxArrayStr(array), x, y, w, h, style);
}

void bmx_wxchecklistbox_check(MaxCheckListBox * listbox, int item, bool check) {
	listbox->Check(item, check);
}

bool bmx_wxchecklistbox_ischecked(MaxCheckListBox * listbox, int item) {
	return listbox->IsChecked(item);
}

int bmx_wxchecklistbox_append(MaxCheckListBox * listbox, BBString * item) {
	return listbox->Append(wxStringFromBBString(item));
}

int bmx_wxchecklistbox_geteventtype(int type) {
	switch(type) {
		case 6: return wxEVT_COMMAND_CHECKLISTBOX_TOGGLED;
	}
	
	return 0;
}

