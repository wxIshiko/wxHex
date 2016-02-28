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

#include "wxHexData.h"

static const size_t s_bufferSize = 0x4000;
static const size_t s_bufferShift = 14;
static const size_t s_bufferMask = 0x3FFF;

wxHexData::wxHexData()
{
}

wxHexData::~wxHexData()
{
	for (std::map<size_t, unsigned char*>::iterator it = m_cache.begin();
		 it != m_cache.end();
		 ++it)
	{
		delete[] it->second;
	}
}

void wxHexData::GetBytes(size_t pos, size_t count, unsigned char* buffer)
{
	// Verify that pos and count don't get past the end of the data.
	size_t validatedCount = count;
	size_t length = GetLength();
	if ((pos + count) > length)
	{
		if (pos < length)
		{
			validatedCount = length - pos;
		}
		else
		{
			// TODO
			return;
		}
	}

	size_t alignedPos = pos >> s_bufferShift;
	std::map<size_t, unsigned char*>::const_iterator it = m_cache.find(alignedPos);
	if (it == m_cache.end())
	{
		unsigned char* newBuffer = new unsigned char[s_bufferSize];
		m_cache[alignedPos] = newBuffer;
		DoGetBytes(alignedPos, s_bufferSize, newBuffer);
		it = m_cache.find(alignedPos);
	}

	size_t bufferOffset = pos & s_bufferMask;
	std::memcpy(buffer, it->second + bufferOffset, validatedCount);
}
