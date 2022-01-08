#include "Questionb211B.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
namespace Questionb211B {
namespace {
	const char* INPUT_CASE[] = {
	R"(3B
HR
2B
H
)",
	R"(2B
3B
HR
3B
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(Yes)",
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
const int AtCoderQuestion::GetNumTestCase() const {
	return SIZEOF(INPUT_CASE);
}
/* “ü—ÍŽæ“¾ */
InputStruct AtCoderQuestion::Input() {
	InputStruct input;
	char buf[128];
	GetInputFormat("%s", &buf);
	input.hit.push_back(buf);
	GetInputFormat("%s", &buf);
	input.hit.push_back(buf);
	GetInputFormat("%s", &buf);
	input.hit.push_back(buf);
	GetInputFormat("%s", &buf);
	input.hit.push_back(buf);

	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	auto outText = output.judge ? "Yes" : "No";
	OutputFormat(outStr, "%s", outText);
}
/* ‰ð–@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	int bitFlag = 0;
	const char* hits[] = {
		"H",
		"2B",
		"3B",
		"HR"
	};
	OutputStruct result;
	result.judge = true;
	bool dupliFlag = false;
	for (auto hit : input.hit) {
		repeat(i, 4) {
			if (std::strcmp(hit.c_str(), hits[i]) == 0) {
				if (bitFlag & 1 << i) {
					result.judge = false;
					dupliFlag = true;
					break;
				} else {
					bitFlag |= 1 << i;
				}
				break;
			}
		}
		if (dupliFlag) {
			break;
		}
	}
	return result;
}
}
