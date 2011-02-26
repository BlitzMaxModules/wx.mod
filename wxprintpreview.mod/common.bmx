' Copyright (c) 2007-2011 Bruce A Henderson
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
Import wx.wxPrintout
Import wx.wxScrolledWindow
Import wx.wxFrame
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

	Function bmx_wxprintpreview_create:Byte Ptr(handle:Object, printout:Byte Ptr, printoutForPrinting:Byte Ptr, data:Byte Ptr)
	Function bmx_wxprintpreview_free(handle:Byte Ptr)
	Function bmx_wxprintpreview_getcanvas:Byte Ptr(handle:Byte Ptr)
	Function bmx_wxprintpreview_getcurrentpage:Int(handle:Byte Ptr)
	Function bmx_wxprintpreview_getframe:Byte Ptr(handle:Byte Ptr)
	Function bmx_wxprintpreview_getmaxpage:Int(handle:Byte Ptr)
	Function bmx_wxprintpreview_getminpage:Int(handle:Byte Ptr)
	Function bmx_wxprintpreview_getprintout:Byte Ptr(handle:Byte Ptr)
	Function bmx_wxprintpreview_getprintoutforprinting:Byte Ptr(handle:Byte Ptr)
	Function bmx_wxprintpreview_isok:Int(handle:Byte Ptr)
	Function bmx_wxprintpreview_paintpage:Int(handle:Byte Ptr, canvas:Byte Ptr, dc:Byte Ptr)
	Function bmx_wxprintpreview_paintpage_default:Int(handle:Byte Ptr, canvas:Byte Ptr, dc:Byte Ptr)
	Function bmx_wxprintpreview_print:Int(handle:Byte Ptr, prompt:Int)
	Function bmx_wxprintpreview_renderpage:Int(handle:Byte Ptr, pageNum:Int)
	Function bmx_wxprintpreview_setCanvas(handle:Byte Ptr, canvas:Byte Ptr)
	Function bmx_wxprintpreview_setcurrentpage(handle:Byte Ptr, pageNum:Int)
	Function bmx_wxprintpreview_setframe(handle:Byte Ptr, frame:Byte Ptr)
	Function bmx_wxprintpreview_setprintout(handle:Byte Ptr, printout:Byte Ptr)
	Function bmx_wxprintpreview_setzoom(handle:Byte Ptr, percent:Int)


End Extern
