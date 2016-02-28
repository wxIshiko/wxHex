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

#include "wxhexoffsetspanel.h"
#include <wx/dcclient.h>

wxHexOffsetsPanel::wxHexOffsetsPanel(wxWindow* parent,
									 size_t startOffset,
									 size_t increment,
									 size_t endOffset)
	: wxPanel(parent, wxID_ANY),
	m_startOffset(startOffset), m_increment(increment), m_endOffset(endOffset),
	m_leftMargin(5), m_rightMargin(5), m_topMargin(5), m_bottomMargin(5),
	m_lineHeight(15)
{
	SetBackgroundColour(*wxWHITE);

	m_numberOfDigits = log10(m_endOffset) + 1;
}

void wxHexOffsetsPanel::Init(size_t endOffset)
{
	m_endOffset = endOffset;
	m_numberOfDigits = log10(endOffset) + 1;

	InvalidateBestSize();
	Refresh();
	PostSizeEventToParent();
}

wxSize wxHexOffsetsPanel::GetMinSize() const
{
	std::string str;
	for (size_t i = 0; i < m_numberOfDigits; ++i)
	{
		str.append("0");
	}
	wxSize result = GetTextExtent(str.c_str());
	result.SetHeight(m_lineHeight * ((m_endOffset - m_startOffset + m_increment - 1) / m_increment));
	result.IncBy(m_leftMargin + m_rightMargin, m_topMargin + m_bottomMargin);
	return result;
}

bool wxHexOffsetsPanel::AcceptsFocus() const
{
	return false;
}

void wxHexOffsetsPanel::OnPaint(wxPaintEvent& evt)
{
	wxPaintDC dc(this);
	dc.SetTextForeground(*wxBLACK);

	wxCoord y = m_topMargin;
	size_t currentOffset = m_startOffset;
	while (currentOffset <= m_endOffset)
	{
        wxString string;
        string << currentOffset;
		dc.DrawText(string, m_leftMargin, y);

		y += m_lineHeight;
		currentOffset += m_increment;
	}
}

wxBEGIN_EVENT_TABLE(wxHexOffsetsPanel, wxPanel)
	EVT_PAINT(wxHexOffsetsPanel::OnPaint)
wxEND_EVENT_TABLE()
