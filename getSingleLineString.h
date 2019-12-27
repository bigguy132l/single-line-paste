#pragma once

#include <string>
#include <memory>

using wstrptr = std::unique_ptr<std::wstring>;

// takes a std::wstring and return the same string, with newlines replaced by spaces
wstrptr getSingleLineString(wstrptr input);

// returns a single-line string based on the current contents of the clipboard
wstrptr singleLineCopy();