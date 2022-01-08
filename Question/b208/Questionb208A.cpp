#include "Questionb208A.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb208A {
namespace {
	const char* INPUT_CASE[] = {
	R"(2 11)",
	R"(2 13)",
	R"(100 600)",
	};
	const char* OUTPUT_CASE[] = {
	R"(Yes)",
	R"(No)",
	R"(Yes)",
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
	GetInputFormat("%d %d", &input.times, &input.targetSum);
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	if (output.isSame) {
		OutputFormat(outStr, "Yes");
	} else {
		OutputFormat(outStr, "No");
	}
}
/* ‰ð–@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result;
	result.isSame = true;
	if (input.times > input.targetSum) {
		result.isSame = false;
	} else if (input.times * 6 < input.targetSum) {
		result.isSame = false;
	}
	return result;
}
}
