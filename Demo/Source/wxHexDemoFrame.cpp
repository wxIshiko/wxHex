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

#include "wxHexDemoFrame.h"
#include "wxHexControls/wxHexControls.h"
#include <wx/menu.h>
#include <wx/sizer.h>

wxHexDemoFrame::wxHexDemoFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	CreateMenuBar();

	wxHexEditCtrl* control = new wxHexEditCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(300, 200));

	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->Add(control, 1, wxEXPAND);
	SetSizerAndFit(topSizer);
}

void wxHexDemoFrame::CreateMenuBar()
{
	wxMenuBar* menuBar = new wxMenuBar;

	wxMenu* menuFile = new wxMenu;
	menuFile->Append(wxID_EXIT);
	menuBar->Append(menuFile, "&File");

	SetMenuBar(menuBar);
}

void wxHexDemoFrame::OnExit(wxCommandEvent& evt)
{
	Close();
}

wxBEGIN_EVENT_TABLE(wxHexDemoFrame, wxFrame)
	EVT_MENU(wxID_EXIT, wxHexDemoFrame::OnExit)
wxEND_EVENT_TABLE()
