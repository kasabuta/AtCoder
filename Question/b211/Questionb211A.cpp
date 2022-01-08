#include "Questionb211A.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb211A {
namespace {
	const char* INPUT_CASE[] = {
	R"(130 100)",
	R"(300 50)",
	R"(123 123)",
	};
	const char* OUTPUT_CASE[] = {
	R"(110)",
	R"(133.3333333)",
	R"(123)",
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
const int AtCoderQuestion::GetNumTestCase() const {
	return SIZEOF(INPUT_CASE);
}
/* “ü—ÍŽæ“¾ */
InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	GetInputFormat("%d %d", &input.max, &input.min);
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%f", output.average);
}
/* ‰ð–@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result;
	result.average = input.min + ((float)(input.max - input.min) / 3.f);
	return result;
}
}
