/*
	Copyright (c) 2015-2016 Xavier Leclercq

	Permission is hereby granted, free of charge, to any person obtaining a
	copy of this software and associated documentation files (the "Software"),
	to deal in the Software without restriction, including without limitation
	the rights to use, copy, modify, merge, publish, distribute, sublicense,
	and/or sell copies of the Software, and to permit persons to whom the
	Software is furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
	THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
	IN THE SOFTWARE.
*/

#ifndef _WX_HEX_WXHEXDATAPANEL_H_
#define _WX_HEX_WXHEXDATAPANEL_H_

#include "wxhexdata.h"
#include <wx/panel.h>
#include <wx/caret.h>
#include <wx/sharedptr.h>

class wxHexDataPanel : public wxPanel
{
public:
	wxHexDataPanel(wxWindow* parent,
		size_t increment);

	void Init(wxSharedPtr<wxHexData> data);

	virtual wxSize GetMinSize() const;

private:
	void OnPaint(wxPaintEvent& evt);
	void OnChar(wxKeyEvent &evt);

private:
	wxSharedPtr<wxHexData> m_data;
	size_t m_startOffset;
	size_t m_increment;
	size_t m_leftMargin;
	size_t m_rightMargin;
	size_t m_topMargin;
	size_t m_bottomMargin;
	size_t m_lineHeight;
	size_t m_count;
	
	wxDECLARE_EVENT_TABLE();
};

#endif
