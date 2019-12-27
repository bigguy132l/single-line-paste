#pragma once

#include <string>
#include <memory>

using chosen_string = std::wstring;

std::unique_ptr<chosen_string> getClipboardText();
void setClipboardText(const chosen_string* data);