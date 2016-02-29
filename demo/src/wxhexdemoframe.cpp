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

#include "wxhexdemoframe.h"
#include <wx/menu.h>
#include <wx/sizer.h>
#include <wx/filedlg.h>
#include <wx/aboutdlg.h>

wxHexDemoFrame::wxHexDemoFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title), m_hexEditCtrl(0)
{
	CreateMenuBar();

	m_hexEditCtrl = new wxHexEditCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(300, 200));

	wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->Add(m_hexEditCtrl, 1, wxEXPAND);
	SetSizer(topSizer);
}

void wxHexDemoFrame::CreateMenuBar()
{
	wxMenuBar* menuBar = new wxMenuBar;

	wxMenu* menuFile = new wxMenu;
	menuFile->Append(wxID_OPEN);
	menuFile->Append(wxID_EXIT);
	menuBar->Append(menuFile, "&File");

	wxMenu* menuHelp = new wxMenu;
	menuHelp->Append(wxID_ABOUT);
	menuBar->Append(menuHelp, "&Help");

	SetMenuBar(menuBar);
}

void wxHexDemoFrame::OnOpen(wxCommandEvent& evt)
{
	wxFileDialog* fileDialog = new wxFileDialog(this);
	if (fileDialog->ShowModal() == wxID_OK)
	{
		wxString selectedFile = fileDialog->GetPath();
		m_data = new wxHexDataFile(selectedFile);
		m_hexEditCtrl->SetData(m_data);
	}

	fileDialog->Destroy();
}

void wxHexDemoFrame::OnExit(wxCommandEvent& evt)
{
	Close();
}

void wxHexDemoFrame::OnAbout(wxCommandEvent& evt)
{
	wxAboutDialogInfo info;

	info.SetName(L"wxHexDemo");
	info.SetVersion(L"0.1.0");
	info.SetDescription(L"A sample application for the wxHexEditCtrl control.");
	info.SetCopyright(L"Copyright (c) 2015 Xavier Leclercq");
	info.SetWebSite(L"http://www.needfulsoftware.com/Products");

	wxArrayString developers;
	developers.Add(L"Xavier Leclercq");
	info.SetDevelopers(developers);

	wxArrayString docWriters;
	docWriters.Add(L"Xavier Leclercq");
	info.SetDocWriters(docWriters);

	info.SetLicence(
		L"Permission is hereby granted, free of charge, to any person obtaining a "
		L"copy of this software and associated documentation files (the \"Software\"), "
		L"to deal in the Software without restriction, including without limitation "
		L"the rights to use, copy, modify, merge, publish, distribute, sublicense, "
		L"and / or sell copies of the Software, and to permit persons to whom the "
		L"Software is furnished to do so, subject to the following conditions :\n"
		L"\n"
		L"The above copyright notice and this permission notice shall be included in "
		L"all copies or substantial portions of the Software.\n"
		L"\n"
		L"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR "
		L"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, "
		L"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL "
		L"THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER "
		L"LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING "
		L"FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS "
		L"IN THE SOFTWARE.");

	wxAboutBox(info);
}

wxBEGIN_EVENT_TABLE(wxHexDemoFrame, wxFrame)
	EVT_MENU(wxID_OPEN, wxHexDemoFrame::OnOpen)
	EVT_MENU(wxID_EXIT, wxHexDemoFrame::OnExit)
	EVT_MENU(wxID_ABOUT, wxHexDemoFrame::OnAbout)
wxEND_EVENT_TABLE()
