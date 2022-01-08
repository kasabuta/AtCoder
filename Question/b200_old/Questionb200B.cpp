#include "Questionb200B.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb200B {
namespace {
	const char* INPUT_CASE[] = {
	R"(2021 4)",
	R"(40000 2)",
	R"(8691 20)",
	};
	const char* OUTPUT_CASE[] = {
	R"(50531)",
	R"(1)",
	R"(84875488281)",
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
	InputFormat("%d %d", &input.number, &input.count);
	return input;
}
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%lld", output.number);
}
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result; 
	result.number = input.number;
	repeat(i, input.count) {
		if (result.number % 200 == 0) {
			result.number = result.number / 200;
		} else {
			result.number = result.number * 1000 + 200;
		}
	}
	
	return result;
}
}
