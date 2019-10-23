// PasteWithoutLines.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "getSingleLineString.h"
#include "handleClipboard.h"
#include <string>

int wmain() {
	std::wstring clipboardData = getSingleLineString(getClipboardText());
	//std::wstring newClipboardData = getSingleLineString(clipboardData);
	setClipboardText(clipboardData);
	return 0;
}

#ifndef UNICODE
int main() {
	std::string clipboardData = getClipboardText();
	std::string newClipboardData = getSingleLineString(clipboardData);
	setClipboardText(newClipboardData);
	return 0;
}
#endif