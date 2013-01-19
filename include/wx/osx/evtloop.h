///////////////////////////////////////////////////////////////////////////////
// Name:        wx/osx/evtloop.h
// Purpose:     simply forwards to wx/osx/carbon/evtloop.h or
//              wx/osx/cocoa/evtloop.h for consistency with the other Mac
//              headers
// Author:      Vadim Zeitlin
// Modified by:
// Created:     2006-01-12
// RCS-ID:      $Id: evtloop.h 72206 2012-07-24 20:45:43Z VZ $
// Copyright:   (c) 2006 Vadim Zeitlin <vadim@wxwindows.org>
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

#ifndef _WX_OSX_EVTLOOP_H_
#define _WX_OSX_EVTLOOP_H_

#ifdef __WXOSX_COCOA__
    #include "wx/osx/cocoa/evtloop.h"
#else
    #include "wx/osx/carbon/evtloop.h"
#endif

class WXDLLIMPEXP_FWD_CORE wxWindow;
class WXDLLIMPEXP_FWD_CORE wxNonOwnedWindow;

class WXDLLIMPEXP_CORE wxModalEventLoop : public wxGUIEventLoop
{
public:
    wxModalEventLoop(wxWindow *modalWindow);
    wxModalEventLoop(WXWindow modalNativeWindow);

protected:
    virtual void DoRun();

    virtual void DoStop();

    // (in case) the modal window for this event loop
    wxNonOwnedWindow* m_modalWindow;
    WXWindow m_modalNativeWindow;
};

#endif // _WX_OSX_EVTLOOP_H_
