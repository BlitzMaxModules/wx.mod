' Copyright (c) 2007-2013 Bruce A Henderson
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

Import wx.wx
Import wx.wxDialog
Import wx.wxBookCtrlBase
Import BRL.Blitz


' headers :-)
?linux
Import "../lib/linux/wx/include/gtk2-unicode-release-static/*.h"
Import "../include/*.h"
?win32
Import "../lib/win32/mswu/*.h"
Import "../include/*.h"
?macosppc
Import "../lib/macosppc/wx/include/mac-unicode-release-static/*.h"
Import "../include/*.h"
?macosx86
Import "../lib/macosx86/wx/include/mac-unicode-release-static/*.h"
Import "../include/*.h"
?

Import "glue.cpp"

Extern

	Function bmx_wxpropertysheetdialog_create:Byte Ptr(handle:Object, parent:Byte Ptr, id:Int, title:String, x:Int, y:Int, w:Int, h:Int, style:Int)
	Function bmx_wxpropertysheetdialog_addbookctrl(handle:Byte Ptr, sizer:Byte Ptr)
	Function bmx_wxpropertysheetdialog_createbookctrl:Byte Ptr(handle:Byte Ptr)
	Function bmx_wxpropertysheetdialog_createbuttons(handle:Byte Ptr, flags:Int)
	Function bmx_wxpropertysheetdialog_getbookctrl:Byte Ptr(handle:Byte Ptr)
	Function bmx_wxpropertysheetdialog_getinnersizer:Byte Ptr(handle:Byte Ptr)
	Function bmx_wxpropertysheetdialog_getsheetstyle:Int(handle:Byte Ptr)
	Function bmx_wxpropertysheetdialog_layoutdialog(handle:Byte Ptr, centreFlags:Int)
	Function bmx_wxpropertysheetdialog_setbookctrl(handle:Byte Ptr, bookCtrl:Byte Ptr)

	Function bmx_wxpropertysheetdialog_addresourcehandler()
	
End Extern
