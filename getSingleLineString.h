#pragma once

#include <string>

// takes a std::string or std::wstring and return the same string, with newlines replaced by spaces
std::wstring getSingleLineString(const std::wstring&);
std::string getSingleLineString(const std::string&);