#include "stdafx.h"
#include "getSingleLineString.h"
#include <string>
#include <sstream>
#include <memory>

#ifdef _MSVC_LANG // so I'm not bound to compilers that support __forceinline
#define forceinline __forceinline
#else
#define forceinline inline
#endif

// Using a template so I don't have to retype the entire thing (will use template in function definitions)
template <typename StrType>
forceinline std::unique_ptr<StrType> getSingleLineStringTemplate(const StrType& input) {
	using char_t = typename StrType::value_type;

	std::basic_stringstream<char_t> stream;

	size_t streamSize = 0;
	for (size_t& i = streamSize; i < input.length(); i++) { // reference to streamSize is more intuitive in the loop
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
	stream.get(outputData, streamSize+10, '\0');

	return std::make_unique<StrType>(StrType(outputData));
}

// takes a wstring as input, and returns it with any newline characters replaced with spaces
std::unique_ptr<std::wstring> getSingleLineString(const std::wstring& input) {
	return getSingleLineStringTemplate<std::wstring>(input);
}

std::unique_ptr<std::string> getSingleLineString(const std::string& input) {
	return getSingleLineStringTemplate<std::string>(input);
}