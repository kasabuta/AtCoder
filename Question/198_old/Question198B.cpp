#include "Question198B.h"
#include <algorithm>

#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Question198B {
namespace {
	const char* INPUT_CASE[] = {
	R"(0)",
	R"(1000000000)",
	R"(123456789)",
	};
	const char* OUTPUT_CASE[] = {
	R"(Yes)",
	R"(Yes)",
	R"(No)",
	};
	static_assert(SIZEOF(OUTPUT_CASE) == SIZEOF(INPUT_CASE), "num of OUTPUT_CASE is invalid.");
}	// end of anonymous namespace.
const char* AtCoderQuestion::GetInputCase(uint8_t index) const {
	if (index < SIZEOF(INPUT_CASE)) {
		return INPUT_CASE[index];
	}
	return "";
}
const char* AtCoderQuestion::GetOutputCase(uint8_t index) const {
	if (index < SIZEOF(OUTPUT_CASE)) {
		return OUTPUT_CASE[index];
	}
	return "";
}

AtCoderQuestion::AtCoderQuestion() : AtCoderQuestionBase<InputStruct, OutputStruct>() {
	m_numTestCase = SIZEOF(INPUT_CASE);
}
InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	char buf[64];
	InputFormat("%s", buf);
	input.numStr = buf;
	return input;
}
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	const char* result = "No";
	if (output.isEnable) {
		result = "Yes";
	}
	OutputFormat(outStr, result);
}
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	auto str = input.numStr;

	//while (*str.rbegin() == '0') str = str.substr(0, str.length() - 1);
	int repeatNum = str.length();
	repeat(i, repeatNum) {
		if (str.substr(str.length() -1 ) == "0") {
			str.erase(str.end() - 1);
		} else {
			break;
		}
	}
	OutputStruct result;
	result.isEnable = true;
	/*
	while(str.size() >= 2) {
		if (str.substr(0, 1) != str.substr(str.length() - 1)) {
			result.isEnable = false;
			break;
		}
		str.erase(str.begin());
		str.erase(str.end() - 1);
	}
	*/
	std::string revStr = str;
	std::reverse(str.begin(), str.end());
	
	if (revStr == str) {
		result.isEnable = true;
	} else {
		result.isEnable = false;
	}
	return result;
}
}
