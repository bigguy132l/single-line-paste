// SingleLinePaste.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "getSingleLineString.h"
#include "handleClipboard.h"
#include <string>
#include <memory>

int wmain() {
	wstrptr newText(singleLineCopy());
	setClipboardText(newText.get());
	return 0;
}