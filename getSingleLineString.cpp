#include "stdafx.h"
#include "getSingleLineString.h"
#include "handleClipboard.h"
#include <string>
#include <sstream>
#include <memory>

// takes a wstring as input, and returns it with any newline characters replaced with spaces
wstrptr getSingleLineString(wstrptr input) {
	std::wstringstream stream;

	size_t streamSize = 0;
	for (size_t& i = streamSize; i < input->length(); i++) { // reference to streamSize is more intuitive in the loop
		auto character = input->at(i);
		switch (character) {
		case '\n':
			stream << ' ';
			break;
		case '\r':
			if (input->at(i + 1) != '\n')
				stream << ' ';
			break;
		default:
			stream << character;
		}
	}

	wchar_t* outputData = new wchar_t[streamSize];
	stream.get(outputData, streamSize + 10, '\0');

	return wstrptr(new std::wstring(outputData));
}

wstrptr singleLineCopy()
{
	return getSingleLineString(getClipboardText());
}