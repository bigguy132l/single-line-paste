// SingleLinePaste.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "getSingleLineString.h"
#include "handleClipboard.h"
#include <string>

int wmain() {
	std::wstring clipboardData = getSingleLineString(getClipboardText());
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