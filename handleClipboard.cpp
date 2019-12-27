/* This file contains the only platform-specific code. If you want to port this
program to another platform, just change this file to work with the platform's
clipboard API. */

#include "stdafx.h"
#include "handleClipboard.h"
#include <stdexcept>
#include <WinUser.h>
#include <WinBase.h>

#define CHOSEN_FORMAT CF_UNICODETEXT
using chosen_char = chosen_string::value_type;

class RaiiClipboard
{
public:
	RaiiClipboard() {
		if (!OpenClipboard(nullptr))
			throw std::runtime_error("Can't open clipboard");
	}

	~RaiiClipboard() { CloseClipboard(); }

	RaiiClipboard(const RaiiClipboard&) = delete;
	RaiiClipboard operator=(const RaiiClipboard&) = delete;
};

class RaiiTextGlobalLock
{
public:
	explicit RaiiTextGlobalLock(HANDLE hData)
		: m_hData(hData)
	{
		m_psz = static_cast<const chosen_char*>(GlobalLock(m_hData));
		if (!m_psz)
			throw std::runtime_error("Can't acquire lock on clipboard text");
	}

	virtual ~RaiiTextGlobalLock() { GlobalUnlock(m_hData); }

	RaiiTextGlobalLock(const RaiiTextGlobalLock&) = delete;
	RaiiTextGlobalLock operator=(const RaiiTextGlobalLock&) = delete;

	const chosen_char* Get() const { return m_psz; }

private:
	HANDLE m_hData;
	const chosen_char* m_psz;
};

std::unique_ptr<chosen_string> getClipboardText()
{
	RaiiClipboard clipboardLock;

	HANDLE hData = GetClipboardData(CHOSEN_FORMAT);
	if (hData == nullptr)
		throw std::runtime_error("Can't get text from clipboard");

	RaiiTextGlobalLock clipboardText(hData);

	return std::unique_ptr<chosen_string>(new chosen_string(clipboardText.Get()));
}

void setClipboardText(const chosen_string* data)
{
	size_t strLength = (data->length()+1) * sizeof(chosen_char);

	HGLOBAL hglbCopy = GlobalAlloc(GMEM_MOVEABLE, strLength);
	if (hglbCopy == nullptr) 
		throw std::runtime_error("Couldn't allocate memory");

	LPTSTR lptstrCopy = static_cast<LPTSTR>(GlobalLock(hglbCopy));
	memcpy(lptstrCopy, data->c_str(), strLength);
	lptstrCopy[data->length()] = '\0';
	GlobalUnlock(hglbCopy);

	RaiiClipboard clipboardLock;

	SetClipboardData(CHOSEN_FORMAT, hglbCopy);
}