/*
	Copyright (c) 2015 Xavier Leclercq

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

#include "wxHexGridCtrl.h"
#include <wx/sizer.h>

wxHexGridCtrl::wxHexGridCtrl(wxWindow* parent,
							 wxWindowID id,
							 const wxPoint& pos,
							 const wxSize& size)
	: wxScrolledWindow(parent, id, pos, size), m_offsets(0),
	m_data(0)
{
	m_offsets = new wxHexOffsetsPanel(this, 0, 16, 64);

	m_data = new wxHexDataPanel(this, 16);

	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->Add(m_offsets, 0, wxEXPAND);
	topSizer->Add(m_data, 1, wxEXPAND);
	SetSizerAndFit(topSizer);

	FitInside();
	SetScrollRate(5, 5);
}

wxHexGridCtrl::~wxHexGridCtrl()
{
}

bool wxHexGridCtrl::AcceptsFocus() const
{
	return false;
}

void wxHexGridCtrl::SetData(std::shared_ptr<wxHexData>& data)
{
	m_offsets->Init(data->GetLength());
	m_data->Init(data);
}

void wxHexGridCtrl::OnChar(wxKeyEvent &evt)
{
	switch (evt.GetKeyCode())
	{
	case WXK_LEFT:
		break;

	case WXK_RIGHT:
	{
		wxPoint caretPos = GetCaret()->GetPosition();
		caretPos.x += 20;
		GetCaret()->Move(caretPos);
	}
		break;

	default:
		evt.Skip();
		break;
	}
}

wxBEGIN_EVENT_TABLE(wxHexGridCtrl, wxScrolledWindow)
	EVT_CHAR(wxHexGridCtrl::OnChar)
wxEND_EVENT_TABLE()
