#include "Questionb203A.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb203A {
namespace {
	const char* INPUT_CASE[] = {
	R"(2 5 2)",
	R"(4 5 6)",
	R"(1 1 1)",
	};
	const char* OUTPUT_CASE[] = {
	R"(5)",
	R"(0)",
	R"(1)",
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
	GetInputFormat("%d %d %d", &input.a, &input.b, &input.c);
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%d", output.result);
}
/* ‰ð–@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result;
	if (input.a == input.b) {
		result.result = input.c;
	} else if (input.a == input.c) {
		result.result = input.b;
	} else if (input.b == input.c) {
		result.result = input.a;
	} else {
		result.result = 0;
	}
	return result;
}
}
