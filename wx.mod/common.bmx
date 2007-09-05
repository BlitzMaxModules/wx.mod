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

Import BRL.Map
Import BRL.Blitz

Import "consts.bmx"

?linux
Import "../lib/linux/wx/include/gtk2-unicode-release-static/*.h"
Import "../include/*.h"

' For dynamic linking :

Import "-lwx_gtk2u_aui-2.8"
Import "-lwx_gtk2u_xrc-2.8"
Import "-lwx_gtk2u_qa-2.8"
Import "-lwx_gtk2u_html-2.8"
Import "-lwx_gtk2u_adv-2.8"
Import "-lwx_gtk2u_core-2.8"
Import "-lwx_baseu_xml-2.8"
Import "-lwx_baseu_net-2.8"
Import "-lwx_baseu-2.8"
Import "-lwx_gtk2u_gl-2.8"
Import "-lwx_gtk2u_richtext-2.8"
Import "-lwxregexu-2.8"

Rem
Import "../lib/linux/libwx_gtk2u_aui-2.8.a"
Import "../lib/linux/libwx_gtk2u_xrc-2.8.a"
Import "../lib/linux/libwx_gtk2u_qa-2.8.a"
Import "../lib/linux/libwx_gtk2u_html-2.8.a"
Import "../lib/linux/libwx_gtk2u_adv-2.8.a"
Import "../lib/linux/libwx_gtk2u_core-2.8.a"
Import "../lib/linux/libwx_baseu_xml-2.8.a"
Import "../lib/linux/libwx_baseu_net-2.8.a"
Import "../lib/linux/libwx_baseu-2.8.a"
Import "../lib/linux/libwx_gtk2u_gl-2.8.a"
Import "../lib/linux/libwx_gtk2u_richtext-2.8.a"
Import "../lib/linux/libwxregexu-2.8.a"
End Rem
Import "-lgdk-x11-2.0"
Import "-latk-1.0"
Import "-lgdk_pixbuf-2.0"
Import "-lm"
Import "-lpango-1.0"
Import "-lgobject-2.0"
Import "-lgmodule-2.0"
Import "-ldl"
Import "-lgthread-2.0"
Import "-lrt"
Import "-lglib-2.0"
Import "-lXinerama"
Import "-lSM"
Import "-ltiff"
Import "-lgtk-x11-2.0"
' end of static linking

?win32
Import "../lib/win32/mswu/*.h"
Import "../include/*.h"

Import "-lwxmsw28u_aui"
Import "-lwxmsw28u_xrc"
Import "-lwxmsw28u_html"
Import "-lwxmsw28u_adv"
Import "-lwxmsw28u_core"
Import "-lwxbase28u_xml"
Import "-lwxbase28u_net"
Import "-lwxbase28u"
Import "-lwxjpeg"
Import "-lwxmsw28u_gl"
Import "-lwxpng"
Import "-lwxzlib"
Import "-lwxmsw28u_media"
Import "-lwxregexu"
Import "-lwxexpat"
Import "-lwxmsw28u_richtext"
Import "-lwxtiff"

Import "-ladvapi32"
Import "-lshell32"
Import "-lkernel32"
Import "-luser32"
Import "-lgdi32"
Import "-lcomdlg32"
Import "-lwinspool"
Import "-lwinmm"
Import "-lcomctl32"
Import "-lole32"
Import "-loleaut32"
Import "-luuid"
Import "-lrpcrt4"
Import "-lwsock32"
Import "-lodbc32"
?macosppc
Import "../lib/macosppc/wx/include/mac-unicode-release-static/*.h"
Import "../include/*.h"

Import "-lwx_macu_aui-2.8"
Import "-lwx_macu_xrc-2.8"
Import "-lwx_macu_qa-2.8"
Import "-lwx_macu_html-2.8"
Import "-lwx_macu_adv-2.8"
Import "-lwx_macu_core-2.8"
Import "-lwx_base_carbonu_xml-2.8"
Import "-lwx_base_carbonu_net-2.8"
Import "-lwx_base_carbonu-2.8"
Import "-lwx_macu_gl-2.8"
Import "-lwx_macu_richtext-2.8"
Import "-lwxtiff-2.8"
Import "-lwxjpeg-2.8"
Import "-lwxpng-2.8"
Import "-lwxregexu-2.8"
Import "-lwxexpat-2.8"

Import "-framework QuickTime"
Import "-framework IOKit"
Import "-framework Carbon"
Import "-framework Cocoa"
Import "-framework System"
Import "-framework WebKit"
Import "-lz"
Import "-liconv"
?macosx86
Import "../lib/macosx86/wx/include/mac-unicode-release-static/*.h"
Import "../include/*.h"

Import "-lwx_macu_aui-2.8"
Import "-lwx_macu_xrc-2.8"
Import "-lwx_macu_qa-2.8"
Import "-lwx_macu_html-2.8"
Import "-lwx_macu_adv-2.8"
Import "-lwx_macu_core-2.8"
Import "-lwx_base_carbonu_xml-2.8"
Import "-lwx_base_carbonu_net-2.8"
Import "-lwx_base_carbonu-2.8"
Import "-lwx_macu_gl-2.8"
Import "-lwx_macu_richtext-2.8"
Import "-lwxtiff-2.8"
Import "-lwxjpeg-2.8"
Import "-lwxpng-2.8"
Import "-lwxregexu-2.8"
Import "-lwxexpat-2.8"

Import "-framework QuickTime"
Import "-framework IOKit"
Import "-framework Carbon"
Import "-framework Cocoa"
Import "-framework System"
Import "-framework WebKit"
Import "-lz"
Import "-liconv"
?


Import "wxglue.cpp"


Extern
	Function wxfind:Object(handle:Byte Ptr)

	Function bmx_app_wxentry:Int()
	Function bmx_wxapp_settopwindow(window:Byte Ptr)
	Function bmx_wxapp_setappname(name:String)
	Function bmx_wxapp_yield:Int(onlyIfNeeded:Int)
	
	Function bmx_wxwindow_create:Byte Ptr(handle:Object, parent:Byte Ptr, id:Int, x:Int, y:Int, w:Int, h:Int, style:Int)
	Function bmx_wxwindow_show:Int(handle:Byte Ptr, value:Int)
	Function bmx_wxwindow_close:Int(handle:Byte Ptr, force:Int)
	Function bmx_wxwindow_setsizer(handle:Byte Ptr, sizer:Byte Ptr, deleteOld:Int)
	Function bmx_wxwindow_setautolayout(handle:Byte Ptr, autoLayout:Int)
	Function bmx_wxwindow_delete(handle:Byte Ptr)
	Function bmx_wxwindow_getsizer:Byte Ptr(handle:Byte Ptr)
	Function bmx_wxwindow_layout(handle:Byte Ptr)
	Function bmx_wxwindow_getwindowstyleflag:Int(handle:Byte Ptr)
	Function bmx_wxwindow_getbestsize(handle:Byte Ptr, w:Int Ptr, h:Int Ptr)
	Function bmx_wxwindow_setfocus(handle:Byte Ptr)
	Function bmx_wxwindow_clearbackground(handle:Byte Ptr)
	Function bmx_wxwindow_clienttoscreen(handle:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_wxwindow_setbackgroundcolour(handle:Byte Ptr, colour:Byte Ptr)
	Function bmx_wxwindow_setfont(handle:Byte Ptr, font:Byte Ptr)
	Function bmx_wxwindow_setforegroundcolour(handle:Byte Ptr, colour:Byte Ptr)
	Function bmx_wxwindow_getfont:Byte Ptr(handle:Byte Ptr)
	Function bmx_wxwindow_gethelptext:String(handle:Byte Ptr)
	Function bmx_wxwindow_getid:Int(handle:Byte Ptr)
	Function bmx_wxwindow_getlabel:String(handle:Byte Ptr)
	Function bmx_wxwindow_preparedc(handle:Byte Ptr, dc:Byte Ptr)
	Function bmx_wxwindow_refresh(handle:Byte Ptr, eraseBackground:Int)
	Function bmx_wxwindow_getparent:Byte Ptr(handle:Byte Ptr)
	
	Function bmx_wxmenu_create:Byte Ptr(handle:Object, title:String, style:Int)
	Function bmx_wxmenu_append(handle:Byte Ptr, id:Int, item:String, helpString:String, kind:Int)
	Function bmx_wxmenu_appendMenu(handle:Byte Ptr, id:Int, item:String, submenu:Byte Ptr, helpString:String)
	Function bmx_wxmenu_appendseparator(handle:Byte Ptr)
	Function bmx_wxmenu_appendcheckitem(handle:Byte Ptr, id:Int, item:String, helpString:String)
	Function bmx_wxmenu_appendradioitem(handle:Byte Ptr, id:Int, item:String, helpString:String)
	Function bmx_wxmenu_break(handle:Byte Ptr)

	Function bmx_wxevthandler_connectnoid(handle:Byte Ptr, eventType:Int, data:Object)
	Function bmx_wxevthandler_connect(handle:Byte Ptr, id:Int, eventType:Int, data:Object)
	Function bmx_wxevthandler_connectrange(handle:Byte Ptr, id:Int, lastId:Int, eventType:Int, data:Object)
	Function bmx_event_geteventobject:Object(evt:Byte Ptr)
	Function bmx_eventtype_value:Int(value:Int)
	Function bmx_wxcommandevent_getstring:String(evt:Byte Ptr)
	Function bmx_wxcommandevent_ischecked:Int(evt:Byte Ptr)
	Function bmx_wxcommandevent_getint:Int(evt:Byte Ptr)
	Function bmx_wxcommandevent_getselection:Int(evt:Byte Ptr)
	Function bmx_wxcommandevent_isselection:Int(evt:Byte Ptr)
	Function bmx_wxcommandevent_getextralong:Int(evt:Byte Ptr)
	Function bmx_wxmoveevent_getposition(evt:Byte Ptr, x:Int Ptr, y:Int Ptr)
	Function bmx_wxevent_skip(evt:Byte Ptr, skip:Int)
	Function bmx_wxsizeevent_getsize(evt:Byte Ptr, w:Int Ptr, h:Int Ptr)
	Function bmx_wxevent_geteventtype:Int(evt:Byte Ptr)
	Function bmx_wxevent_getid:Int(evt:Byte Ptr)
	
	Function bmx_wxupdateeventui_check(evt:Byte Ptr, value:Int)
	
	Function bmx_wxnotifyevent_allow(evt:Byte Ptr)
	Function bmx_wxnotifyevent_veto(evt:Byte Ptr)
	Function bmx_wxnotifyevent_isallowed:Int(evt:Byte Ptr)
	
	Function bmx_wxversion_string:String()
	Function bmx_wxmessagebox:Int(message:String, caption:String, style:Int, parent:Byte Ptr, x:Int, y:Int)
	Function bmx_wxgetosdescription:String()
	
	Function bmx_wxcontrol_getlabel:String(handle:Byte Ptr)
	Function bmx_wxcontrol_getlabeltext:String(handle:Byte Ptr)
	Function bmx_wxcontrol_setlabel(handle:Byte Ptr, label:String)
	
	Function bmx_wxboxsizer_create:Byte Ptr(handle:Object, orient:Int)
	Function bmx_wxsizer_add:Byte Ptr(handler:Byte Ptr, window:Byte Ptr, proportion:Int, flag:Int, border:Int)
	Function bmx_wxsizer_addsizer:Byte Ptr(handler:Byte Ptr, sizer:Byte Ptr, proportion:Int, flag:Int, border:Int)
	Function bmx_wxsizer_detach:Int(handle:Byte Ptr, window:Byte Ptr)
	Function bmx_wxsizer_detachsizer:Int(handle:Byte Ptr, sizer:Byte Ptr)
	Function bmx_wxsizer_insert:Byte Ptr(handler:Byte Ptr, index:Int, window:Byte Ptr, proportion:Int, flag:Int, border:Int)
	Function bmx_wxsizer_insertsizer:Byte Ptr(handler:Byte Ptr, index:Int, sizer:Byte Ptr, proportion:Int, flag:Int, border:Int)
	Function bmx_wxsizer_addcustomspacer:Byte Ptr(handler:Byte Ptr, width:Int, height:Int, proportion:Int, flag:Int, border:Int)
	Function bmx_wxsizer_addspacer:Byte Ptr(handler:Byte Ptr, size:Int)
	Function bmx_wxsizer_addstretchspacer:Byte Ptr(handler:Byte Ptr, prop:Int)
	Function bmx_wxsizer_setitemminsize(handler:Byte Ptr, index:Int, width:Int, height:Int)
	Function bmx_wxsizer_setitemminsizewindow(handler:Byte Ptr, window:Byte Ptr, width:Int, height:Int)
	Function bmx_wxsizer_setitemminsizesizer(handler:Byte Ptr, sizer:Byte Ptr, width:Int, height:Int)
	Function bmx_wxgridsizer_create:Byte Ptr(handle:Object, cols:Int, vgap:Int, hgap:Int)
	Function bmx_wxgridsizer_getcols:Int(handle:Byte Ptr)
	Function bmx_wxgridsizer_gethgap:Int(handle:Byte Ptr)
	Function bmx_wxgridsizer_getrows:Int(handle:Byte Ptr)
	Function bmx_wxgridsizer_getvgap:Int(handle:Byte Ptr)
	Function bmx_wxgridsizer_setcols(handle:Byte Ptr, cols:Int)
	Function bmx_wxgridsizer_sethgap(handle:Byte Ptr, hgap:Int)
	Function bmx_wxgridsizer_setrows(handle:Byte Ptr, rows:Int)
	Function bmx_wxgridsizer_setvgap(handle:Byte Ptr, vgap:Int)
	Function bmx_wxsizer_setsizehints(handle:Byte Ptr, window:Byte Ptr)
	Function bmx_wxflexgridsizer_create:Byte Ptr(handle:Object, cols:Int, vgap:Int, hgap:Int)
	Function bmx_wxflexgridsizer_addgrowablecol(handle:Byte Ptr, index:Int, prop:Int)
	Function bmx_wxflexgridsizer_addgrowablerow(handle:Byte Ptr, index:Int, prop:Int)
	

	Function bmx_wxarraystring_create:Byte Ptr()
	Function bmx_wxarraystring_add:Int(handle:Byte Ptr, text:String, copies:Int)
	Function bmx_wxarraystring_alloc(handle:Byte Ptr, count:Int)
	Function bmx_wxarraystring_delete(handle:Byte Ptr)
	
	Function bmx_wxcolour_create:Byte Ptr(r:Int, g:Int, b:Int, a:Int)
	Function bmx_wxcolour_delete(handle:Byte Ptr)
	Function bmx_wxcolour_isok:Int(handle:Byte Ptr)
	Function bmx_wxcolour_red:Int(handle:Byte Ptr)
	Function bmx_wxcolour_green:Int(handle:Byte Ptr)
	Function bmx_wxcolour_blue:Int(handle:Byte Ptr)
	Function bmx_wxcolour_alpha:Int(handle:Byte Ptr)
	Function bmx_wxcolour_getasstring:String(handle:Byte Ptr, flags:Int)
	Function bmx_wxcolour_createnamedcolour:Byte Ptr(name:String)
	
	Function bmx_wxstockgdi_colour_black:Byte Ptr()
	Function bmx_wxstockgdi_colour_blue:Byte Ptr()
	Function bmx_wxstockgdi_colour_cyan:Byte Ptr()
	Function bmx_wxstockgdi_colour_green:Byte Ptr()
	Function bmx_wxstockgdi_colour_lightgrey:Byte Ptr()
	Function bmx_wxstockgdi_colour_red:Byte Ptr()
	Function bmx_wxstockgdi_colour_white:Byte Ptr()
	
	Function bmx_wxstockgdi_font_italic:Byte Ptr()
	Function bmx_wxstockgdi_font_normal:Byte Ptr()
	Function bmx_wxstockgdi_font_small:Byte Ptr()
	Function bmx_wxstockgdi_font_swiss:Byte Ptr()
	
	Function bmx_wxstockgdi_pen_blackdashed:Byte Ptr()
	Function bmx_wxstockgdi_pen_black:Byte Ptr()
	Function bmx_wxstockgdi_pen_cyan:Byte Ptr()
	Function bmx_wxstockgdi_pen_green:Byte Ptr()
	Function bmx_wxstockgdi_pen_grey:Byte Ptr()
	Function bmx_wxstockgdi_pen_lightgrey:Byte Ptr()
	Function bmx_wxstockgdi_pen_mediumgrey:Byte Ptr()
	Function bmx_wxstockgdi_pen_red:Byte Ptr()
	Function bmx_wxstockgdi_pen_transparent:Byte Ptr()
	Function bmx_wxstockgdi_pen_white:Byte Ptr()
	
	Function bmx_wxfont_delete(handler:Byte Ptr)
	Function bmx_wxfont_getpointsize:Int(handler:Byte Ptr)
	Function bmx_wxfont_setpointsize(handler:Byte Ptr, size:Int)
	Function bmx_wxfont_isfixedwidth:Int(handle:Byte Ptr)
	Function bmx_wxfont_getdefaultencoding:Int()
	Function bmx_wxfont_getfacename:String(handle:Byte Ptr)
	Function bmx_wxfont_getfamily:Int(handle:Byte Ptr)
	Function bmx_wxfont_getfamilystring:String(handle:Byte Ptr)
	Function bmx_wxfont_getnativefontinfodesc:String(handle:Byte Ptr)
	Function bmx_wxfont_getnativefontinfouserdesc:String(handle:Byte Ptr)
	Function bmx_wxfont_getstyle:Int(handle:Byte Ptr)
	Function bmx_wxfont_getunderlined:Int(handle:Byte Ptr)
	Function bmx_wxfont_getweight:Int(handle:Byte Ptr)
	Function bmx_wxfont_isok:Int(handle:Byte Ptr)
	Function bmx_wxfont_getencoding:Int(handle:Byte Ptr)
	Function bmx_wxfont_getstylestring:String(handle:Byte Ptr)
	Function bmx_wxfont_getweightstring:String(handle:Byte Ptr)
	Function bmx_wxfont_setstyle(handle:Byte Ptr, style:Int)
	Function bmx_wxfont_setunderlined(handle:Byte Ptr, underlined:Int)
	Function bmx_wxfont_setweight(handle:Byte Ptr, weight:Int)
	
	Function bmx_wxpaintdc_create:Byte Ptr(window:Byte Ptr)
	Function bmx_wxpaintdc_delete(handle:Byte Ptr)
	
	Function bmx_wxbrush_create:Byte Ptr(name:String, style:Int)
	Function bmx_wxbrush_delete(handle:Byte Ptr)
	
	Function bmx_wxpen_create:Byte Ptr(name:String, width:Int, style:Int)
	Function bmx_wxpen_createfromcolour:Byte Ptr(colour:Byte Ptr, width:Int, style:Int)
	Function bmx_wxpen_delete(handle:Byte Ptr)
	
	Function bmx_wxdc_clear(handle:Byte Ptr)
	Function bmx_wxdc_setbackground(handle:Byte Ptr, brush:Byte Ptr)
	Function bmx_wxdc_drawtext(handle:Byte Ptr, text:String, x:Int, y:Int)
	
	Function bmx_wxfontmapper_getencoding:Int(n:Int)
	Function bmx_wxfontmapper_getencodingdescription:String(encoding:Int)
	Function bmx_wxfontmapper_getencodingname:String(encoding:Int)
	Function bmx_wxfontmapper_getsupportedencodingcount:Int()
	
End Extern

Global wxVERSION_STRING:String = bmx_wxversion_string()



