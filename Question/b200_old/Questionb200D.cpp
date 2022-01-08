#include "Questionb200D.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb200D {
namespace {
	const char* INPUT_CASE[] = {
	R"(5
180 186 189 191 218
)",
	R"(2
123 523
)",
	R"(6
2013 1012 2765 2021 508 6971
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(Yes
1 1
2 3 4
)",
	R"(Yes
1 1
1 2
)",
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
AtCoderQuestion::AtCoderQuestion() : AtCoderQuestionBase<InputStruct, OutputStruct>(SIZEOF(INPUT_CASE)) {
}
InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	InputFormat("%d", &input);
	char buf[4096];
	InputFormat("%[^\n]", buf);
	auto arr = split(buf, " ");
	for (auto num : arr) {
		input.array.push_back(std::atoll(num.c_str()));
	}
	return input;
}
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	//if (output.judge) {
	//	OutputFormat(outStr, "Yes");
	//	std::string format("%d");
	//	repeat(i, output.array1.size()) {
	//		format.append(" %d");
	//	}
	//	OutputFormat(outStr, format, );
	//} else {
	//	OutputFormat(outStr, "No")
	//}
}
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	
	
	
	
	OutputStruct result;
	return result;
}
}
