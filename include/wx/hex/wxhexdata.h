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

#ifndef _WX_HEX_WXHEXDATA_H_
#define _WX_HEX_WXHEXDATA_H_

#include <wx/hashmap.h>

class wxHexData
{
public:
	wxHexData();
	virtual ~wxHexData();

	virtual size_t GetLength() const = 0;
	virtual void GetBytes(size_t pos, size_t count, unsigned char* buffer);

private:
	virtual void DoGetBytes(size_t pos, size_t count, unsigned char* buffer) = 0;

private:
    WX_DECLARE_HASH_MAP(size_t, unsigned char*, wxIntegerHash, wxIntegerEqual, wxHexDataCache);

private:
	// The cache is a list of fixed size buffers.
	// The key is the position of the buffer in the original input
	// The key is aligned according to the size of the buffer.
	// In the current implementation the size of each buffer is 
	// 16kb (2^14, 0x4000)
    wxHexDataCache m_cache;
};

#endif
