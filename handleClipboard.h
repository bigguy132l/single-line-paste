#pragma once

#include <string>

using chosen_string = std::wstring;

chosen_string __stdcall getClipboardText();
void __stdcall setClipboardText(const chosen_string& data);