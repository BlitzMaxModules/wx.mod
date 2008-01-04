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

Rem
bbdoc: wxApp
End Rem
Module wx.wxApp

ModuleInfo "Version: 1.00"
ModuleInfo "License: MIT"
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
bbdoc: The wxApp type represents the application itself.
about: It is used to:
<ul>
<li>set and get application-wide properties</li>
<li>implement the windowing system message or event loop</li>
<li>initiate application processing via wxApp::OnInit</li>
<li>allow default processing of events not handled by other objects in the application.</li>
</ul>
End Rem
Type wxApp Abstract

	Global app:wxApp
	
	Method New()
		app = Self
	End Method

	Rem
	bbdoc: This must be provided by the application, and will usually create the application's main window, optionally calling wxApp::SetTopWindow.
	about: You may use OnExit to clean up anything initialized here, provided that the method returns true.
	<p>
	Notice that if you want to to use the command line processing provided by wxWidgets you have to call the
	base type version in the derived type OnInit().
	</p>
	<p>
	Return true to continue processing, false to exit the application immediately.
	</p>
	End Rem
	Method OnInit:Int() Abstract

	Function _OnInit:Int()
		Return app.OnInit()
	End Function

	Rem
	bbdoc: TODO
	End Rem
	Method Run:Int()
		Return bmx_app_wxentry()
	End Method
	
	Rem
	bbdoc: Sets the 'top' window.
	about: You can call this from within wxApp::OnInit to let wxWidgets know which is the main window.
	You don't have to set the top window; it is only a convenience so that (for example) certain dialogs without
	parents can use a specific window as the top window. If no top window is specified by the application,
	wxWidgets just uses the first frame or dialog in its top-level window list, when it needs to use the top window.
	End Rem
	Method SetTopWindow(window:wxWindow)
		bmx_wxapp_settopwindow(window.wxObjectPtr)
	End Method
	
	Rem
	bbdoc: Sets the name of the application.
	about: The name may be used in dialogs (for example by the document/view framework). A default name is set by
	wxWidgets.
	End Rem
	Method SetAppName(name:String)
		bmx_wxapp_setappname(name)
	End Method
	
	Rem
	bbdoc: Yields control to pending messages in the windowing system.
	about: This can be useful, for example, when a time-consuming process writes to a text window.
	Without an occasional yield, the text window will not be updated properly, and on systems with
	cooperative multitasking, such as Windows 3.1 other processes will not respond.
	<p>
	Caution should be exercised, however, since yielding may allow the user to perform actions which
	are not compatible with the current task. Disabling menu items or whole menus during processing
	can avoid unwanted reentrance of code: see ::wxSafeYield for a better function.
	</p>
	<p>
	Note that Yield() will not flush the message logs. This is intentional as calling Yield() is
	usually done to quickly update the screen and popping up a message box dialog may be undesirable.
	If you do wish to flush the log messages immediately (otherwise it will be done during the next
	idle loop iteration), call wxLog::FlushActive.
	</p>
	<p>
	Calling Yield() recursively is normally an error and an assert failure is raised in debug build
	if such situation is detected. However if the onlyIfNeeded parameter is true, the method will just
	silently return false instead.
	</p>
	End Rem
	Method Yield:Int(onlyIfNeeded:Int = False)
		Return bmx_wxapp_yield(onlyIfNeeded)
	End Method
	
End Type

Rem
bbdoc: Returns a reference to the application object
End Rem
Function wxGetApp:wxApp()
	Return wxApp.app
End Function

Rem
bbdoc: 
End Rem
Type wxAppMain Extends wxApp Abstract

	Method Run:Int()
		bmx_wxapp_setownmain()
		Return bmx_app_wxentry()
	End Method

	Rem
	bbdoc: 
	End Rem
	Method Dispatch:Int()
		Return bmx_wxapp_dispatch()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method MainLoop:Int() Abstract

	Function _MainLoop:Int()
		Return wxAppMain(app).MainLoop()
	End Function
	
	Rem
	bbdoc: 
	End Rem
	Method Pending:Int()
		Return bmx_wxapp_pending()
	End Method
	
	Method ProcessIdle:Int()
		Return bmx_wxapp_processidle()
	End Method

End Type
