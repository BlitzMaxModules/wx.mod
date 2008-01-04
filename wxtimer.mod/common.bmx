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
	Function bmx_wxtimer_create:Byte Ptr(handle:Object, owner:Byte Ptr, id:Int)
	Function bmx_wxtimer_getinterval:Int(handle:Byte Ptr)
	Function bmx_wxtimer_isoneshot:Int(handle:Byte Ptr)
	Function bmx_wxtimer_isrunning:Int(handle:Byte Ptr)
	Function bmx_wxtimer_setowner(handle:Byte Ptr, owner:Byte Ptr, id:Int)
	Function bmx_wxtimer_start:Int(handle:Byte Ptr, milli:Int, oneshot:Int)
	Function bmx_wxtimer_stop(handle:Byte Ptr)
	
	Function bmx_wxtimerevent_getinterval:Int(evt:Byte Ptr)

	Function bmx_wxtimer_geteventtype:Int(evt:Int)
	
End Extern


Const wxTIMER_CONTINUOUS:Int = False
Const wxTIMER_ONE_SHOT:Int = True

Const wxEVT_TIMER:Int = 80
