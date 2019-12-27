// SingleLinePaste.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "getSingleLineString.h"
#include "handleClipboard.h"
#include <string>
#include <memory>

int wmain() {
	setClipboardText(std::move(getSingleLineString(getClipboardText())));
	return 0;
}

#ifndef UNICODE
int main() {
	setClipboardText(std::move(getSingleLineString(getClipboardText())));
	return 0;
}
#endif