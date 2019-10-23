#include "stdafx.h"
#include "getSingleLineString.h"
#include <string>
#include <sstream>

// Using a template so I don't have to retype the entire thing (will use template in function definitions)
template <typename StrType>
__forceinline StrType getSingleLineStringTemplate(const StrType& input) {
	using char_t = typename StrType::value_type;
	using StreamType = std::basic_stringstream<char_t>;

	StreamType stream;

	size_t streamSize = 0;
	for (size_t i = 0; i < input.length(); streamSize = i++) {
		auto character = input[i];
		switch (character) {
			case '\n':
				stream << ' ';
				break;
			case '\r':
				if (input[i + 1] != '\n')
					stream << ' ';
				break;
			default:
				stream << character;
		}
	}
	
	char_t* outputData = new char_t[streamSize];
	stream.get(outputData, streamSize+100, (char_t)0);

	StrType output(outputData);
	return output;
}

// takes a wstring as input, and returns it with any newline characters replaced with spaces
std::wstring getSingleLineString(const std::wstring& input) {
	return getSingleLineStringTemplate<std::wstring>(input);
}

std::string getSingleLineString(const std::string& input) {
	return getSingleLineStringTemplate<std::string>(input);
}