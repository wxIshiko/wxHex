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

#include "wxHexEditCtrl.h"
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>

wxHexEditCtrl::wxHexEditCtrl(wxWindow* parent, 
							 wxWindowID id,
							 const wxPoint& pos,
							 const wxSize& size)
	: wxPanel(parent, id, pos, size), m_hexGridCtrl(0)
{
	wxStaticText* staticText = new wxStaticText(this, wxID_ANY, "Static Text");
	wxTextCtrl* offset = new wxTextCtrl(this, wxID_ANY);

	wxBoxSizer* infoBarSizer = new wxBoxSizer(wxHORIZONTAL);
	infoBarSizer->Add(staticText);
	infoBarSizer->Add(offset);

	m_hexGridCtrl = new wxHexGridCtrl(this, wxID_ANY);

	wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
	topSizer->Add(infoBarSizer);
	topSizer->Add(m_hexGridCtrl, 1, wxEXPAND);
	SetSizerAndFit(topSizer);
}

void wxHexEditCtrl::SetData(std::shared_ptr<wxHexData>& data)
{
	m_hexGridCtrl->SetData(data);
}
