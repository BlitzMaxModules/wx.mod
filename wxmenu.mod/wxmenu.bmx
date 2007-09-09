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
Module wx.wxMenu

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
bbdoc: A menu is a popup (or pull down) list of items, one of which may be selected before the menu goes away (clicking elsewhere dismisses the menu).
about: Menus may be used to construct either menu bars or popup menus.
<p>
A menu item has an integer ID associated with it which can be used to identify the selection, or to
change the menu item in some way. A menu item with a special identifier -1 is a separator item and doesn't
have an associated command but just makes a separator line appear in the menu.
</p>
<p>
NB: Please note that wxID_ABOUT and wxID_EXIT are predefined by wxWidgets and have a special meaning
since entries using these IDs will be taken out of the normal menus under MacOS X and will be inserted
into the system menu (following the appropriate MacOS X interface guideline).
</p>
<p>
Menu items may be either normal items, check items or radio items. Normal items don't have any special
properties while the check items have a boolean flag associated to them and they show a checkmark in
the menu when the flag is set. wxWidgets automatically toggles the flag value when the item is clicked
and its value may be retrieved using either IsChecked method of wxMenu or wxMenuBar itself or by using
wxEvent::IsChecked when you get the menu notification for the item in question.
</p>
<p>
The radio items are similar to the check items except that all the other items in the same radio group are
unchecked when a radio item is checked. The radio group is formed by a contiguous range of radio items,
i.e. it starts at the first item of this kind and ends with the first item of a different kind (or the
end of the menu). Notice that because the radio groups are defined in terms of the item positions inserting
or removing the items in the menu containing the radio items risks to not work correctly.
</p>
End Rem
Type wxMenu Extends wxEvtHandler

'	Field wxMenuPtr:Byte Ptr

	' creates a "soft link" to a wxMenu*
	Function _create:wxMenu(wxObjectPtr:Byte Ptr)
		If wxObjectPtr Then
			Local this:wxMenu = New wxMenu
			this.wxObjectPtr = wxObjectPtr
			Return this
		End If
	End Function

	Rem
	bbdoc: Constructs a #wxMenu object.
	about: TODO
	End Rem
	Function CreateMenu:wxMenu(title:String = "", style:Int = 0)
		Return New wxMenu.Create(title, style)
	End Function
	
	Rem
	bbdoc: 
	End Rem
	Method Create:wxMenu(title:String = "", style:Int = 0)
		wxObjectPtr = bmx_wxmenu_create(Self, title, style)
		Return Self
	End Method

	Rem
	bbdoc: Adds a string item to the end of the menu.
	about: @kind may be wxITEM_SEPARATOR, wxITEM_NORMAL, wxITEM_CHECK, or wxITEM_RADIO
	TODO
	End Rem
	Method Append:wxMenuItem(id:Int, item:String = "", helpString:String = "", kind:Int = wxITEM_NORMAL)
		Return wxMenuItem._create(bmx_wxmenu_append(wxObjectPtr, id, item, helpString, kind))
	End Method
	
	Rem
	bbdoc: 
	about: TODO
	End Rem
	Method AppendMenu:wxMenuItem(id:Int, item:String = "", subMenu:wxMenu, helpString:String = "")
		Return wxMenuItem._create(bmx_wxmenu_appendmenu(wxObjectPtr, id, item, subMenu.wxObjectPtr, helpString))
	End Method

	Rem
	bbdoc: Adds a checkable item to the end of the menu.
	End Rem
	Method AppendCheckItem:wxMenuItem(id:Int, item:String = "", helpString:String = "")
		Return wxMenuItem._create(bmx_wxmenu_appendcheckitem(wxObjectPtr, id, item, helpString))
	End Method

	Rem
	bbdoc: Adds a radio item to the end of the menu.
	about: All consequent radio items form a group and when an item in the group is checked, all the others are
	automatically unchecked.
	End Rem
	Method AppendRadioItem:wxMenuItem(id:Int, item:String = "", helpString:String = "")
		Return wxMenuItem._create(bmx_wxmenu_appendradioitem(wxObjectPtr, id, item, helpString))
	End Method

	Rem
	bbdoc: Adds a separator to the end of the menu.
	End Rem
	Method AppendSeparator:wxMenuItem()
		Return wxMenuItem._create(bmx_wxmenu_appendseparator(wxObjectPtr))
	End Method
	
	Rem
	bbdoc: Adds the given submenu to this menu.
	about: @text is the text shown in the menu for it and @help is the help string shown in the status
	bar when the submenu item is selected.
	End Rem
	Method AppendSubMenu:wxMenuItem(submenu:wxMenu, text:String, help:String = "")
		Return wxMenuItem._create(bmx_wxmenu_appendsubmenu(wxObjectPtr, submenu.wxObjectPtr, text, help))
	End Method
	
	Rem
	bbdoc: Inserts a break in a menu, causing the next appended item to appear in a new column.
	End Rem
	Method Break()
		bmx_wxmenu_break(wxObjectPtr)
	End Method
	
	Rem
	bbdoc: Checks or unchecks the menu item.
	End Rem
	Method Check(id:Int, value:Int)
		bmx_wxmenu_check(wxObjectPtr, id, value)
	End Method
	
	Rem
	bbdoc: Deletes the menu item from the menu.
	about: If the item is a submenu, it will not be deleted. Use Destroy if you want to delete a submenu.
	End Rem
	Method DeleteItem(id:Int)
		bmx_wxmenu_delete(wxObjectPtr, id)
	End Method
	
	Rem
	bbdoc: Deletes the menu item from the menu.
	about: If the item is a submenu, it will be deleted. Use Remove if you want to keep the submenu
	(for example, to reuse it later).
	End Rem
	Method DestroyItem(id:Int)
		bmx_wxmenu_destroy(wxObjectPtr, id)
	End Method
	
	Rem
	bbdoc: Enables or disables (greys out) a menu item.
	End Rem
	Method Enable(id:Int, value:Int)
		bmx_wxmenu_enable(wxObjectPtr, id, value)
	End Method
	
	Rem
	bbdoc: Finds the menu item id for a menu item string.
	End Rem
	Method FindItem:Int(itemString:String)
		Return bmx_wxmenu_finditem(wxObjectPtr, itemString)
	End Method
	
	Rem
	bbdoc: Returns the wxMenuItem given a position in the menu.
	End Rem
	Method FindItemByPosition:wxMenuItem(pos:Int)
		Return wxMenuItem._create(bmx_wxmenu_finditembyposition(wxObjectPtr, pos))
	End Method
	
	Rem
	bbdoc: Returns the help string associated with a menu item.
	End Rem
	Method GetHelpString:String(id:Int)
		Return bmx_wxmenu_gethelpstring(wxObjectPtr, id)
	End Method
	
	Rem
	bbdoc: Returns a menu item label.
	End Rem
	Method GetLabel:String(id:Int)
		Return bmx_wxmenu_getlabel(wxObjectPtr, id)
	End Method
	
	Rem
	bbdoc: Returns the number of items in the menu.
	End Rem
	Method GetMenuItemCount:Int()
		Return bmx_wxmenu_getmenuitemcount(wxObjectPtr)
	End Method
	
	Rem
	bbdoc: Returns the list of items in the menu.
	End Rem
	Method GetMenuItems:wxMenuItem[]()
	End Method
	
	Rem
	bbdoc: Returns the title of the menu.
	about: This is relevant only to popup menus, use wxMenuBar::GetLabelTop for the menus in the menubar.
	End Rem
	Method GetTitle:String()
		Return bmx_wxmenu_gettitle(wxObjectPtr)
	End Method	
	
	Rem
	bbdoc: Inserts the given item before the position pos.
	about: Inserting the item at position GetMenuItemCount is the same as appending it.
	End Rem
	Method Insert:wxMenuItem(pos:Int, id:Int, item:String = "", helpString:String = "", kind:Int = wxITEM_NORMAL)
		Return wxMenuItem._create(bmx_wxmenu_insert(wxObjectPtr, pos, id, item, helpString, kind))
	End Method
	
	Rem
	bbdoc: Inserts a checkable item at the given position.
	End Rem
	Method InsertCheckItem:wxMenuItem(pos:Int, id:Int, item:String, helpString:String = "")
		Return wxMenuItem._create(bmx_wxmenu_insertcheckitem(wxObjectPtr, pos, id, item, helpString))
	End Method
	
	Rem
	bbdoc: Inserts a radio item at the given position.
	End Rem
	Method InsertRadioItem:wxMenuItem(pos:Int, id:Int, item:String, helpString:String = "")
		Return wxMenuItem._create(bmx_wxmenu_insertradioitem(wxObjectPtr, pos, id, item, helpString))
	End Method
	
	Rem
	bbdoc: Inserts a separator at the given position.
	End Rem
	Method InsertSeparator:wxMenuItem(pos:Int)
		Return wxMenuItem._create(bmx_wxmenu_insertseparator(wxObjectPtr, pos))
	End Method
	
	Rem
	bbdoc: Determines whether a menu item is checked.
	returns: True if the menu item is checked, False otherwise.
	End Rem
	Method IsChecked:Int(id:Int)
		Return bmx_wxmenu_ischecked(wxObjectPtr, id)
	End Method

	Rem
	bbdoc: Determines whether a menu item is enabled.
	returns: True if the menu item is enabled, False otherwise.
	End Rem
	Method IsEnabled:Int(id:Int)
		Return bmx_wxmenu_isenabled(wxObjectPtr, id)
	End Method
	
	Rem
	bbdoc: Inserts the given item at position 0, i.e. before all the other existing items.
	End Rem
	Method Prepend:wxMenuItem(id:Int, item:String = "", helpString:String = "", kind:Int = wxITEM_NORMAL)
		Return wxMenuItem._create(bmx_wxmenu_prepend(wxObjectPtr, id, item, helpString, kind))
	End Method
	
	Rem
	bbdoc: Inserts a checkable item at position 0.
	End Rem
	Method PrependCheckItem:wxMenuItem(id:Int, item:String, helpString:String = "")
		Return wxMenuItem._create(bmx_wxmenu_prependcheckitem(wxObjectPtr, id, item, helpString))
	End Method
	
	Rem
	bbdoc: Inserts a radio item at position 0.
	End Rem
	Method PrependRadioItem:wxMenuItem(id:Int, item:String, helpString:String = "")
		Return wxMenuItem._create(bmx_wxmenu_prependradioitem(wxObjectPtr, id, item, helpString))
	End Method
	
	Rem
	bbdoc: Inserts a separator at position 0.
	End Rem
	Method PrependSeparator:wxMenuItem()
		Return wxMenuItem._create(bmx_wxmenu_prependseparator(wxObjectPtr))
	End Method
	
	Rem
	bbdoc: Removes the menu item from the menu but doesn't delete the associated object.
	about: This allows to reuse the same item later by adding it back to the menu (especially useful
	with submenus).
	End Rem
	Method Remove(id:Int)
		bmx_wxmenu_remove(wxObjectPtr, id)
	End Method
	
	Rem
	bbdoc: Sets an item's help string.
	End Rem
	Method SetHelpString(id:Int, helpString:String)
		bmx_wxmenu_sethelpstring(wxObjectPtr, id, helpString)
	End Method
	
	Rem
	bbdoc: Sets the label of a menu item.
	End Rem
	Method SetLabel(id:Int, label:String)
		bmx_wxmenu_setlabel(wxObjectPtr, id, label)
	End Method
	
	Rem
	bbdoc: Sets the title of the menu.
	End Rem
	Method SetTitle(title:String)
		bmx_wxmenu_settitle(wxObjectPtr, title)
	End Method
	
	Rem
	bbdoc: Sends events to source (or owning window if NULL) to update the menu UI.
	about: This is called just before the menu is popped up with wxWindow::PopupMenu, but the
	application may call it at other times if required.
	End Rem
	Method UpdateUI(source:wxEvtHandler = Null)
		If source Then
			bmx_wxmenu_updateui(wxObjectPtr, source.wxObjectPtr)
		Else
			bmx_wxmenu_updateui(wxObjectPtr, Null)
		End If
	End Method
	
End Type

Rem
bbdoc: A menu item represents an item in a menu.
about: Note that you usually don't have to deal with it directly as wxMenu methods usually construct an
object of this class for you.
<p>
Also please note that the methods related to fonts and bitmaps are currently only implemented for Windows
and GTK+.
</p>
End Rem
Type wxMenuItem Extends wxObject

	Function _create:wxMenuItem(wxObjectPtr:Byte Ptr)
		If wxObjectPtr Then
			Local this:wxMenuItem = New wxMenuItem
			this.wxObjectPtr = wxObjectPtr
			Return this
		End If
	End Function
	
	Rem
	bbdoc: 
	End Rem
	Method Check(value:Int = True)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method Enable(value:Int = True)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetBackgroundColour:wxColour()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetBitmap:wxBitmap(checked:Int = True)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetFont:wxFont()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetHelp:String()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetId:Int()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetKind:Int()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetLabel:String()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetLabelFromText:String(text:String)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetMarginWidth:Int()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetMenu:wxMenu()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetName:String()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetText:String()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetSubMenu:wxMenu()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method GetTextColour:wxColour()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method IsChecked:Int()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method IsEnabled:Int()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method IsSeparator:Int()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method IsSubMenu:Int()
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method SetBackgroundColour(colour:wxColour)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method SetBitmap(bitmap:wxBitmap)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method SetBitmaps(checked:wxBitmap, unchecked:wxBitmap = Null)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method SetFont(font:wxFont)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method SetHelp(helpString:String)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method SetMarginWidth(width:Int)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method SetMenu(menu:wxMenu)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method SetSubMenu(submenu:wxMenu)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method SetText(text:String)
	End Method
	
	Rem
	bbdoc: 
	End Rem
	Method SetTextColour(colour:wxColour)
	End Method
	
End Type

Rem
bbdoc: This type is used for a variety of menu-related events.
about: Note that these do not include menu command events, which are handled using wxCommandEvent objects.
The default handler for wxEVT_MENU_HIGHLIGHT displays help text in the first field of the status bar.
End Rem
Type wxMenuEvent Extends wxEvent

	Function create:wxEvent(wxEventPtr:Byte Ptr, evt:TEventHandler)
		Local this:wxMenuEvent = New wxMenuEvent 
		
		this.wxEventPtr = wxEventPtr
		this.userData = evt.userData
		this.parent = evt.parent
		
		Return this
	End Function

	Rem
	bbdoc: Returns the menu which is being opened or closed.
	about: This method should only be used with the OPEN and CLOSE events and even for them the
	returned pointer may be Null in some ports.
	End Rem
	Method GetMenu:wxMenu()
	End Method
	
	Rem
	bbdoc: Returns the menu identifier associated with the event.
	about: This method should be only used with the HIGHLIGHT events.
	End Rem
	Method GetMenuId:Int()
	End Method
	
	Rem
	bbdoc: Returns true if the menu which is being opened or closed is a popup menu, false if it is a normal one.
	about: This method should only be used with the OPEN and CLOSE events.
	End Rem
	Method IsPopup:Int()
	End Method
	
End Type


Type TMenuEventFactory Extends TEventFactory

	Method CreateEvent:wxEvent(wxEventPtr:Byte Ptr, evt:TEventHandler)
	
		Select evt.eventType
			Case wxEVT_MENU_OPEN, ..
					wxEVT_MENU_CLOSE, ..
					wxEVT_MENU_HIGHLIGHT
				Return wxMenuEvent.create(wxEventPtr, evt)
		End Select
		
		Return Null
	End Method

	Method GetEventType:Int(eventType:Int)
		Select eventType
			Case wxEVT_MENU_OPEN, ..
					wxEVT_MENU_CLOSE, ..
					wxEVT_MENU_HIGHLIGHT
				Return bmx_wxmenu_geteventtype(eventType)
		End Select
	End Method
		
End Type

New TMenuEventFactory

