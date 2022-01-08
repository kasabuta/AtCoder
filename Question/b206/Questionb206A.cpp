#include "Questionb206A.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb206A {
namespace {
	const char* INPUT_CASE[] = {
	R"(180)",
	R"(200)",
	R"(191)",
	};
	const char* OUTPUT_CASE[] = {
	R"(Yay!)",
	R"(:()",
	R"(so-so)",
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
	GetInputFormat("%d", &input.price);
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	switch (output.compare) {
	case CHEEP:
		OutputFormat(outStr, "Yay!");
		break;
	case EQUAL:
		OutputFormat(outStr, "so-so");
		break;
	case EXPENSIVE:
		OutputFormat(outStr, ":(");
		break;
	}
}
/* ‰ð–@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	const auto price = RoundDown(1.08f * input.price);
	OutputStruct result;
	if (price < 206) {
		result.compare = CHEEP;
	} else if (price > 206) {
		result.compare = EXPENSIVE;
	} else {
		result.compare = EQUAL;
	}
	return result;
}
}
