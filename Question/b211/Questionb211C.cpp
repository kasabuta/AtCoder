#include "Questionb211C.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb211C {
namespace {
	const char* INPUT_CASE[] = {
	R"(chchokudai)",
	R"(atcoderrr)",
	R"(chokudaichokudaichokudai)",
	};
	const char* OUTPUT_CASE[] = {
	R"(3)",
	R"(0)",
	R"(45)",
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
	char buf[100000];
	GetInputFormat("%s", &buf);
	input.text = buf;
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%lld", output.num);
}
/* ‰ð–@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	constexpr int length = 8;
	const char* name = "chokudai";
	long long chrCount[length] = { 0, 0, 0, 0, 0, 0, 0, 0 };
	for (int i = input.text.size() - 1; i >= 0; i--) {
		repeat(j, length) {
			if (input.text[i] == name[j]) {
				if (j == length - 1) {
					chrCount[j]++;
				} else {
					chrCount[j] += chrCount[j + 1];
					chrCount[j] = chrCount[j] % 1000000007;
				}
				break;
			}
		}
	}

	OutputStruct result;
	result.num = chrCount[0];
	return result;
}
}
