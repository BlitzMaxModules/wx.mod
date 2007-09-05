' Copyright (c) 2007 Bruce A Henderson
' 
' Permission is hereby granted, free of charge, to any person obtaining a copy
' of this software and associated documentation files (the "Software"), to deal
' in the Software without restriction, including without limitation the rights
' to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
' copies of the Software, and to permit persons to whom the Software is
' furnished to do so, subject to the following conditions:
' 
' The above copyright notice and this permission notice shall be included in
' all copies or substantial portions of the Software.
' 
' THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
' IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
' FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
' AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
' LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
' OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
' THE SOFTWARE.
' 
SuperStrict

Rem
bbdoc: 
End Rem
Module wx.wxCheckBox

ModuleInfo "Version: 1.00"
ModuleInfo "License:"
ModuleInfo "Author: Bruce A Henderson"
ModuleInfo "Copyright: (c) 2007 Bruce A Henderson"
ModuleInfo "Modserver: BRL"

?linux
ModuleInfo "CC_OPTS: -D__WXGTK__"
ModuleInfo "CC_OPTS: -D_FILE_OFFSET_BITS=64"
ModuleInfo "CC_OPTS: -D_LARGE_FILES"
ModuleInfo "CC_OPTS: -DWX_PRECOMP"
?win32
ModuleInfo "CC_OPTS: -DHAVE_W32API_H"
ModuleInfo "CC_OPTS: -D__WXMSW__"
ModuleInfo "CC_OPTS: -D_UNICODE"
ModuleInfo "CC_OPTS: -DUNICODE"
?macos
ModuleInfo "CC_OPTS: -D__WXMAC__"
ModuleInfo "CC_OPTS: -D_FILE_OFFSET_BITS=64"
ModuleInfo "CC_OPTS: -D_LARGE_FILES"
ModuleInfo "CC_OPTS: -DWX_PRECOMP"
?

Import "common.bmx"

Rem
bbdoc: A checkbox is a labelled box which by default is either on (checkmark is visible) or off (no checkmark).
about: Optionally (when the wxCHK_3STATE style flag is set) it can have a third state, called the
mixed or undetermined state. Often this is used as a "Does Not Apply" state.
End Rem
Type wxCheckBox Extends wxControl

	Rem
	bbdoc: 
	End Rem
	Function CreateCheckBox:wxCheckBox(parent:wxWindow, id:Int, label:String = Null, x:Int = -1, y:Int = -1, ..
			w:Int = -1, h:Int = -1, style:Int = 0)
	
		Local this:wxCheckBox = New wxCheckBox
	
		this.wxObjectPtr = bmx_wxcheckbox_create(this, parent.wxObjectPtr, id, label, x, y, w, h, style)
	
		Return this
	End Function

	Rem
	bbdoc: Gets the state of a 2-state checkbox.
	returns: True if it is checked, false otherwise.
	End Rem
	Method GetValue:Int()
		Return bmx_wxcheckbox_getvalue(wxObjectPtr)
	End Method
	
	Rem
	bbdoc: Gets the state of a 3-state checkbox.
	returns: wxCHK_UNCHECKED when the checkbox is unchecked, wxCHK_CHECKED when it is checked and wxCHK_UNDETERMINED when it's in the undetermined state. Asserts when the function is used with a 2-state checkbox.
	End Rem
	Method Get3StateValue:Int()
		Return bmx_wxcheckbox_get3statevalue(wxObjectPtr)
	End Method
	
	Rem
	bbdoc: Returns whether or not the user can set the checkbox to the third state.
	returns: True if the user can set the third state of this checkbox, false if it can only be set programmatically or if it's a 2-state checkbox.
	End Rem
	Method Is3rdStateAllowedForUser:Int()
		Return bmx_wxcheckbox_is3rdstateallowedforuser(wxObjectPtr)
	End Method
	
	Rem
	bbdoc: Returns whether or not the checkbox is a 3-state checkbox.
	returns: True if this checkbox is a 3-state checkbox, false if it's a 2-state checkbox.
	End Rem
	Method Is3State:Int()
		Return bmx_wxcheckbox_is3state(wxObjectPtr)
	End Method
	
	Rem
	bbdoc: This is just a maybe more readable synonym for GetValue.
	about: just as the latter, it returns true if the checkbox is checked and false otherwise.
	End Rem
	Method IsChecked:Int()
		Return bmx_wxcheckbox_ischecked(wxObjectPtr)
	End Method
	
	Rem
	bbdoc: Sets the checkbox to the given state.
	about: This does not cause a wxEVT_COMMAND_CHECKBOX_CLICKED event to get emitted.
	End Rem
	Method SetValue(state:Int)
		bmx_wxcheckbox_setvalue(wxObjectPtr, state)
	End Method
	
	Rem
	bbdoc: Sets the checkbox to the given state.
	about: This does not cause a wxEVT_COMMAND_CHECKBOX_CLICKED event to get emitted.
	End Rem
	Method Set3StateValue(state:Int)
		bmx_wxcheckbox_set3statevalue(wxObjectPtr, state)
	End Method
		
End Type


Type TCheckBoxEventFactory Extends TEventFactory

	Method CreateEvent:wxEvent(wxEventPtr:Byte Ptr, evt:TEventHandler)
	
		If evt.eventType = wxEVT_COMMAND_CHECKBOX_CLICKED Then
			Return wxCommandEvent.create(wxEventPtr, evt)
		End If
		
		Return Null
	End Method

	Method GetEventType:Int(eventType:Int)
		If eventType = wxEVT_COMMAND_CHECKBOX_CLICKED Then
			Return bmx_wxcheckbox_geteventtype(eventType)
		End If
	End Method

End Type

New TCheckBoxEventFactory

