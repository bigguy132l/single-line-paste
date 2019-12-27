#pragma once

#include <string>

#ifdef UNICODE
using chosen_string = std::wstring;
#else
using chosen_string = std::string;
#endif

chosen_string getClipboardText();
void setClipboardText(std::unique_ptr<chosen_string> data);