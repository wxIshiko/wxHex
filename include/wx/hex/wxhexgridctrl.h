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

#ifndef _WXHEX_CONTROLS_WXHEXGRIDCTRL_H_
#define _WXHEX_CONTROLS_WXHEXGRIDCTRL_H_

#include "wxHexData.h"
#include "wxHexOffsetsPanel.h"
#include "wxHexDataPanel.h"
#include <wx/scrolwin.h>
#include <wx/panel.h>
#include <memory>

class wxHexGridCtrl : public wxScrolledWindow
{
public:
	wxHexGridCtrl(wxWindow* parent, wxWindowID id,
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize);
	virtual ~wxHexGridCtrl();
	
	virtual bool AcceptsFocus() const;

	void SetData(std::shared_ptr<wxHexData>& data);

	void OnChar(wxKeyEvent &evt);

private:
	wxHexOffsetsPanel* m_offsets;
	wxHexDataPanel* m_data;

	wxDECLARE_EVENT_TABLE();
};

#endif
