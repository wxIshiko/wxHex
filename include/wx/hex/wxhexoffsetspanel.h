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

#ifndef _WX_HEX_WXHEXOFFSETSPANEL_H_
#define _WX_HEX_WXHEXOFFSETSPANEL_H_

#include <wx/panel.h>

// This represents the panel in a wxHexEditGrid that
// displays the position in the input corresponding
// to the data being displayed.
// Typically developers would not use this class
// directly but use wxHexEditCtrl or wxHexGridCtrl.
// It is provided to build more advanced custom controls.
class wxHexOffsetsPanel : public wxPanel
{
public:
	wxHexOffsetsPanel(wxWindow* parent, size_t startOffset,
		size_t increment, size_t endOffset);

	void Init(size_t endOffset);

	virtual wxSize GetMinSize() const;
	virtual bool AcceptsFocus() const;

private:
	void OnPaint(wxPaintEvent& evt);

private:
	size_t m_startOffset;
	size_t m_increment;
	size_t m_endOffset;
	size_t m_numberOfDigits;
	size_t m_leftMargin;
	size_t m_rightMargin;
	size_t m_topMargin;
	size_t m_bottomMargin;
	size_t m_lineHeight;

	wxDECLARE_EVENT_TABLE();
};

#endif
