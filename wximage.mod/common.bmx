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

Import wx.wx
Import wx.wxPalette
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

	Function bmx_wximage_createempty:Byte Ptr(width:Int, height:Int)
	Function bmx_wximage_delete(handle:Byte Ptr)
	
	Function bmx_wximage_setrgb(handle:Byte Ptr, x:Int, y:Int, r:Int, g:Int, b:Int)
	Function bmx_wximage_rescale(handle:Byte Ptr, width:Int, height:Int, quality:Int)
	Function bmx_wximage_getwidth:Int(handle:Byte Ptr)
	Function bmx_wximage_resize(handle:Byte Ptr, width:Int, height:Int, x:Int, y:Int, red:Int, green:Int, blue:Int)
	Function bmx_wximage_rotate:Byte Ptr(handle:Byte Ptr, angle:Double, centreX:Int, centreY:Int, interpolating:Int, offsetX:Int Ptr, offsetY:Int Ptr)
	
	Function bmx_wximage_addhandler(handler:Byte Ptr)	
	Function bmx_wxpnghandler_create:Byte Ptr()
	Function bmx_wxxpmhandler_create:Byte Ptr()

End Extern


Const wxIMAGE_QUALITY_NORMAL:Int = 0
Const wxIMAGE_QUALITY_HIGH:Int = 1

Const wxIMAGE_RESOLUTION_INCHES:Int = 1
Const wxIMAGE_RESOLUTION_CM:Int = 2
