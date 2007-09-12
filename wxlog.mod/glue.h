/*
  Copyright (c) 2007 Bruce A Henderson
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/ 

#include "wxglue.h"
#include "wx/log.h"

extern "C" {

#include <blitz.h>

	BBObject *wxlogfind( wxLog *obj );

	void bmx_wxlogerror(BBString * message);
	void bmx_wxlogfatalerror(BBString * message);
	void bmx_wxlogwarning(BBString * message);
	void bmx_wxlogmessage(BBString * message);
	void bmx_wxlogverbose(BBString * message);
	void bmx_wxlogstatus(BBString * message, wxFrame * frame);
	void bmx_wxsafeshowmessage(BBString * message);
	unsigned long bmx_wxsyserrorcode();
	BBString * bmx_wxsyserrormsg(unsigned long code);

	void bmx_wxlog_delete(wxLog * logger);
	wxLog * bmx_wxlogtextctrl_create(BBObject * handle, wxTextCtrl * textctrl);
	wxLog * bmx_wxlog_setactivetarget(wxLog * log);
	void bmx_wxlog_settimestamp(BBString * format);
}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

