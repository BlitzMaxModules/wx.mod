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

#ifndef _WX_MAX_DATETIME_H_
#define _WX_MAX_DATETIME_H_

#include "wxglue.h"
#include "wx/datetime.h"
#include "wx/dateevt.h"

class MaxDateTime;
class MaxDateSpan;
class MaxTimeSpan;
class MaxTimeZone;

extern "C" {

#include <blitz.h>

	void bmx_wxdatetime_setcountry(wxDateTime::Country country);
	wxDateTime::Country bmx_wxdatetime_getcountry();
	bool bmx_wxdatetime_iswesteuropeancountry(wxDateTime::Country country);
	int bmx_wxdatetime_getcurrentyear(wxDateTime::Calendar cal);
	int bmx_wxdatetime_convertyeartobc(int year);
	wxDateTime::Month bmx_wxdatetime_getcurrentmonth(wxDateTime::Calendar cal);
	bool bmx_wxdatetime_isleapyear(int year, wxDateTime::Calendar cal);
	int bmx_wxdatetime_getcenturyforyear(int year);
	int bmx_wxdatetime_getnumberofdaysforyear(int year, wxDateTime::Calendar cal);
	int bmx_wxdatetime_getnumberofdays(wxDateTime::Month month, int year, wxDateTime::Calendar cal);
	BBString * bmx_wxdatetime_getmonthname(wxDateTime::Month month, wxDateTime::NameFlags flags);
	BBString * bmx_wxdatetime_getweekdayname(wxDateTime::WeekDay weekday, wxDateTime::NameFlags flags);
	BBString * bmx_wxdatetime_getamstring();
	BBString * bmx_wxdatetime_getpmstring();
	bool bmx_wxdatetime_isdstapplicable(int year, wxDateTime::Country country);
	MaxDateTime * bmx_wxdatetime_getbegindst(int year, wxDateTime::Country country);
	MaxDateTime * bmx_wxdatetime_getenddst(int year, wxDateTime::Country country);
	MaxDateTime * bmx_wxdatetime_now();
	MaxDateTime * bmx_wxdatetime_unow();
	MaxDateTime * bmx_wxdatetime_today();

	MaxDateTime * bmx_wxdatetime_create();
	MaxDateTime * bmx_wxdatetime_createfromtimet(time_t time);
	MaxDateTime * bmx_wxdatetime_createfromjdn(double jdn);
	MaxDateTime * bmx_wxdatetime_createfromhms(int hour, int minute, int second, int millisec);
	MaxDateTime * bmx_wxdatetime_createfromdmy(int day, wxDateTime::Month month, int year, int hour, int minute, int second, int millisec);
	void bmx_wxdatetime_delete(MaxDateTime * dt);

	void bmx_wxdatetime_settocurrent(MaxDateTime * datetime);
	void bmx_wxdatetime_settimet(MaxDateTime * datetime, time_t timet);
	void bmx_wxdatetime_setjdn(MaxDateTime * datetime, double jdn);
	void bmx_wxdatetime_sethms(MaxDateTime * datetime, int hour, int minute, int second, int millisec);
	void bmx_wxdatetime_setdmy(MaxDateTime * datetime, int day, wxDateTime::Month month, int year, int hour, int minute, int second, int millisec);
	void bmx_wxdatetime_resettime(MaxDateTime * datetime);
	void bmx_wxdatetime_setyear(MaxDateTime * datetime, int year);
	void bmx_wxdatetime_setmonth(MaxDateTime * datetime, wxDateTime::Month month);
	void bmx_wxdatetime_setday(MaxDateTime * datetime, int day);
	void bmx_wxdatetime_sethour(MaxDateTime * datetime, int hour);
	void bmx_wxdatetime_setminute(MaxDateTime * datetime, int minute);
	void bmx_wxdatetime_setsecond(MaxDateTime * datetime, int second);
	void bmx_wxdatetime_setmillisecond(MaxDateTime * datetime, int millisec);
	bool bmx_wxdatetime_isvalid(MaxDateTime * datetime);
	MaxDateTime * bmx_wxdatetime_getdateonly(MaxDateTime * datetime);
	time_t bmx_wxdatetime_getticks(MaxDateTime * datetime);
	int bmx_wxdatetime_getcentury(MaxDateTime * datetime, MaxTimeZone * tz);
	int bmx_wxdatetime_getyear(MaxDateTime * datetime, MaxTimeZone * tz);
	wxDateTime::Month bmx_wxdatetime_getmonth(MaxDateTime * datetime, MaxTimeZone * tz);
	int bmx_wxdatetime_getday(MaxDateTime * datetime, MaxTimeZone * tz);
	wxDateTime::WeekDay bmx_wxdatetime_getweekday(MaxDateTime * datetime, MaxTimeZone * tz);
	int bmx_wxdatetime_gethour(MaxDateTime * datetime, MaxTimeZone * tz);
	int bmx_wxdatetime_getminute(MaxDateTime * datetime, MaxTimeZone * tz);
	int bmx_wxdatetime_getsecond(MaxDateTime * datetime, MaxTimeZone * tz);
	int bmx_wxdatetime_getmillisecond(MaxDateTime * datetime, MaxTimeZone * tz);
	int bmx_wxdatetime_getdayofyear(MaxDateTime * datetime, MaxTimeZone * tz);
	int bmx_wxdatetime_getweekofyear(MaxDateTime * datetime, wxDateTime::WeekFlags flags, MaxTimeZone * tz);
	int bmx_wxdatetime_getweekofmonth(MaxDateTime * datetime, wxDateTime::WeekFlags flags, MaxTimeZone * tz);
	bool bmx_wxdatetime_isworkday(MaxDateTime * datetime, wxDateTime::Country country);
	void bmx_wxdatetime_setfromdos(MaxDateTime * datetime, unsigned long ddt);
	unsigned long bmx_wxdatetime_getasdos(MaxDateTime * datetime);
	bool bmx_wxdatetime_isequalto(MaxDateTime * datetime, MaxDateTime * dt);
	bool bmx_wxdatetime_isearlierthan(MaxDateTime * datetime, MaxDateTime * dt);
	bool bmx_wxdatetime_islaterthan(MaxDateTime * datetime, MaxDateTime * dt);
	bool bmx_wxdatetime_isstrictlybetween(MaxDateTime * datetime, MaxDateTime * t1, MaxDateTime * t2);
	bool bmx_wxdatetime_isbetween(MaxDateTime * datetime, MaxDateTime * t1, MaxDateTime * t2);
	bool bmx_wxdatetime_issamedate(MaxDateTime * datetime, MaxDateTime * dt);
	bool bmx_wxdatetime_issametime(MaxDateTime * datetime, MaxDateTime * dt);


	MaxDateTime * bmx_wxdateevent_getdate(wxDateEvent & event);
	void bmx_wxdateevent_setdate(wxDateEvent & event, MaxDateTime * date);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxDateTime
{
public:
	MaxDateTime(const wxDateTime & d);
	wxDateTime & DateTime();

private:
	wxDateTime dateTime;

};

class MaxDateSpan
{
public:
	MaxDateSpan(const wxDateSpan & d);
	wxDateSpan & Span();

private:
	wxDateSpan dateSpan;

};

class MaxTimeSpan
{
public:
	MaxTimeSpan(const wxTimeSpan & t);
	wxTimeSpan & Span();

private:
	wxTimeSpan timeSpan;

};

class MaxTimeZone
{
public:
	MaxTimeZone(const wxDateTime::TimeZone & t);
	wxDateTime::TimeZone & TimeZone();

private:
	wxDateTime::TimeZone timeZone;

};


#endif // _WX_MAX_DATETIME_H_
