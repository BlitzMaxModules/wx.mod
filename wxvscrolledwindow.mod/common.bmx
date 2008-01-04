' Copyright (c) 2007,2008 Bruce A Henderson
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
Import wx.wxPanel
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

	Function bmx_wxvscrolledwindow_create:Byte Ptr(handle:Object, parent:Byte Ptr, id:Int, x:Int, y:Int, w:Int, h:Int, style:Int)
	Function bmx_wxvscrolledwindow_getfirstvisibleline:Int(handle:Byte Ptr)
	Function bmx_wxvscrolledwindow_getlastvisibleline:Int(handle:Byte Ptr)
	Function bmx_wxvscrolledwindow_getlinecount:Int(handle:Byte Ptr)
	Function bmx_wxvscrolledwindow_getvisiblebegin:Int(handle:Byte Ptr)
	Function bmx_wxvscrolledwindow_getvisibleend:Int(handle:Byte Ptr)
	Function bmx_wxvscrolledwindow_hittest:Int(handle:Byte Ptr, x:Int, y:Int)
	Function bmx_wxvscrolledwindow_isvisible:Int(handle:Byte Ptr, line:Int)
	Function bmx_wxvscrolledwindow_refreshline(handle:Byte Ptr, line:Int)
	Function bmx_wxvscrolledwindow_refreshlines(handle:Byte Ptr, fromline:Int, toLint:Int)
	Function bmx_wxvscrolledwindow_refreshall(handle:Byte Ptr)
	Function bmx_wxvscrolledwindow_scrolllines:Int(handle:Byte Ptr, lines:Int)
	Function bmx_wxvscrolledwindow_scrollpages:Int(handle:Byte Ptr, pages:Int)
	Function bmx_wxvscrolledwindow_scrolltoline:Int(handle:Byte Ptr, line:Int)
	Function bmx_wxvscrolledwindow_setlinecount(handle:Byte Ptr, count:Int)

End Extern

