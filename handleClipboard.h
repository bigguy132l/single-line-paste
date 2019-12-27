#pragma once

#include <string>

#ifdef UNICODE
using chosen_string = std::wstring;
#else
using chosen_string = std::string;
#endif

chosen_string __stdcall getClipboardText();
void __stdcall setClipboardText(const chosen_string& data);
void __stdcall setClipboardText(std::unique_ptr<chosen_string> data);