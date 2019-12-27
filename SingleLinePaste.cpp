// SingleLinePaste.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "getSingleLineString.h"
#include "handleClipboard.h"
#include <string>
#include <memory>

int wmain() {
	using strptr = std::unique_ptr<std::wstring>;
	strptr oldText(getClipboardText());
	strptr newText(getSingleLineString(oldText.get()));
	setClipboardText(newText.get());
	return 0;
}

#ifndef UNICODE
int main() {
	std::unique_ptr<std::string> newText(getSingleLineString(getClipboardText()));
	setClipboardText(newText.get());
	return 0;
}
#endif