#include "Questionb203C.h"
#include "../../Utility/AtCoderInOut.h"
#include "../../Utility/Utility.h"
#include <algorithm>
namespace Questionb203C {
namespace {
	const char* INPUT_CASE[] = {
	R"(2 3
2 1
5 10
)",
	R"(5 1000000000
1 1000000000
2 1000000000
3 1000000000
4 1000000000
5 1000000000
)",
	R"(3 2
5 5
2 1
2 2
)",
	};
	const char* OUTPUT_CASE[] = {
	R"(4)",
	R"(6000000000)",
	R"(10)",
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
	GetInputFormat("%lld %lld", &input.numFriends, &input.money);
	repeat(i, input.numFriends) {
		InputStruct::Friend frie;
		GetInputFormat("%lld %lld", &frie.village, &frie.money);
		input.friends.push_back(frie);
	}
	return input;
}
/* ‰ð“šo—Í */
void AtCoderQuestion::Output(const OutputStruct& output, std::string* outStr) {
	OutputFormat(outStr, "%lld", output.village);
}
/* ‰ð–@ */
OutputStruct AtCoderQuestion::Solver(const InputStruct& input) {
	OutputStruct result;
	auto sortedFriends = input.friends;
	std::sort(sortedFriends.begin(), sortedFriends.end());
	result.village = input.money;
	for (auto frie : sortedFriends) {
		if (frie.village <= result.village) {
			result.village += frie.money;
		} else {
			break;
		}
	}
	return result;
}
}
