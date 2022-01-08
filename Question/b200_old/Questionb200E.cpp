#include "Questionb200E.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb200E {
namespace {
	const char* INPUT_CASE[] = {
	R"(2 5)",
	R"(1000000 1000000000000000000)",
	R"(9 47)",
	};
	const char* OUTPUT_CASE[] = {
	R"(1 2 2)",
	R"(1000000 1000000 1000000)",
	R"(3 1 4)",
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
	InputFormat("%d %d", &input);
	return input;
}
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "");
}
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result;
	return result;
}
}
