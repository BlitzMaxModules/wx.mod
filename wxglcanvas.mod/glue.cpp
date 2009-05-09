/*
  Copyright (c) 2007-2009 Bruce A Henderson
 
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

#include "glue.h"

#if wxUSE_GLCANVAS


// ---------------------------------------------------------------------------------------

static wxGLContext * sharedContext;


MaxGLCanvas::MaxGLCanvas(BBObject * handle, wxWindow* parent, wxWindowID id,
		int x, int y, int w, int h, long style, const wxString& name, int* attribList)
	: wxGLCanvas(parent, id, wxPoint(x, y), wxSize(w, h), style, name, attribList)
{
	wxbind(this, handle);
}

MaxGLCanvas::MaxGLCanvas(BBObject * handle, wxWindow* parent, wxGLContext * sharedContext, wxWindowID id,
		int x, int y, int w, int h, long style, const wxString& name, int* attribList)
	: wxGLCanvas(parent, sharedContext, id, wxPoint(x, y), wxSize(w, h), style, name, attribList)
{
	wxbind(this, handle);
}

MaxGLCanvas::~MaxGLCanvas() {
	wxunbind(this);
}

void MaxGLCanvas::OnEraseBackground(wxEraseEvent& WXUNUSED(event))
{
    // Do nothing, to avoid flashing on MSW
}

void MaxGLCanvas::Render(BBObject * event) {
	wxGLCanvas::SetCurrent();
	wxPaintDC(this);
	_wx_wxglcanvas_wxGLCanvas__OnPaint(event);
}

void MaxGLCanvas::Refresh(bool eraseBackground, const wxRect* rect) {
	wxGLCanvas::Refresh(eraseBackground, rect);
}


// *********************************************

BEGIN_EVENT_TABLE(MaxGLCanvas, wxGLCanvas)
    EVT_ERASE_BACKGROUND(MaxGLCanvas::OnEraseBackground)
END_EVENT_TABLE()

static int _initAttrs( int attrs[16],int flags ){
	int n=0;
	attrs[n++] = WX_GL_RGBA;
	if( flags & FLAGS_BACKBUFFER ) attrs[n++]=WX_GL_DOUBLEBUFFER;
	if( flags & FLAGS_ALPHABUFFER ){ attrs[n++]=WX_GL_MIN_ALPHA;attrs[n++]=1; }
	if( flags & FLAGS_DEPTHBUFFER ){ attrs[n++]=WX_GL_DEPTH_SIZE;attrs[n++]=16; }
	if( flags & FLAGS_STENCILBUFFER ){ attrs[n++]=WX_GL_STENCIL_SIZE;attrs[n++]=1; }
	if( flags & FLAGS_ACCUMBUFFER ){ attrs[n++]=WX_GL_MIN_ACCUM_RED;attrs[n++]=1; }
//	if( flags & FLAGS_FULLSCREEN ){
//		attrs[n++]=kCGLPFAFullScreen;
////		attrs[n++]=kCGLPFADisplayMask;
//		attrs[n++]=CGDisplayIDToOpenGLDisplayMask( kCGDirectMainDisplay );
//	}else{
//		attrs[n++]=kCGLPFANoRecovery;
//	}
	attrs[n]=0;
	return n;
}

MaxGLCanvas * bmx_wxglcanvas_create(BBObject * handle, wxWindow* parent, wxWindowID id,
	int flags, int x, int y, int w, int h, long style) {

	int attribList[16];
	
	_initAttrs(attribList, flags);
	
	if (sharedContext) {
		return new MaxGLCanvas(handle, parent, sharedContext, id, x, y, w, h, style, wxT("GLCanvas"), attribList);
	} else {
		MaxGLCanvas * canvas = new MaxGLCanvas(handle, parent, id, x, y, w, h, style, wxT("GLCanvas"), attribList);
		sharedContext = canvas->GetContext();
		return canvas;
	}
}

void bmx_wxglcanvas_onpainthook(MaxGLCanvas * canvas, BBObject * event) {
	canvas->Render(event);
}

void bmx_wxglcanvas_swapbuffers(wxGLCanvas * canvas) {
	canvas->SwapBuffers();
}

void bmx_wxglcanvas_setcurrent(wxGLCanvas * canvas) {
	canvas->SetCurrent();
}

#endif