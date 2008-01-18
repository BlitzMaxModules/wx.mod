/*
  Copyright (c) 2007,2008 Bruce A Henderson
 
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
#include "wx/process.h"

class MaxProcess;

extern "C" {

#include <blitz.h>

	wxProcess * bmx_wxprocess_create(BBObject * handle, wxEvtHandler * parent, int id);
	wxProcess * bmx_wxprocess_createwithflags(BBObject * handle, int flags);
	void bmx_wxprocess_closeoutput(wxProcess * process);
	void bmx_wxprocess_detach(wxProcess * process);
	wxInputStream * bmx_wxprocess_geterrorstream(wxProcess * process);
	wxInputStream * bmx_wxprocess_getintputstream(wxProcess * process);
	wxOutputStream * bmx_wxprocess_getoutputstream(wxProcess * process);
	bool bmx_wxprocess_iserroravailable(wxProcess * process);
	bool bmx_wxprocess_isinputavailable(wxProcess * process);
	bool bmx_wxprocess_isinputopened(wxProcess * process);
	wxKillError bmx_wxprocess_kill(int pid, wxSignal signal, int flags);
	bool bmx_wxprocess_exists(int pid);
	wxProcess * bmx_wxprocess_open(BBString * cmd, int flags);
	int bmx_wxprocess_getpid(wxProcess * process);
	void bmx_wxprocess_redirect(wxProcess * process);
	void bmx_wxprocess_free(wxProcess * process);

	bool bmx_wxshell(BBString * command);
	bool bmx_wxshutdown(wxShutdownFlags flags);
	unsigned long bmx_wxgetprocessid();
	void bmx_wxexit();
	int bmx_wxkill(long pid, wxSignal signal, wxKillError * rc, int flags);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxProcess : public wxProcess
{
public:
	MaxProcess(BBObject * handle, wxEvtHandler * parent, int id);
	MaxProcess(BBObject * handle, int flags);
	~ MaxProcess();

};
