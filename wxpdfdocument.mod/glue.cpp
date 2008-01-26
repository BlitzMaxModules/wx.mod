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

#include "glue.h"

// ---------------------------------------------------------------------------------------

MaxPdfDocument::MaxPdfDocument(BBObject * handle, int orientation, const wxString& unit, wxPaperSize format)
	: maxHandle(handle), wxPdfDocument(orientation, unit, format)
{
}

MaxPdfDocument::~MaxPdfDocument() {
}

void MaxPdfDocument::Header() {
	_wx_wxpdfdocument_wxPdfDocument__Header(maxHandle);
}

void MaxPdfDocument::Footer() {
	_wx_wxpdfdocument_wxPdfDocument__Footer(maxHandle);
}

bool MaxPdfDocument::AcceptPageBreak() {
	return _wx_wxpdfdocument_wxPdfDocument__AcceptPageBreak(maxHandle);
}

bool MaxPdfDocument::AcceptPageBreak_default() {
	return wxPdfDocument::AcceptPageBreak();
}


// ---------------------------------------------------------------------------------------

MaxPdfLink::MaxPdfLink(const wxPdfLink & l)
	: pdfLink(l)
{
}

wxPdfLink & MaxPdfLink::Link() {
	return pdfLink;
}

// ---------------------------------------------------------------------------------------

MaxPdfColour::MaxPdfColour(const wxPdfColour & c)
	: colour(c)
{
}

wxPdfColour & MaxPdfColour::Colour() {
	return colour;
}

// ---------------------------------------------------------------------------------------

MaxPdfLineStyle::MaxPdfLineStyle(const wxPdfLineStyle & s)
	: style(s)
{
}

wxPdfLineStyle & MaxPdfLineStyle::Style() {
	return style;
}


// *********************************************

MaxPdfShape::MaxPdfShape(const wxPdfShape & s)
	: shape(s)
{
}

wxPdfShape & MaxPdfShape::Shape() {
	return shape;
}


// *********************************************

MaxPdfInfo::MaxPdfInfo(const wxPdfInfo & i)
	: info(i)
{
}

wxPdfInfo & MaxPdfInfo::Info() {
	return info;
}


// *********************************************

MaxPdfCoonsPatchMesh::MaxPdfCoonsPatchMesh(const wxPdfCoonsPatchMesh & m)
	: mesh(m)
{
}

wxPdfCoonsPatchMesh & MaxPdfCoonsPatchMesh::Mesh() {
	return mesh;
}


// *********************************************

MaxPdfFontDescription::MaxPdfFontDescription(const wxPdfFontDescription & d)
	: desc(d)
{
}

wxPdfFontDescription & MaxPdfFontDescription::Desc() {
	return desc;
}


// *********************************************


wxPdfArrayDouble bbDoubleArrayTowxPdfArrayDouble( BBArray *p ){
	int n=p->scales[0];
	double *s=(double*)BBARRAYDATA( p,p->dims );
	wxPdfArrayDouble arr;
	arr.Alloc(n);
	for( int i=0;i<n;++i ){
		arr.Add(s[i]);
	}
	return arr;
}



void bmx_wxpdfdocument_free(wxPdfDocument * doc) {
	delete doc;
}

wxPdfDocument * bmx_wxpdfdocument_create(BBObject * handle, int orientation, BBString * unit, wxPaperSize format) {
	return new MaxPdfDocument(handle, orientation, wxStringFromBBString(unit), format);
}

void bmx_wxpdfdocument_addpage(wxPdfDocument * doc, int orientation) {
	doc->AddPage(orientation);
}

void bmx_wxpdfdocument_setfont(wxPdfDocument * doc, BBString * family, BBString * style, double size) {
	doc->SetFont(wxStringFromBBString(family), wxStringFromBBString(style), size);
}

void bmx_wxpdfdocument_cell(wxPdfDocument * doc, double w, double h, BBString * txt, int border, int ln, int align, int fill, MaxPdfLink * link) {
	if (link) {
		doc->Cell(w, h, wxStringFromBBString(txt), border, ln, align, fill, link->Link());
	} else {
		doc->Cell(w, h, wxStringFromBBString(txt), border, ln, align, fill);
	}
}

void bmx_wxpdfdocument_saveasfile(wxPdfDocument * doc, BBString * name) {
	doc->SaveAsFile(wxStringFromBBString(name));
}

void bmx_wxpdfdocument_addspotcolor(wxPdfDocument * doc, BBString * name, double cyan, double magenta, double yellow, double black) {
	doc->AddSpotColor(wxStringFromBBString(name), cyan, magenta, yellow, black);
}

void bmx_wxpdfdocument_aliasnbpages(wxPdfDocument * doc, BBString * _alias) {
	doc->AliasNbPages(wxStringFromBBString(_alias));
}

void bmx_wxpdfdocument_arrow(wxPdfDocument * doc, double x1, double y1, double x2, double y2, double lineWidth, double height, double width) {
	doc->Arrow(x1, y1, x2, y2, lineWidth, height, width);
}

void bmx_wxpdfdocument_circle(wxPdfDocument * doc, double x0, double y0, double r, double astart, double afinish, int style, int nSeg) {
	doc->Circle(x0, y0, r, astart, afinish, style, nSeg);
}

void bmx_wxpdfdocument_curve(wxPdfDocument * doc, double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3, int style) {
	doc->Curve(x0, y0, x1, y1, x2, y2, x3, y3, style);
}

void bmx_wxpdfdocument_ellipse(wxPdfDocument * doc, double x0, double y0, double rx, double ry, double angle, double astart, double afinish, int style, int nSeg) {
	doc->Ellipse(x0, y0, rx, ry, angle, astart, afinish, style, nSeg);
}

bool bmx_wxpdfdocument_image(wxPdfDocument * doc, BBString * file, double x, double y, double w, double h, BBString * mimeType, MaxPdfLink * link, int maskImage) {
	if (link) {
		return doc->Image(wxStringFromBBString(file), x, y, w, h, wxStringFromBBString(mimeType), link->Link(), maskImage);
	} else {
		return doc->Image(wxStringFromBBString(file), x, y, w, h, wxStringFromBBString(mimeType), wxPdfLink(-1), maskImage);
	}
}

void bmx_wxpdfdocument_ln(wxPdfDocument * doc, double h) {
	doc->Ln(h);
}

void bmx_wxpdfdocument_sety(wxPdfDocument * doc, double y) {
	doc->SetY(y);
}

int bmx_wxpdfdocument_pageno(wxPdfDocument * doc) {
	return doc->PageNo();
}

void bmx_wxpdfdocument_setx(wxPdfDocument * doc, double x) {
	doc->SetX(x);
}

void bmx_wxpdfdocument_settitle(wxPdfDocument * doc, BBString * title) {
	doc->SetTitle(wxStringFromBBString(title));
}

void bmx_wxpdfdocument_setdrawcolor(wxPdfDocument * doc, MaxColour * colour) {
	doc->SetDrawColor(colour->Colour());
}

void bmx_wxpdfdocument_setfillcolor(wxPdfDocument * doc, MaxColour * colour) {
	doc->SetFillColor(colour->Colour());
}

void bmx_wxpdfdocument_settextcolor(wxPdfDocument * doc, MaxColour * colour) {
	doc->SetTextColor(colour->Colour());
}

double bmx_wxpdfdocument_getstringwidth(wxPdfDocument * doc, BBString * text) {
	return doc->GetStringWidth(wxStringFromBBString(text));
}

void bmx_wxpdfdocument_setlinewidth(wxPdfDocument * doc, double width) {
	doc->SetLineWidth(width);
}

void bmx_wxpdfdocument_setauthor(wxPdfDocument * doc, BBString * author) {
	doc->SetAuthor(wxStringFromBBString(author));
}

void bmx_wxpdfdocument_settextcolorgrayscale(wxPdfDocument * doc, int grayscale) {
	doc->SetTextColor(static_cast<unsigned char>(grayscale));
}

int bmx_wxpdfdocument_multicell(wxPdfDocument * doc, double w, double h, BBString * txt, int border, int align, int fill, int maxline) {
	return doc->MultiCell(w, h, wxStringFromBBString(txt), border, align, fill, maxline);
}

bool bmx_wxpdfdocument_acceptpagebreak(MaxPdfDocument * doc) {
	return doc->AcceptPageBreak_default();
}

bool bmx_wxpdfdocument_addfont(wxPdfDocument * doc, BBString * family, BBString * style, BBString * file) {
	return doc->AddFont(wxStringFromBBString(family), wxStringFromBBString(style), wxStringFromBBString(file));
}

bool bmx_wxpdfdocument_addfontcjk(wxPdfDocument * doc, BBString * family) {
	return doc->AddFontCJK(wxStringFromBBString(family));
}

int bmx_wxpdfdocument_addlink(wxPdfDocument * doc) {
	return doc->AddLink();
}

void bmx_wxpdfdocument_annotate(wxPdfDocument * doc, double x, double y, BBString * text) {
	doc->Annotate(x, y, wxStringFromBBString(text));
}

void bmx_wxpdfdocument_appendjavascript(wxPdfDocument * doc, BBString * javascript) {
	doc->AppendJavascript(wxStringFromBBString(javascript));
}

int bmx_wxpdfdocument_axialgradient(wxPdfDocument * doc, MaxPdfColour * col1, MaxPdfColour * col2, double x1, double y1, double x2, double y2, double intexp) {
	return doc->AxialGradient(col1->Colour(), col2->Colour(), x1, y1, x2, y2, intexp);
}

int bmx_wxpdfdocument_begintemplate(wxPdfDocument * doc, double x, double y, double width, double height) {
	return doc->BeginTemplate(x, y, width, height);
}

void bmx_wxpdfdocument_bookmark(wxPdfDocument * doc, BBString * txt, int level, double y) {
	doc->Bookmark(wxStringFromBBString(txt), level, y);
}

void bmx_wxpdfdocument_setimagescale(wxPdfDocument * doc, double scale) {
	doc->SetImageScale(scale);
}

void bmx_wxpdfdocument_setkeywords(wxPdfDocument * doc, BBString * keywords) {
	doc->SetKeywords(wxStringFromBBString(keywords));
}

void bmx_wxpdfdocument_setleftmargin(wxPdfDocument * doc, double margin) {
	doc->SetLeftMargin(margin);
}

void bmx_wxpdfdocument_setlineheight(wxPdfDocument * doc, double height) {
	doc->SetLineHeight(height);
}

void bmx_wxpdfdocument_setlinestyle(wxPdfDocument * doc, MaxPdfLineStyle * style) {
	doc->SetLineStyle(style->Style());
}

double bmx_wxpdfdocument_gettopmargin(wxPdfDocument * doc) {
	doc->GetTopMargin();
}

double bmx_wxpdfdocument_getx(wxPdfDocument * doc) {
	return doc->GetX();
}

double bmx_wxpdfdocument_gety(wxPdfDocument * doc) {
	return doc->GetY();
}

double bmx_wxpdfdocument_getbreakmargin(wxPdfDocument * doc) {
	return doc->GetBreakMargin();
}

double bmx_wxpdfdocument_getcellmargin(wxPdfDocument * doc) {
	return doc->GetCellMargin();
}

BBString * bmx_wxpdfdocument_getfontfamily(wxPdfDocument * doc) {
	return bbStringFromWxString(doc->GetFontFamily());
}

BBString * bmx_wxpdfdocument_getfontpath(wxPdfDocument * doc) {
	return bbStringFromWxString(doc->GetFontPath());
}

double bmx_wxpdfdocument_getfontsize(wxPdfDocument * doc) {
	return doc->GetFontSize();
}

BBString * bmx_wxpdfdocument_getfontstyle(wxPdfDocument * doc) {
	return bbStringFromWxString(doc->GetFontStyle());
}

bool bmx_wxpdfdocument_getfontsubsetting(wxPdfDocument * doc) {
	return doc->GetFontSubsetting();
}

double bmx_wxpdfdocument_getimagescale(wxPdfDocument * doc) {
	return doc->GetImageScale();
}

double bmx_wxpdfdocument_getleftmargin(wxPdfDocument * doc) {
	return doc->GetLeftMargin();
}

double bmx_wxpdfdocument_getlineheight(wxPdfDocument * doc) {
	return doc->GetLineHeight();
}

double bmx_wxpdfdocument_getlinewidth(wxPdfDocument * doc) {
	return doc->GetLineWidth();
}

void bmx_wxpdfdocument_writexml(wxPdfDocument * doc, BBString * txt) {
	doc->WriteXml(wxStringFromBBString(txt));
}

void bmx_wxpdfdocument_translate(wxPdfDocument * doc, double tx, double ty) {
	doc->Translate(tx, ty);
}

void bmx_wxpdfdocument_translatex(wxPdfDocument * doc, double tx) {
	doc->TranslateX(tx);
}

void bmx_wxpdfdocument_translatey(wxPdfDocument * doc, double ty) {
	doc->TranslateY(ty);
}

void bmx_wxpdfdocument_unsetclipping(wxPdfDocument * doc) {
	doc->UnsetClipping();
}

void bmx_wxpdfdocument_usetemplate(wxPdfDocument * doc, int templateId, double x, double y, double width, double height) {
	doc->UseTemplate(templateId, x, y, width, height);
}

void bmx_wxpdfdocument_write(wxPdfDocument * doc, double h, BBString * txt, MaxPdfLink * link) {
	if (link) {
		doc->Write(h, wxStringFromBBString(txt), link->Link());
	} else {
		doc->Write(h, wxStringFromBBString(txt));
	}
}

void bmx_wxpdfdocument_writecell(wxPdfDocument * doc, double h, BBString * txt, int border, int fill, MaxPdfLink * link) {
	if (link) {
		doc->WriteCell(h, wxStringFromBBString(txt), border, fill, link->Link());
	} else {
		doc->WriteCell(h, wxStringFromBBString(txt), border, fill);
	}
}

void bmx_wxpdfdocument_textfield(wxPdfDocument * doc, BBString * name, double width, double height, BBString * value, bool multiline) {
	doc->TextField(wxStringFromBBString(name), width, height, wxStringFromBBString(value), multiline);
}

void bmx_wxpdfdocument_textfieldxy(wxPdfDocument * doc, BBString * name, double x, double y, double width, double height, BBString * value, bool multiline) {
	doc->TextField(wxStringFromBBString(name), x, y, width, height, wxStringFromBBString(value), multiline);
}

void bmx_wxpdfdocument_stoptransform(wxPdfDocument * doc) {
	doc->StopTransform();
}

void bmx_wxpdfdocument_text(wxPdfDocument * doc, double x, double y, BBString * txt) {
	doc->Text(x, y, wxStringFromBBString(txt));
}

int bmx_wxpdfdocument_textbox(wxPdfDocument * doc, double w, double h, BBString * txt, int halign, int valign, int border, int fill) {
	return doc->TextBox(w, h, wxStringFromBBString(txt), halign, valign, border, fill);
}

void bmx_wxpdfdocument_checkbox(wxPdfDocument * doc, BBString * name, double width, bool checked) {
	doc->CheckBox(wxStringFromBBString(name), width, checked);
}

void bmx_wxpdfdocument_checkboxxy(wxPdfDocument * doc, BBString * name, double x, double y, double width, bool checked) {
	doc->CheckBox(wxStringFromBBString(name), x, y, width, checked);
}

void bmx_wxpdfdocument_combobox(wxPdfDocument * doc, BBString * name, double width, double height, BBArray * values) {
	doc->ComboBox(wxStringFromBBString(name), width, height, bbStringArrayTowxArrayStr(values));
}

void bmx_wxpdfdocument_comboboxxy(wxPdfDocument * doc, BBString * name, double x, double y, double width, double height, BBArray * values) {
	doc->ComboBox(wxStringFromBBString(name), x, y, width, height, bbStringArrayTowxArrayStr(values));
}

void bmx_wxpdfdocument_clippedcell(wxPdfDocument * doc, double w, double h, BBString * txt, int border, int ln, int align, int fill, MaxPdfLink * link) {
	if (link) {
		doc->ClippedCell(w, h, wxStringFromBBString(txt), border, ln, align, fill, link->Link());
	} else {
		doc->ClippedCell(w, h, wxStringFromBBString(txt), border, ln, align, fill);
	}
}

void bmx_wxpdfdocument_clippingellipse(wxPdfDocument * doc, double x, double y, double rx, double ry, bool outline) {
	doc->ClippingEllipse(x, y, rx, ry, outline);
}

void bmx_wxpdfdocument_clippingpath(wxPdfDocument * doc) {
	doc->ClippingPath();
}

void bmx_wxpdfdocument_clippingpathshape(wxPdfDocument * doc, MaxPdfShape * shape, int style) {
	doc->ClippingPath(shape->Shape(), style);
}

void bmx_wxpdfdocument_clippingpolygon(wxPdfDocument * doc, BBArray * x, BBArray * y, bool outline) {
	doc->ClippingPolygon(bbDoubleArrayTowxPdfArrayDouble(x), bbDoubleArrayTowxPdfArrayDouble(y), outline);
}

void bmx_wxpdfdocument_clippingrect(wxPdfDocument * doc, double x, double y, double w, double h, bool outline) {
	doc->ClippingRect(x, y, w, h, outline);
}

void bmx_wxpdfdocument_clippingtext(wxPdfDocument * doc, double x, double y, BBString * txt, bool outline) {
	doc->ClippingText(x, y, wxStringFromBBString(txt), outline);
}

void bmx_wxpdfdocument_closepath(wxPdfDocument * doc, int style) {
	doc->ClosePath(style);
}

int bmx_wxpdfdocument_setalpha(wxPdfDocument * doc, double lineAlpha, double fillAlpha, wxPdfBlendMode blendMode) {
	return doc->SetAlpha(lineAlpha, fillAlpha, blendMode);
}

void bmx_wxpdfdocument_rect(wxPdfDocument * doc, double x, double y, double w, double h, int style) {
	doc->Rect(x, y, w, h, style);
}

int bmx_wxpdfdocument_imagemask(wxPdfDocument * doc, BBString * file, BBString * mimeType) {
	return doc->ImageMask(wxStringFromBBString(file), wxStringFromBBString(mimeType));
}

void bmx_wxpdfdocument_starttransform(wxPdfDocument * doc) {
	doc->StartTransform();
}

void bmx_wxpdfdocument_settopmargin(wxPdfDocument * doc, double margin) {
	doc->SetTopMargin(margin);
}

void bmx_wxpdfdocument_setviewerpreferences(wxPdfDocument * doc, int preferences) {
	doc->SetViewerPreferences(preferences);
}

void bmx_wxpdfdocument_setxy(wxPdfDocument * doc, double x, double y) {
	doc->SetXY(x, y);
}

bool bmx_wxpdfdocument_skew(wxPdfDocument * doc, double xAngle, double yAngle, double x, double y) {
	return doc->Skew(xAngle, yAngle, x, y);
}

bool bmx_wxpdfdocument_skewx(wxPdfDocument * doc, double xAngle, double x, double y) {
	return doc->SkewX(xAngle, x, y);
}

bool bmx_wxpdfdocument_skewy(wxPdfDocument * doc, double yAngle, double x, double y) {
	return doc->SkewY(yAngle, x, y);
}

void bmx_wxpdfdocument_starpolygon(wxPdfDocument * doc, double x0, double y0, double r,
		int nv, int nr, double angle, bool circle, int style, int circleStyle, MaxPdfLineStyle * circleLineStype, MaxPdfColour * circleFillColor) {
	if (circleLineStype) {
		if (circleFillColor) {
			doc->StarPolygon(x0, y0, r, nv, nr, angle, circle, style, circleStyle, circleLineStype->Style(), circleFillColor->Colour());
		} else {
			doc->StarPolygon(x0, y0, r, nv, nr, angle, circle, style, circleStyle, circleLineStype->Style(), wxPdfColour());
		}
	} else {
		if (circleFillColor) {
			doc->StarPolygon(x0, y0, r, nv, nr, angle, circle, style, circleStyle, wxPdfLineStyle(), circleFillColor->Colour());
		} else {
			doc->StarPolygon(x0, y0, r, nv, nr, angle, circle, style, circleStyle, wxPdfLineStyle(), wxPdfColour());
		}
	}
}

void bmx_wxpdfdocument_shape(wxPdfDocument * doc, MaxPdfShape * shape, int style) {
	doc->Shape(shape->Shape(), style);
}

void bmx_wxpdfdocument_shapedtext(wxPdfDocument * doc, MaxPdfShape * shape, BBString * text, wxPdfShapedTextMode mode) {
	doc->ShapedText(shape->Shape(), wxStringFromBBString(text), mode);
}

bool bmx_wxpdfdocument_setlink(wxPdfDocument * doc, int link, double y, int page) {
	return doc->SetLink(link, y, page);
}

double bmx_wxpdfdocument_getpageheight(wxPdfDocument * doc) {
	return doc->GetPageHeight();
}

double bmx_wxpdfdocument_getpagewidth(wxPdfDocument * doc) {
	return doc->GetPageWidth();
}

double bmx_wxpdfdocument_getrightmargin(wxPdfDocument * doc) {
	return doc->GetRightMargin();
}

double bmx_wxpdfdocument_getscalefactor(wxPdfDocument * doc) {
	return doc->GetScaleFactor();
}

bool bmx_wxpdfdocument_getsourceinfo(wxPdfDocument * doc, MaxPdfInfo * info) {
	return doc->GetSourceInfo(info->Info());
}

int bmx_wxpdfdocument_coonspatchgradient(wxPdfDocument * doc, MaxPdfCoonsPatchMesh * mesh, double minCoord, double maxCoord) {
	return doc->CoonsPatchGradient(mesh->Mesh(), minCoord, maxCoord);
}

void bmx_wxpdfdocument_curveto(wxPdfDocument * doc, double x1, double y1, double x2, double y2, double x3, double y3) {
	doc->CurveTo(x1, y1, x2, y2, x3, y3);
}

int bmx_wxpdfdocument_endtemplate(wxPdfDocument * doc) {
	return doc->EndTemplate();
}

MaxPdfColour * bmx_wxpdfdocument_getdrawcolor(wxPdfDocument * doc) {
	return new MaxPdfColour(doc->GetDrawColor());
}


MaxPdfColour * bmx_wxpdfdocument_getfillcolor(wxPdfDocument * doc) {
	return new MaxPdfColour(doc->GetFillColor());
}

MaxPdfFontDescription * bmx_wxpdfdocument_getfontdescription(wxPdfDocument * doc) {
	return new MaxPdfFontDescription(doc->GetFontDescription());
}

MaxPdfLineStyle *  bmx_wxpdfdocument_getlinestyle(wxPdfDocument * doc) {
	return new MaxPdfLineStyle(doc->GetLineStyle());
}

void bmx_wxpdfdocument_gettemplatebbox(wxPdfDocument * doc, int templateId, double * x, double * y, double * width, double * height) {
	doc->GetTemplateBBox(templateId, *x, *y, *width, *height);
}

void bmx_wxpdfdocument_gettemplatessize(wxPdfDocument * doc, int templateId, double * width, double * height) {
	doc->GetTemplateSize(templateId, *width, *height);
}

MaxPdfColour * bmx_wxpdfdocument_gettextcolor(wxPdfDocument * doc) {
	return new MaxPdfColour(doc->GetTextColor());
}

bool bmx_wxpdfdocument_imageimage(wxPdfDocument * doc, BBString * name, MaxImage * image, double x, double y, double w, double h, MaxPdfLink * link, int maskImage) {
	if (link) {
		return doc->Image(wxStringFromBBString(name), image->Image(), x, y, w, h, link->Link(), maskImage);
	} else {
		return doc->Image(wxStringFromBBString(name), image->Image(), x, y, w, h, wxPdfLink(-1), maskImage);
	}
}

bool bmx_wxpdfdocument_imagemaskimage(wxPdfDocument * doc, BBString * name, MaxImage * image) {
	return doc->ImageMask(wxStringFromBBString(name), image->Image());
}

int bmx_wxpdfdocument_importpage(wxPdfDocument * doc, int page) {
	return doc->ImportPage(page);
}

bool bmx_wxpdfdocument_isinfooter(wxPdfDocument * doc) {
	return doc->IsInFooter();
}

void bmx_wxpdfdocument_line(wxPdfDocument * doc, double x1, double y1, double x2, double y2) {
	doc->Line(x1, y1, x2, y2);
}

int bmx_wxpdfdocument_lineargradient(wxPdfDocument * doc, MaxPdfColour * col1, MaxPdfColour * col2, wxPdfLinearGradientType gradientType) {
	return doc->LinearGradient(col1->Colour(), col2->Colour(), gradientType);
}

int bmx_wxpdfdocument_linecount(wxPdfDocument * doc, double w, BBString * txt) {
	return doc->LineCount(w, wxStringFromBBString(txt));
}

void bmx_wxpdfdocument_lineto(wxPdfDocument * doc, double x, double y) {
	doc->LineTo(x, y);
}

void bmx_wxpdfdocument_link(wxPdfDocument * doc, double x, double y, double w, double h, MaxPdfLink * link) {
	doc->Link(x, y, w, h, link->Link());
}

void bmx_wxpdfdocument_marker(wxPdfDocument * doc, double x, double y, wxPdfMarker markerType, double size) {
	doc->Marker(x, y, markerType, size);
}

void bmx_wxpdfdocument_midaxialgradient(wxPdfDocument * doc, MaxPdfColour * col1, MaxPdfColour * col2, double x1, double y1, double x2, double y2, double midpoint, double intexp) {
	doc->MidAxialGradient(col1->Colour(), col2->Colour(), x1, y1, x2, y2, midpoint, intexp);
}

void bmx_wxpdfdocument_mirrorh(wxPdfDocument * doc, double x) {
	doc->MirrorH(x);
}

void bmx_wxpdfdocument_mirrorv(wxPdfDocument * doc, double y) {
	doc->MirrorV(y);
}

void bmx_wxpdfdocument_moveto(wxPdfDocument * doc, double x, double y) {
	doc->MoveTo(x, y);
}

void bmx_wxpdfdocument_polygon(wxPdfDocument * doc, BBArray * x, BBArray * y, int style) {
	doc->Polygon(bbDoubleArrayTowxPdfArrayDouble(x), bbDoubleArrayTowxPdfArrayDouble(y), style);
}

void bmx_wxpdfdocument_pushbutton(wxPdfDocument * doc, BBString * name, double width, double height, BBString * caption, BBString * action) {
	doc->PushButton(wxStringFromBBString(name), width, height, wxStringFromBBString(caption), wxStringFromBBString(action));
}

void bmx_wxpdfdocument_pushbuttonxy(wxPdfDocument * doc, BBString * name, double x, double y, double width, double height, BBString * caption, BBString * action) {
	doc->PushButton(wxStringFromBBString(name), x, y, width, height, wxStringFromBBString(caption), wxStringFromBBString(action));
}

int bmx_wxpdfdocument_radialgradient(wxPdfDocument * doc, MaxPdfColour * col1, MaxPdfColour * col2, double x1, double y1, double r1, double x2, double y2, double r2, double intexp) {
	return doc->RadialGradient(col1->Colour(), col2->Colour(), x1, y1, r1, x2, y2, r2, intexp);
}

void bmx_wxpdfdocument_radiobutton(wxPdfDocument * doc, BBString * group, BBString * name, double width) {
	doc->RadioButton(wxStringFromBBString(group), wxStringFromBBString(name), width);
}

void bmx_wxpdfdocument_radiobuttonxy(wxPdfDocument * doc, BBString * group, BBString * name, double x, double y, double width) {
	doc->RadioButton(wxStringFromBBString(group), wxStringFromBBString(name), x, y, width);
}

void bmx_wxpdfdocument_settextcolorpdf(wxPdfDocument * doc, MaxPdfColour * pdfColour) {
	doc->SetTextColor(pdfColour->Colour());
}

void bmx_wxpdfdocument_settextcolorrgb(wxPdfDocument * doc, int red, int green, int blue) {
	doc->SetTextColor(static_cast<unsigned char>(red), static_cast<unsigned char>(green), static_cast<unsigned char>(blue));
}

void bmx_wxpdfdocument_settextcolorcmyk(wxPdfDocument * doc, double cyan, double magenta, double yellow, double black) {
	doc->SetTextColor(cyan, magenta, yellow, black);
}

void bmx_wxpdfdocument_settextcolorname(wxPdfDocument * doc, BBString * name, double tint) {
	doc->SetTextColor(wxStringFromBBString(name), tint);
}

void bmx_wxpdfdocument_setdrawcolorpdf(wxPdfDocument * doc, MaxPdfColour * pdfColour) {
	doc->SetDrawColor(pdfColour->Colour());
}

void bmx_wxpdfdocument_setdrawcolorrgb(wxPdfDocument * doc, int red, int green, int blue) {
	doc->SetDrawColor(static_cast<unsigned char>(red), static_cast<unsigned char>(green), static_cast<unsigned char>(blue));
}

void bmx_wxpdfdocument_setdrawcolorcmyk(wxPdfDocument * doc, double cyan, double magenta, double yellow, double black) {
	doc->SetDrawColor(cyan, magenta, yellow, black);
}

void bmx_wxpdfdocument_setdrawcolorname(wxPdfDocument * doc, BBString * name, double tint) {
	doc->SetDrawColor(wxStringFromBBString(name), tint);
}

void bmx_wxpdfdocument_setfillcolorpdf(wxPdfDocument * doc, MaxPdfColour * pdfColour) {
	doc->SetFillColor(pdfColour->Colour());
}

void bmx_wxpdfdocument_setfillcolorrgb(wxPdfDocument * doc, int red, int green, int blue) {
	doc->SetFillColor(static_cast<unsigned char>(red), static_cast<unsigned char>(green), static_cast<unsigned char>(blue));
}

void bmx_wxpdfdocument_setfillcolorcmyk(wxPdfDocument * doc, double cyan, double magenta, double yellow, double black) {
	doc->SetFillColor(cyan, magenta, yellow, black);
}

void bmx_wxpdfdocument_setfillcolorname(wxPdfDocument * doc, BBString * name, double tint) {
	doc->SetFillColor(wxStringFromBBString(name), tint);
}

void bmx_wxpdfdocument_rotate(wxPdfDocument * doc, double angle, double x, double y) {
	doc->Rotate(angle, x, y);
}

void bmx_wxpdfdocument_rotatedtext(wxPdfDocument * doc, double x, double y, BBString * txt, double angle) {
	doc->RotatedText(x, y, wxStringFromBBString(txt), angle);
}

void bmx_wxpdfdocument_roundedrect(wxPdfDocument * doc, double x, double y, double w, double h, int roundCorner, int style) {
	doc->RoundedRect(x, y, w, h, roundCorner, style);
}

bool bmx_wxpdfdocument_scale(wxPdfDocument * doc, double sx, double sy, double x, double y) {
	return doc->Scale(sx, sy, x, y);
}

bool bmx_wxpdfdocument_scalex(wxPdfDocument * doc, double sx, double x, double y) {
	return doc->ScaleX(sx, x, y);
}

bool bmx_wxpdfdocument_scaley(wxPdfDocument * doc, double sy, double x, double y) {
	return doc->ScaleY(sy, x, y);
}

bool bmx_wxpdfdocument_scalexy(wxPdfDocument * doc, double s, double x, double y) {
	return doc->ScaleXY(s, x, y);
}

void bmx_wxpdfdocument_setdrawcolorgrayscale(wxPdfDocument * doc, int grayscale) {
	doc->SetDrawColor(static_cast<unsigned char>(grayscale));
}

void bmx_wxpdfdocument_setfillcolorgrayscale(wxPdfDocument * doc, int grayscale) {
	doc->SetFillColor(static_cast<unsigned char>(grayscale));
}

int bmx_wxpdfdocument_setsourcefile(wxPdfDocument * doc, BBString * filename, BBString * password) {
	return doc->SetSourceFile(wxStringFromBBString(filename), wxStringFromBBString(password));
}

// *********************************************

MaxPdfColour * bmx_wxpdfcolour_createforname(BBString * name) {
	wxPdfColour c(wxStringFromBBString(name));
	return new MaxPdfColour(c);
}

void bmx_wxpdfcolour_delete(MaxPdfColour * colour) {
	delete colour;
}

// *********************************************

MaxPdfInfo * bmx_wxpdfinfo_create() {
	wxPdfInfo i;
	return new MaxPdfInfo(i);
}

BBString * bmx_wxpdfinfo_gettitle(MaxPdfInfo * info) {
	return bbStringFromWxString(info->Info().GetTitle());
}

BBString * bmx_wxpdfinfo_getauthor(MaxPdfInfo * info) {
	return bbStringFromWxString(info->Info().GetAuthor());
}

BBString * bmx_wxpdfinfo_getsubject(MaxPdfInfo * info) {
	return bbStringFromWxString(info->Info().GetSubject());
}

BBString * bmx_wxpdfinfo_getkeywords(MaxPdfInfo * info) {
	return bbStringFromWxString(info->Info().GetKeywords());
}

BBString * bmx_wxpdfinfo_getcreator(MaxPdfInfo * info) {
	return bbStringFromWxString(info->Info().GetCreator());
}

BBString * bmx_wxpdfinfo_getproducer(MaxPdfInfo * info) {
	return bbStringFromWxString(info->Info().GetProducer());
}

BBString * bmx_wxpdfinfo_getcreationdate(MaxPdfInfo * info) {
	return bbStringFromWxString(info->Info().GetCreationDate());
}

BBString * bmx_wxpdfinfo_getmoddate(MaxPdfInfo * info) {
	return bbStringFromWxString(info->Info().GetModDate());
}

void bmx_wxpdfinfo_delete(MaxPdfInfo * info) {
	delete info;
}

