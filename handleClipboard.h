#pragma once

#include <string>
#include <memory>

#ifdef UNICODE
using chosen_string = std::wstring;
#else
using chosen_string = std::string;
#endif

std::unique_ptr<chosen_string> getClipboardText();
void setClipboardText(const chosen_string* data);