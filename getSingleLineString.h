#pragma once

#include <string>
#include <memory>

// takes a std::string or std::wstring and return the same string, with newlines replaced by spaces
std::unique_ptr<std::wstring> getSingleLineString(const std::wstring&);
std::unique_ptr<std::string> getSingleLineString(const std::string&);