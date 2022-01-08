#include "Questionb200A.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb200A {
namespace {
	const char* INPUT_CASE[] = {
	R"(221)",
	R"(200)",
	R"(2001)",
	R"(2000)",
	};
	const char* OUTPUT_CASE[] = {
	R"(3)",
	R"(2)",
	R"(21)",
	R"(20)",
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
	InputFormat("%d", &input.year);
	return input;
}
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%d", output.century);
}
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result;
	result.century = 0;
	auto year = input.year;
	while (year > 0) {
		year -= 100;
		result.century++;
	}

	return result;
}
}
