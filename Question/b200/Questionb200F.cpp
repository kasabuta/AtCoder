#include "Questionb200F.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb200F {
namespace {
	const char* INPUT_CASE[] = {
	R"()",
	R"()",
	R"()",
	};
	const char* OUTPUT_CASE[] = {
	R"()",
	R"()",
	R"()",
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
/* 入力取得 */
InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	GetInput<int>();
	return input;
}
/* 解答出力 */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "");
}
/* 解法 */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result;
	return result;
}
}
